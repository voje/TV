#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int const max_bin_val = 255;
int const max_type = 4;
int thresh_val = 100;
int thresh_type = 2;
string window_name = "Thresholding";
Mat src, dst;

void do_thresholding(int, void*){
	//threshold(src, dst, thresh_val, max_bin_val, thresh_type);
	threshold(src, dst, 255, 1, thresh_type);
	imshow(window_name, dst);	
}
int main(int argc, char** argv){

	if(argc < 2) exit(42);
	src = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	createTrackbar("Threshold type", window_name, &thresh_type, max_type, do_thresholding);
	createTrackbar("Threshold value", window_name, &thresh_val, max_bin_val, do_thresholding);

	do_thresholding(0,0);

	cout << "Press 'x' to escape." << endl;
	while(waitKey(0)!='x'){
		//wait
	}

	return 0;
}
