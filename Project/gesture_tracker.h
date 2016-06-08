#ifndef _MY_GESTURE_TRACKER_
#define _MY_GESTURE_TRACKER_

#include <opencv2/opencv.hpp>

class GestureTracker{
	bool running;
	bool run_toggle;
	int head_old_y;
	int head_old_dy;
	double head_dy_min;
	int head_running_vote;
	int head_standing_vote;
	int l_hand;
	int l_hand_vote;
	int r_hand;
	int r_hand_vote;
	int delay;
public:
	GestureTracker(int, int);	
	void update(cv::Rect, cv::Point, cv::Point, cv::Mat&);
	void take_action();
};

#endif