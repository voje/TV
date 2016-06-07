#ifndef _MY_GESTURE_TRACKER_
#define _MY_GESTURE_TRACKER_

#include <opencv2/opencv.hpp>

class GestureTracker{
	bool running;
	int l_hand;
	int r_hand;
	int delay;
public:
	GestureTracker(int);	
	void update(cv::Rect, cv::Point, cv::Point);
};

#endif