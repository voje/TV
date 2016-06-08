#ifndef _MY_GESTURE_TRACKER_
#define _MY_GESTURE_TRACKER_

#include <opencv2/opencv.hpp>

class GestureTracker{
	bool running;
	int head_old_y;
	double head_percent;
	int head_running_vote;
	int head_standing_vote;
	int l_hand;
	int l_hand_vote;
	int r_hand;
	int r_hand_vote;
	int delay;
public:
	GestureTracker(int);	
	void update(cv::Rect, cv::Point, cv::Point, cv::Mat&);
	int get_state();
};

#endif