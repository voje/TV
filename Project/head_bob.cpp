#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"

#define WINDOW_NAME "head_bob"

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

int main(int argc, char** argv){

	//Set some parameters.
	param.scaleFactor = 1.1;
	param.minNeigh = 3;
	param.flags = 0;
	param.minSize = Size(80, 80);
	param.maxSize = Size(200, 200);
	string cascade_file = "haarcascade_frontalface_default.xml"; //you will need this file inside /build

	Mat frame, g_frame, mask_MOG2;
	char c;
	int new_y, dy;
	int old_y = -1;
	int still_count = 1000; //start with a high value
	int still_count_threshold = 5; //if not running for n frames, detect stillness
	int dy_threshold = 10;	//dy needs to change at least 10 px to detect running behavior in user
	bool running = false;

	//one of these might be causing the memory leak
	VideoCapture cap;
	CascadeClassifier detector;
	vector<Rect> found;

	//from file
	string const filename = "../sample_videos/running1.webm";
	cap.open(filename);

	//capture video
	/*cap.open(0);
	if(!cap.isOpened()){
		cout << "Could not find input device." << endl;
		return 1;
	}*/

	bool loaded = detector.load(cascade_file);
	if(!loaded){
		cout << "Cascade not loaded." << endl;
		return 1;
	}

	Ptr<BackgroundSubtractor> pMOG2;
	pMOG2 = createBackgroundSubtractorMOG2();

	namedWindow(WINDOW_NAME, 1);
	cout << "Press 'q' to quit." << endl;

	for(;;){
		cap >> frame;

		//flip(frame, frame, 0); //1 flips around x axis

		pMOG2->apply(frame, mask_MOG2);

		cvtColor(frame, g_frame, CV_BGR2GRAY);

		detector.detectMultiScale(g_frame, found, param.scaleFactor, param.minNeigh, param.flags, param.minSize, param.maxSize);

		if(found.size() > 0){
			for(int i=0; i<found.size(); i++){
				rectangle(frame, found[i].br(), found[i].tl(), Scalar(0, 255, 0), 2, 8, 0);	
			}
		}

		//we're assuming one face
		if(found.size() == 1){
			new_y = found[0].br().y;
			if(old_y != -1){
				dy = new_y - old_y;
				//candidate for running
				if(dy > dy_threshold){
					running = true;
					still_count = 0;
				}else{
					++still_count;
					if(still_count >= still_count_threshold){
						running = false;
					}
				}
			}
                }else{
                    running = false;
                }

		if(running){
			cout << "RUNNING" << endl;
			system("bash ../key_press.sh w down");
		}else{
			cout << "STANDING STILL" << endl;
			system("bash ../key_press.sh w up");
		}

		imshow(WINDOW_NAME, frame);		
		imshow("MOG2", mask_MOG2);
		if(waitKey(1) == 'q') break;

		old_y = new_y;
	}	

	cap.release();
	return 0;
}
