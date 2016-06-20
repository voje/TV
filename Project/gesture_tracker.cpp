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
	this->turning_left = false;
	this->turning_right = false;
	this->reset = true;	//if reset is true, we are listening for a new action
}

void GestureTracker::update(Rect face_rect, Point l_hand, Point r_hand, Mat &frame){

	//update head
	int y_diff = head_dy_min;	//how many pixels counts as a head move?
	int head_y = floor( (face_rect.tl().y + face_rect.br().y) / 2);
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
		//std::cout << "running" << std::endl;
		run_toggle = true;
		head_running_vote = 0;
	}
	if(head_standing_vote >= delay){
		running = false;
		//std::cout << "standing" << std::endl;
		run_toggle = true;
		head_standing_vote = 0;
	}
	head_old_y = head_y;
	head_old_dy = head_dy;

	int mid_height = floor(0.3*frame.rows);
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

	//in case hands haven't been detected
	if(l_hand == -1 || r_hand == -1){
		return;
	}	
	if(l_hand == TL && r_hand == TR){
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

	//turning left and right
	if(l_hand == TL && r_hand == BR && !turning_left && !turning_right){
		turning_left = true;
		system("bash ../key_press.sh TURN_LEFT_ON");
	}
	else if(l_hand != TL && turning_left){
		turning_left = false;
		system("bash ../key_press.sh TURN_LEFT_OFF");
	}
	if(l_hand == BL && r_hand == TR && !turning_left && !turning_right){
		turning_right = true;
		system("bash ../key_press.sh TURN_RIGHT_ON");
	}
	else if(r_hand != TR && turning_right){
		turning_right = false;
		system("bash ../key_press.sh TURN_RIGHT_OFF");
	}

	//other actions, available while standing still
	if(running){
		return;
	}
	if(l_hand == BL && r_hand == BR){
		this->reset = true;
	}
	else if(l_hand == TL && r_hand == TR && reset){
		reset = false;
		system("bash ../key_press.sh JUMP");
	}
	else if(l_hand == ML && r_hand == MR && reset){
		reset = false;
		system("bash ../key_press.sh TAB");
	}
	else if(l_hand == ML && r_hand == BR && reset){
		reset = false;
		system("bash ../key_press.sh SHOOT");
	}
	else if(l_hand == BL && r_hand == MR && reset){
		reset = false;
		system("bash ../key_press.sh SHIELD");
	}
	else if(l_hand == ML && r_hand == BR && reset){
		reset = false;
		system("bash ../key_press.sh LOOT");
	}
}//take action

//visualization
void GestureTracker::draw_grid(Mat &frame, Rect face_rect){
	//void line(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
	int mid_height = floor(0.3*frame.rows);
	int head_y = floor( (face_rect.tl().y + face_rect.br().y) / 2);
	line(frame, Point(0, head_y), Point(frame.cols, head_y), Scalar(69, 0, 255));
	line(frame, Point(0, head_y+mid_height), Point(frame.cols, head_y+mid_height), Scalar(69, 0, 255));
}









