#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "color_extractor.h"

using namespace std;
using namespace cv;

//parameters for detectMultiscale
struct my_param{
	bool detect_face;
	double scaleFactor;
	int minNeigh; //3 in documentation
	int flags;	//should be 0
	Size minSize;
	Size maxSize;
} param;

struct input_param{
	int key_wait;		//framerate if reading from 0; set it to 30
	string input_file;	//if it's 0, we're reading from webcam
	string output_file;	//if it's 0, we're not writing
	string cascade_file;	//for face detection
	int window_margin;	//outdated - used to create outer window (narrow the search)
	int morph_size;		//morphological object size
	int color_margin;	//how far around skin point do we search in bg space
	int window_size_cols;	//resize frame after captzre (speed up the process)
} static inp;

/* 
bool is_skin(Vec3d &bgr){
	//equations from a scientific paper - not working
	Vec3d zero_div(1.0e-9, 1.0e-9, 1.0e-9);
	//bgr += zero_div;
	double sum = bgr[0] + bgr[1] + bgr[2];
	bgr /= sum;
	if( abs(atan(bgr[0]/bgr[2])-M_PI/4) < M_PI/8 &&
		abs(atan(bgr[1]/bgr[2])-M_PI/6) < M_PI/18 &&
		abs(atan(bgr[0]/bgr[1])-M_PI/5) < M_PI/15 ){
		return true;	
	}
	return false;
}
*/

void detect_skin(Mat &frame, Point &skin_point, Mat &bin, ColorExtractor cex){
	for(int i=0; i<bin.rows; i++){
		for(int j=0; j<bin.cols; j++){
			Vec3b BGR = frame.at<Vec3b>(Point(j, i));
			Point p = cex.BGR_to_bg(BGR);
			if(	p.x <= skin_point.x + inp.color_margin && 
				p.x >= skin_point.x - inp.color_margin &&
				p.y <= skin_point.y + inp.color_margin &&
				p.y >= skin_point.y - inp.color_margin	){
				bin.at<unsigned char>(Point(j, i)) = 255;
			}
		}
	}
}

void read_parameters(input_param &p){
	ifstream ifs;	
	ifs.open("detector.conf");
	string skip, value;
	ifs >> skip >> value; p.key_wait = atoi(value.c_str());
	ifs >> skip >> value; p.input_file = value;
	ifs >> skip >> value; p.output_file = value;
	ifs >> skip >> value; p.cascade_file = value;
	ifs >> skip >> value; p.window_margin = atoi(value.c_str());
	ifs >> skip >> value; p.morph_size = atoi(value.c_str());
	ifs >> skip >> value; p.color_margin = atoi(value.c_str());
	ifs >> skip >> value; p.window_size_cols = atoi(value.c_str());
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
	//read parameters
	read_parameters(inp);

	//Set some parameters.
	param.detect_face = true;
	param.scaleFactor = 1.1;
	param.minNeigh = 3;
	param.flags = 0;
	param.minSize = Size(20, 20);	//if you resize window, you need to reset these
	param.maxSize = Size(100, 100);

	Mat frame, g_frame;
	//Mat mask_MOG2, foreground;
	Mat morph_element = getStructuringElement( MORPH_ELLIPSE, Size(inp.morph_size, inp.morph_size), Point(floor(inp.morph_size/2)+1, floor(inp.morph_size/2)+1) );

	VideoCapture cap;
	VideoWriter output_cap;
	CascadeClassifier detector;
	vector<Rect> found_faces;
	ColorExtractor cex(inp.color_margin);
	Point skin_point(-1, -1);

	//get input video
	if(inp.input_file != "0"){
		cap.open(inp.input_file);
	}else{
		cap.open(0);
		if(!cap.isOpened()){
			cout << "Could not find input device." << endl;
			return 1;
		}
	}

	//optional write to file
	if(inp.output_file != "0"){
		int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	   	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
		output_cap.open(inp.output_file, CV_FOURCC('M','J','P','G'), inp.key_wait, Size(frame_width, frame_height), true);

		if(!output_cap.isOpened()){
	        std::cout << "!!! Output video could not be opened" << std::endl;
	        return 1;
		}
	}

	//load cascade
	bool loaded = detector.load(inp.cascade_file);
	if(!loaded){
		cout << "Cascade not loaded." << endl;
		return 1;
	}

	//init background subtractor
	/*
	Ptr<BackgroundSubtractor> pMOG2;
	pMOG2 = createBackgroundSubtractorMOG2();
	*/

	//init window
	cout << "Press 'q' to quit." << endl;

	for(;;){
		cap >> frame;
		//this step is necessary if reading from file
		if(frame.empty()){
			break;
		}

		//write
		if(inp.output_file != "0"){
			output_cap.write(frame);	
		}

		//resize by half
		double frame_scale;
		if(frame.cols <= inp.window_size_cols){
			frame_scale = 1;
		}else{
			frame_scale = ((double)inp.window_size_cols)/((double)frame.cols);
		}
		Size win_size((int)(frame.cols*frame_scale), (int)(frame.rows*frame_scale));
		resize(frame, frame, win_size);

		//preform necessary rotations
		flip(frame, frame, 0); //1 flips around x axis

		/*
		//extract foreground
		extract_foreground(frame, foreground, pMOG2);
		*/

		//detect skin
		Mat skin_binary = Mat::zeros(frame.size(), CV_8U);
		detect_skin(frame, skin_point, skin_binary, cex);

		//GaussianBlur(skin_binary, skin_binary, Size(5, 5), 2);
		erode(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		//dilate(skin_binary, skin_binary, morph_element);

		//face
		cvtColor(frame, g_frame, CV_BGR2GRAY);
		if(param.detect_face){
			detector.detectMultiScale(g_frame, found_faces, param.scaleFactor, param.minNeigh, param.flags, param.minSize, param.maxSize);
			//display 1 found face
			if(found_faces.size() > 0){
				Point br = found_faces[0].br();
				Point tl = found_faces[0].tl();
				int yresizer = floor((br.y-tl.y)/5);
				int xresizer = floor((br.x-tl.x)/5);
				rectangle(frame, br, tl, Scalar(0, 255, 0), 2, 8, 0);	
				rectangle(skin_binary, br, tl, Scalar(0, 255, 0), 2, 8, 0);	
				Mat small_face_region = frame(Range(tl.y+yresizer, br.y-yresizer), Range(tl.x+xresizer, br.x-xresizer));		
				//imshow("small_face_region", small_face_region);
				skin_point = cex.update_bg(small_face_region);
			}
		}

		//imshow("detect_faces", frame);		
        //imshow("foreground", foreground);
		imshow("skin", skin_binary);
		cex.display_bg();
		
		char c = waitKey(inp.key_wait);
		if(c == 'q') break;
	}	

	cap.release();
	return 0;
}
