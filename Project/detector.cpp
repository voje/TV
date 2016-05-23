#include <iostream>
#include <fstream>
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

#define FROM_FILE 1

using namespace std;
using namespace cv;

//parameters for detectMultiscale
struct my_param{
	double scaleFactor;
	int minNeigh; //3 in documentation
	int flags;	//should be 0
	Size minSize;
	Size maxSize;
} param;

struct input_param{
	int key_wait;
	string input_file;
	string cascade_file;
	int window_margin;
};

void read_parameters(input_param &p){
	ifstream ifs;	
	ifs.open("detector.conf");
	string skip, value;
	ifs >> skip >> value; p.key_wait = atoi(value.c_str());
	ifs >> skip >> value; p.input_file = value;
	ifs >> skip >> value; p.cascade_file = value;
	ifs >> skip >> value; p.window_margin = atoi(value.c_str());
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
	param.scaleFactor = 1.1;
	param.minNeigh = 3;
	param.flags = 0;
	param.minSize = Size(80, 80);
	param.maxSize = Size(200, 200);

	Mat frame, g_frame, mask_MOG2, foreground;

	VideoCapture cap;
	CascadeClassifier detector;
	vector<Rect> found_faces;

	//get input video
	if(FROM_FILE){
		cap.open(inp.input_file);
	}else{
		cap.open(0);
		if(!cap.isOpened()){
			cout << "Could not find input device." << endl;
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
	namedWindow("detect_faces", 1);
	cout << "Press 'q' to quit." << endl;

	for(;;){
		cap >> frame;
		//this step is necessary if reading from file
		if(frame.empty()){
			break;
		}

		//preform necessary rotations
		//flip(frame, frame, 0); //1 flips around x axis

		extract_foreground(frame, foreground, pMOG2);

		cvtColor(frame, g_frame, CV_BGR2GRAY);

		detector.detectMultiScale(g_frame, found_faces, param.scaleFactor, param.minNeigh, param.flags, param.minSize, param.maxSize);
		//display 1 found face
		if(found_faces.size() > 0){
			rectangle(frame, found_faces[0].br(), found_faces[0].tl(), Scalar(0, 255, 0), 2, 8, 0);	
		}

		imshow("detect_faces", frame);		
		imshow("foreground", foreground);
		
		char c = waitKey(inp.key_wait);
		if(c == 'q') break;
	}	

	cap.release();
	return 0;
}
