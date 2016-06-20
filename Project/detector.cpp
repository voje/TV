#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unistd.h>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "color_extractor.h"
#include "hand_tracker.h"
#include "gesture_tracker.h"

using namespace std;
using namespace cv;

//parameters for detectMultiscale
struct detectMultiscale_param{
	bool detect_face;
	double scaleFactor;
	int minNeigh; //3 in documentation
	int flags;	//should be 0
	Size minSize;
	Size maxSize;
} dm_param;

struct input_param{
	int key_wait;		//framerate if reading from 0; set it to 30
	string input_file;	//if it's 0, we're reading from webcam
	string output_file;	//if it's 0, we're not writing
	string cascade_file;	//for face detection
	int window_margin;	//outdated - used to create outer window (narrow the search)
	int morph_size;		//morphological object size
	int color_margin;	//how far around skin point do we search in bg space
	int window_size_cols;	//resize frame after captzre (speed up the process)
	int gest_delay;
	int head_dy_min;
	int extract_foreground;
} static in_param;

void detect_skin(Mat &frame, Point &skin_point, Mat &bin, ColorExtractor cex){
	for(int i=0; i<bin.rows; i++){
		for(int j=0; j<bin.cols; j++){
			Vec3b BGR = frame.at<Vec3b>(Point(j, i));
			Point p = cex.BGR_to_bg(BGR);
			if(	p.x <= skin_point.x + in_param.color_margin && 
				p.x >= skin_point.x - in_param.color_margin &&
				p.y <= skin_point.y + in_param.color_margin &&
				p.y >= skin_point.y - in_param.color_margin	){
				bin.at<unsigned char>(Point(j, i)) = 255;
			}
		}
	}
}

void read_input_param(){
	ifstream ifs;	
	ifs.open("../detector.conf");
	string skip, value;
	ifs >> skip >> value; in_param.key_wait = atoi(value.c_str());
	ifs >> skip >> value; in_param.input_file = value;
	ifs >> skip >> value; in_param.output_file = value;
	ifs >> skip >> value; in_param.cascade_file = value;
	ifs >> skip >> value; in_param.window_margin = atoi(value.c_str());
	ifs >> skip >> value; in_param.morph_size = atoi(value.c_str());
	ifs >> skip >> value; in_param.color_margin = atoi(value.c_str());
	ifs >> skip >> value; in_param.window_size_cols = atoi(value.c_str());
	ifs >> skip >> value; in_param.gest_delay = atoi(value.c_str());
	ifs >> skip >> value; in_param.head_dy_min = atoi(value.c_str());
	ifs >> skip >> value; in_param.extract_foreground= atoi(value.c_str());
}

void extract_foreground(Mat original, Mat &foreground, Ptr<BackgroundSubtractor> bs){
	Mat foreground_mask;	
	bs->apply(original, foreground_mask);
	//split the channels, apply mask, merge channels
	vector<Mat> channels(3);
	split(original, channels);
	for(int i=0; i<channels.size(); i++){
		bitwise_and(channels[i], foreground_mask, channels[i]);
	}
	merge(channels, foreground);
}

int main(int argc, char** argv){
	//read input parameters
	read_input_param();

	//Set facedetector parameters.
	dm_param.detect_face = true;
	dm_param.scaleFactor = 1.1;
	dm_param.minNeigh = 3;
	dm_param.flags = 0;
	dm_param.minSize = Size(10, 10);	//if you resize window, you need to reset these
	dm_param.maxSize = Size(80, 80);

	Mat frame, g_frame, skin_binary;
	Mat mask_MOG2, foreground;
	Mat morph_element = getStructuringElement( MORPH_ELLIPSE, Size(in_param.morph_size, in_param.morph_size), Point(floor(in_param.morph_size/2)+1, floor(in_param.morph_size/2)+1) );

	//declarations
	VideoCapture cap;
	VideoWriter output_cap;
	CascadeClassifier detector;
	vector<Rect> found_faces;
	ColorExtractor cex(in_param.color_margin);
	Point skin_point(-1, -1);
	Rect face_rect(-1, -1, 0, 0); //x, y, width, height
	HandTracker lh_tr("left");
	HandTracker rh_tr("right");
	GestureTracker gest(in_param.gest_delay, in_param.head_dy_min);

	//get input video
	if(in_param.input_file != "0"){
		cap.open(in_param.input_file);
	}else{
		cap.open(0);
		if(!cap.isOpened()){
			cout << "Could not find input device." << endl;
			return 1;
		}
	}

	//optional write to file
	if(in_param.output_file != "0"){
		int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	   	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
		output_cap.open(in_param.output_file, CV_FOURCC('M','J','P','G'), in_param.key_wait, Size(frame_width, frame_height), true);

		if(!output_cap.isOpened()){
	        std::cout << "!!! Output video could not be opened" << std::endl;
	        return 1;
		}
	}

	//load cascade
	bool loaded = detector.load(in_param.cascade_file);
	if(!loaded){
		cout << "Cascade not loaded." << endl;
		return 1;
	}

	//init background subtractor
	Ptr<BackgroundSubtractor> pMOG2;
	pMOG2 = createBackgroundSubtractorMOG2();

	//init window
	namedWindow("binary_image", WINDOW_NORMAL);
	namedWindow("cap", WINDOW_NORMAL);
	cout << "Press 'q' to quit, 'p' to capture frame." << endl;

	//wait 5 seconds
	cout << "Position yourself." << endl;
	usleep(5000000);
	cout << "Starting capture.";

	for(;;){
		cap >> frame;
		//this step is necessary if reading from file
		if(frame.empty()){
			break;
		}

		//write
		if(in_param.output_file != "0"){
			output_cap.write(frame);	
		}

		//resize window (faster processing)
		double frame_scale;
		if(frame.cols <= in_param.window_size_cols){
			frame_scale = 1;
		}else{
			frame_scale = ((double)in_param.window_size_cols)/((double)frame.cols);
		}
		Size win_size((int)(frame.cols*frame_scale), (int)(frame.rows*frame_scale));
		resize(frame, frame, win_size);

		//perform rotation if necessary
		flip(frame, frame, 0); //1 flips around x axis

		//if enabled, start extracting foreground after the color is extracted from face
		if(in_param.extract_foreground && cex.is_full()){
			extract_foreground(frame, frame, pMOG2);
		}

		//initiate binary matrix with zeros
		skin_binary = Mat::zeros(frame.size(), CV_8U);

		//face
		cvtColor(frame, g_frame, CV_BGR2GRAY);
		if(dm_param.detect_face){
			detector.detectMultiScale(g_frame, found_faces, dm_param.scaleFactor, dm_param.minNeigh, dm_param.flags, dm_param.minSize, dm_param.maxSize);
			//display 1 found face
			if(found_faces.size() > 0){
				face_rect = found_faces[0];
				Point br = face_rect.br();
				Point tl = face_rect.tl();
				int yresizer = floor((br.y-tl.y)/5);
				int xresizer = floor((br.x-tl.x)/5);
				Mat small_face_region = frame(Range(tl.y+yresizer, br.y-yresizer), Range(tl.x+xresizer, br.x-xresizer));		
				//imshow("small_face_region", small_face_region);
				skin_point = cex.update_bg(small_face_region);
			}
		}

		//detect skin
		detect_skin(frame, skin_point, skin_binary, cex);	//optionally use foreground instead of frame
		//GaussianBlur(skin_binary, skin_binary, Size(5, 5), 2);
		erode(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		//dilate(skin_binary, skin_binary, morph_element);

		//find hands
		lh_tr.find_hand(skin_binary, face_rect);
		rh_tr.find_hand(skin_binary, face_rect);

		//create a binary image with 3 channels
		Mat skin_binary3;
		cvtColor(skin_binary, skin_binary3, CV_GRAY2BGR);

		//draw found objects
		rectangle(skin_binary3, face_rect.br(), face_rect.tl(), Scalar(0, 255, 0), 2, 8, 0);	
		//rectangle(frame, face_rect.br(), face_rect.tl(), Scalar(0, 255, 0), 2, 8, 0);	
		circle(skin_binary3, lh_tr.get_point(), 10, Scalar(255, 0, 0), 2);
		circle(skin_binary3, rh_tr.get_point(), 10, Scalar(0, 0, 255), 2);

		//gesture tracking
		gest.update(face_rect, lh_tr.get_point(), rh_tr.get_point(), frame);
		gest.take_action();	//simulate pressing keys

		//show detections
		imshow("cap", frame);		
        //imshow("foreground", foreground);
        gest.draw_grid(skin_binary3, face_rect);
		imshow("binary_image", skin_binary3);
		cex.display_bg();
		
		char c = waitKey(in_param.key_wait);
		if(c == 'q'){
			break;
		}
		else if(c == 'p'){
			imwrite("../sample_pictures/capture0.jpg", skin_binary);
		}
	}	

	cap.release();
	return 0;
}
