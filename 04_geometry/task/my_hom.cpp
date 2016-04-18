#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/calib3d/calib3d.hpp"

#define WINDOW_NAME "Features."
#define MIN_HESSIAN 400
#define N_POINTS 4

using namespace std;
using namespace cv;

const Scalar red_color(0, 0, 255);
const string extr_name("ORB");

void draw_me(Mat& mat, string window_name){
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, mat);
}

bool compare_matches(DMatch first, DMatch second){
	return (first.distance < second.distance);
}

int main(int argc, char** argv){
	//load images
	Mat small_img, large_img, out_img;
	out_img = large_img.clone();
	vector<KeyPoint> kp1, kp2;
	Mat desc1, desc2;
	vector<DMatch> matches;
	vector<Point2f> good_pts1, good_pts2;
	small_img = imread("../girl_with_the_pearl_earring_s.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	large_img = imread("../girl_with_the_pearl_earring_l.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//small_img = imread("../cathedral.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//large_img = imread("../cathedral1.jpg", CV_LOAD_IMAGE_GRAYSCALE);


	//find keypoints
	Ptr<FeatureDetector> detector = ORB::create();
	detector -> detect(small_img, kp1);
	detector -> detect(large_img, kp2);
	cout << "kp: " << kp1.size() << endl;

	//create descriptors
	Ptr<DescriptorExtractor> extractor = ORB::create();
	extractor -> compute(small_img, kp1, desc1);
	extractor -> compute(large_img, kp2, desc2);
	cout << "desc: [" << desc1.rows << ", " << desc1.cols << "]" << endl;

	//find matches
	Ptr<DescriptorMatcher> matcher = new BFMatcher(NORM_L2, true);
	matcher -> match(desc1, desc2, matches);
	sort(matches.begin(), matches.end(), compare_matches);
	/*
	for(int i=0; i<matches.size(); i++){
		cout << matches[i].distance << endl;
	}
	*/

	//for testing
	vector<DMatch> gmatches;
	for(int i=0; i<N_POINTS; i++){
		gmatches.push_back(matches[i]);
		good_pts1.push_back(kp1[matches[i].queryIdx].pt);
		good_pts2.push_back(kp2[matches[i].trainIdx].pt);
	}
	//drawMatches(small_img, kp1, large_img, kp2, gmatches, out_img, red_color);

	Mat H = findHomography(good_pts1, good_pts2);	
	warpPerspective(small_img, out_img, H, small_img.size());

	//test draw
	//drawKeypoints(small_img, kp1, out_img, red_color);
	//drawKeypoints(large_img, kp2, out_img, red_color);
	//drawMatches(small_img, kp1, large_img, kp2, matches, out_img, red_color);

	draw_me(out_img, WINDOW_NAME);

	int c;
	while(true){
		c = waitKey(0);
		switch(c % 256){
			case 'q':{
				return 0;
			}
			default:{
				//meh
				return 0;
			}
		}
	}

	return 0;
}
