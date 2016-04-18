#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define CIRC_ESTIMATE 5
#define HOUGH_ACCUM_THRESH 40
#define BLUE Vec3b(255, 0, 0)
#define GREEN Vec3b(0, 255, 0)
#define RED Vec3b(0, 0, 255)
#define BLACK Vec3b(0, 0, 0)

using namespace cv;
using namespace std;

Mat src, dst, hsv, black;
Mat srcr, srcr1, srcg, srcb, circles;

void printPixels(Mat mat){
	for(int i=0; i<mat.rows; i++){
		for(int j=0; j<mat.cols; j++){
			cout << (mat.at<Vec3b>(i,j)) << endl;
		}
	}	
}

void opening(Mat& mat){
	Mat el = getStructuringElement(MORPH_RECT, Size(3,3));	
	erode(mat, mat, el);
	dilate(mat, mat, el);
}

void drawCirc(Mat& mat, vector<Vec3f> circles, Vec3b color){
	for(size_t i=0; i<circles.size(); i++){
		Point center = Point(circles[i][0], circles[i][1]);
		int radius = circles[i][2];
		circle(mat, center, radius, color, 5);
	}
}

int main(int argc, char** argv){
	/*approach: firts separate the single channel (using HSV seems to be easier), then detect circles*/

	if(argc < 2) exit(42);

	vector<Vec3f> circles;
	src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	cvtColor(src, hsv, CV_BGR2HSV);
	//GaussianBlur(src, src, Size(9, 9), 2, 2);	//this one does not help
	src.copyTo(dst);
	black = Mat_<Vec3b>(src.rows, src.cols, BLACK);

	/*minimum distance between circle centers for the circles to be recognized as separate
	I will assume there are less than 20 circles, equally distributed throughout the image*/
	int houghCircMinDist = cvRound( ( (src.rows + src.cols)/2 ) / CIRC_ESTIMATE);

	/*
	//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//first, we need to find out HSV values for R, G and B
	Mat r, g, b, rh, gh, bh;
	r = Mat_<Vec3b>(src.rows, src.cols, RED);
	cvtColor(r, rh, CV_BGR2HSV);
	cout << "red: " << rh.at<Vec3b>(0,0) << endl;
	//[0, 255, 255]
	
	g = Mat_<Vec3b>(src.rows, src.cols, GREEN);
	cvtColor(g, gh, CV_BGR2HSV);
	cout << "green:" << gh.at<Vec3b>(0,0) << endl;
	//[60, 255, 255]

	b = Mat_<Vec3b>(src.rows, src.cols, BLUE);
	cvtColor(b, bh, CV_BGR2HSV);
	cout << "blue:" << bh.at<Vec3b>(0,0) << endl;
	//[120, 255, 255]
	//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	*/

	/*use the range +-10 to filter out separate colors*/
	/*remove noise*/
	/*detect circles and add them to circles matrix*/
	//note that there are 2 ranges for red
	//r
	inRange(hsv, Vec3b(170, 100, 100), Vec3b(179, 255, 255), srcr);
	inRange(hsv, Vec3b(0, 100, 100), Vec3b(9, 255, 255), srcr1);
	addWeighted(srcr, 1, srcr1, 1, 1, srcr);
	GaussianBlur(srcr, srcr, Size(3, 3), 2, 2);
	HoughCircles(srcr, circles, CV_HOUGH_GRADIENT, 1, houghCircMinDist, 100, HOUGH_ACCUM_THRESH);
	cout << "red circles: \t" << circles.size() << endl;
	drawCirc(dst, circles, RED);
	drawCirc(black, circles, RED);
	//g
	inRange(hsv, Vec3b(50, 100, 100), Vec3b(69, 255, 255), srcg);
	GaussianBlur(srcg, srcg, Size(3, 3), 2, 2);
	HoughCircles(srcg, circles, CV_HOUGH_GRADIENT, 1, houghCircMinDist, 100, HOUGH_ACCUM_THRESH);
	cout << "green circles: \t" << circles.size() << endl;
	drawCirc(dst, circles, GREEN);
	drawCirc(black, circles, GREEN);
	//b
	inRange(hsv, Vec3b(90, 100, 100), Vec3b(129, 255, 255), srcb);
	GaussianBlur(srcb, srcb, Size(3, 3), 2, 2);
	HoughCircles(srcb, circles, CV_HOUGH_GRADIENT, 1, houghCircMinDist, 100, HOUGH_ACCUM_THRESH);
	cout << "blue circles: \t" << circles.size() << endl;
	drawCirc(dst, circles, BLUE);
	drawCirc(black, circles, BLUE);

	//printPixels(src);
	imshow("Original", dst);
	imshow("Black", black);

	cout << "Press 's', to save the image with drawn circles as circles_out.jpg." << endl;
	cout << "Press 'x', to exit." << endl;

	while(true){
		int k = waitKey(0);
		switch(k){
			case 's': {
				cout << "Saving image to file." << endl;
				imwrite("circles_out.jpg", dst);
				return 0;
			}
			case 'x': {
				cout << "Exit without save." << endl;
				return 0;
			}
		}
	}

	return 0;
}