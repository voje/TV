#ifndef _MY_HAND_TRACKER_
#define _MY_HAND_TRACKER_

#include <opencv2/opencv.hpp>

class HandTracker{
	std::string name; //left, right
	cv::Point hand_point;
	int search_radius;
public:
	void find_hand(cv::Mat&, cv::Rect&);
	HandTracker(std::string);
	bool is_left();
	cv::Point get_point();
};

#endif