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
	this->head_old_y = -1;
	this->head_percent = 0.02;
	this->head_running_vote = 0;
	this->head_standing_vote = 0;
	this->l_hand = -1;
	this->l_hand_vote = 0;
	this->r_hand = -1;
	this->r_hand_vote = 0;
	this->delay = delay;
}

void GestureTracker::update(Rect face_rect, Point l_hand, Point r_hand, Mat &frame){

	//update head
	//set a margin for head bobbing, relative to frame height. say 2% or something (test it)
	int y_diff = floor(frame.rows * head_percent);
	int head_y = face_rect.tl().y;
	//if not initialized
	if(head_old_y == -1){
		head_old_y = head_y;
		return;
	}
	int dy = abs(head_old_y - head_y);
	if(!running){
		if(dy > y_diff){
			head_running_vote += 1;
		}else{
			head_running_vote = 0;
		}
	}else if(running){
		if( dy > y_diff){
			head_standing_vote = 0;
		}else{
			head_standing_vote +=1;
		}
	}
	if(head_running_vote >= delay){
		running = true;
		head_running_vote = 0;
	}
	if(head_standing_vote >= delay){
		running = false;
		head_standing_vote = 0;
	}

	int mid_height = floor(0.2*frame.rows);

	//update l_hand
	int ly = l_hand.y;
	int l_hand_new;
	if(ly < head_y){
		l_hand_new = 1;
	}else if(ly < head_y + mid_height){
		l_hand_new = 2;
	}else{
		l_hand_new = 3;
	}

	if(l_hand_new != this->l_hand){
		l_hand_vote += 1;
	}else{
		l_hand_vote = 0;
	}

	if(l_hand_vote >= delay){
		this->l_hand = l_hand_new;
		l_hand_vote = 0;
	}

	//update r_hand
	int ry = r_hand.y;
	int r_hand_new;
	if(ry < head_y){
		r_hand_new = 4;
	}else if(ry < head_y + mid_height){
		r_hand_new = 5;	
	}else{
		r_hand_new = 6;
	}

	if(r_hand_new != this->r_hand){
		r_hand_vote += 1;
	}else{
		r_hand_vote = 0;
	}

	if(r_hand_vote >= delay){
		this->r_hand = r_hand_new;
		r_hand_vote = 0;
	}

}//update

int GestureTracker::get_state(){
	if(l_hand == -1 || r_hand == -1){
		return -1;
	}	
	//todo: write all possible states
}









