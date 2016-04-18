#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

	if(argc != 2){
		cout << "Argument should be desired text." << endl;
		exit(42);
	}

	Mat img;
	//Mat img = imread("aurora.jpg"); 
	//Mat img(500, 500, CV_8UC3, Scalar::all(0));
	//cout << "Mat type is :" << img.type() << endl;	
	//check table online. Type 16 means CV_8UC3

	VideoCapture cam(0);	

	if(!cam.isOpened()){
		cout << "Cam is not opened." << endl;
		exit(42);
	}

	//text
	string myString = argv[1];
	int textFont = FONT_HERSHEY_PLAIN;
	int baseline = 0;
	double textScale = 2;
	int textThickness = 2;
	Scalar rectColor(0, 255, 0);
	Scalar textColor(Scalar::all(255));
	Size textSize = getTextSize(myString, textFont, textScale, textThickness, &baseline);

	while(true){
		cam.read(img);

		//center rect and text
		Point textPos((img.cols/2 - textSize.width/2), (img.rows/2 - textSize.height/2));

		rectangle(img, textPos+Point(-2, 2), textPos+Point(textSize.width+4, -textSize.height-4), rectColor, -1);
		putText(img, myString, textPos, textFont, textScale, textColor, textThickness);

		imshow("Preview_window", img);

		//wait for P key
		if(waitKey(50) == 112){
			break;
		}
	}
	imwrite("snapshot.png", img);

	return 0;
}

