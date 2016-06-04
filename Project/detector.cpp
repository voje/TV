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
	int key_wait;
	string input_file;
	string output_file;
	string cascade_file;
	int window_margin;
	int morph_size;
};

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

void detect_skin(Mat &foreground, Point skin_point, Mat &bin, ColorExtractor cex){
	//Mat hsv;
	//cvtColor(foreground, hsv, CV_BGR2HSV);
	//inRange(hsv, Scalar(0, 10, 60), Scalar(20, 150, 255), bin);
	for(int i=0; i<bin.rows; i++){
		for(int j=0; j<bin.cols; j++){
			Vec3b BGR = foreground.at<Vec3b>(Point(j, i));
			Point p = cex.BGR_to_bg(BGR);
			int s = 30;
			if(p.x <= skin_point.x+s && p.x >= skin_point.x-s && p.y <= skin_point.y+s && p.y >= skin_point.y-s){
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
	input_param inp;
	read_parameters(inp);

	//Set some parameters.
	param.detect_face = true;
	param.scaleFactor = 1.1;
	param.minNeigh = 3;
	param.flags = 0;
	param.minSize = Size(80, 80);
	param.maxSize = Size(200, 200);

	Mat frame, g_frame, mask_MOG2, foreground;
	Mat morph_element = getStructuringElement( MORPH_ELLIPSE, Size(inp.morph_size, inp.morph_size), Point(floor(inp.morph_size/2)+1, floor(inp.morph_size/2)+1) );

	VideoCapture cap;
	VideoWriter output_cap;
	CascadeClassifier detector;
	vector<Rect> found_faces;
	ColorExtractor cex;

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
		output_cap.open(inp.output_file ,CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);

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
	Ptr<BackgroundSubtractor> pMOG2;
	pMOG2 = createBackgroundSubtractorMOG2();

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

		resize(frame, frame, Size(0,0), 0.5, 0.5);

		//preform necessary rotations
		flip(frame, frame, 0); //1 flips around x axis

		//extract foreground
		extract_foreground(frame, foreground, pMOG2);

		//detect skin
		Point skin_point(-1, -1);
		Mat skin_binary = Mat::zeros(frame.size(), CV_8U);
		GaussianBlur(skin_binary, skin_binary, Size(5, 5), 2);
		erode(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);
		dilate(skin_binary, skin_binary, morph_element);

		//detect_skin(foreground, skin_binary);
		//detect_skin(foreground, skin_point, skin_binary, cex);
		detect_skin(frame, skin_point, skin_binary, cex);

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
				Mat small_face_region = frame(Range(tl.y+yresizer, br.y-yresizer), Range(tl.x+xresizer, br.x-xresizer));		
				imshow("small_face_region", small_face_region);
				skin_point = cex.update_bg(small_face_region);
				cout << skin_point << endl;
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
