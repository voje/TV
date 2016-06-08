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

enum fields{TL, ML, BL, TR, MR, BR};	//top left, ...

GestureTracker::GestureTracker(int delay, int head_dy_min){
	this->running = false;
	this->run_toggle = false;	//send run action only when toggled
	this->head_old_y = -1;
	this->head_old_dy = -1;
	this->head_running_vote = 0;
	this->head_standing_vote = 0;
	this->head_dy_min = head_dy_min;
	this->l_hand = -1;
	this->l_hand_vote = 0;
	this->r_hand = -1;
	this->r_hand_vote = 0;
	this->delay = delay;
}

void GestureTracker::update(Rect face_rect, Point l_hand, Point r_hand, Mat &frame){

	//update head
	int y_diff = head_dy_min;	//how many pixels counts as a head move?
	int head_y = face_rect.tl().y;
	//if not initialized
	if(head_old_y == -1){
		head_old_y = head_y;
		return;
	}
	int head_dy = head_y - head_old_y;
	if(!running){
		if(abs(head_dy) > y_diff){
			head_running_vote += 1;
		}else{
			head_running_vote = 0;
		}
	}else if(running){
		if(abs(head_dy) > y_diff){
			head_standing_vote = 0;
		}else{
			head_standing_vote +=1;
		}
	}
	if(head_running_vote >= delay){	//extra check for false positives
		running = true;
		std::cout << "running" << std::endl;
		run_toggle = true;
		head_running_vote = 0;
	}
	if(head_standing_vote >= delay){
		running = false;
		std::cout << "standing" << std::endl;
		run_toggle = true;
		head_standing_vote = 0;
	}
	head_old_y = head_y;
	head_old_dy = head_dy;

	int mid_height = floor(0.2*frame.rows);
	//update l_hand
	int ly = l_hand.y;
	int l_hand_new;
	if(ly < head_y){
		l_hand_new = TL;
	}else if(ly < head_y + mid_height){
		l_hand_new = ML;
	}else{
		l_hand_new = BL;
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
		r_hand_new = TR;
	}else if(ry < head_y + mid_height){
		r_hand_new = MR;	
	}else{
		r_hand_new = BR;
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

void GestureTracker::take_action(){
	//uses key_press.sh to take an action
	if(l_hand == -1 || r_hand == -1){
		return;
	}	

	//handle run toggle
	if(run_toggle){
		if(running){
			system("bash ../key_press.sh RUN_ON");
		}else{
			system("bash ../key_press.sh RUN_OFF");
		}
		run_toggle = false;
	}
}









