#include "gesture_tracker.h"

using namespace cv;

/* frame will be divided into 6 regions for tracking hands (h represents head)
   Gesture is encoded as a pair: l_hand, r_hand.
   There are also 2 states: running and !running.

0		3
	h
1		4
2		5

Height of area [0 3]: from top of the frame, to centre of head rectangle.
Height of area [1 4]: 20% of frame height.
Height of area [2 5]: rest of frame.

*/

GestureTracker::GestureTracker(int delay){
	this->running = false;
	this->l_hand = 2;
	this->r_hand = 5;
	this->delay = delay;
}

void GestureTracker::update(Rect face_rect, Point l_hand, Point r_hand){

}