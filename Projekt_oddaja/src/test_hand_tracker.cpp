#include "hand_tracker.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv){
	Mat img = imread("../sample_pictures/capture0.jpg");
	//create hand tracker for left hand
	HandTracker hl("left");	
	HandTracker hr("right");	
	//imaginary face_rectangle in the middle of image
	Rect face_rect(-1, -1, 0, 0); //x, y, width, height
	hl.find_hand(img, face_rect);
	hr.find_hand(img, face_rect);
	return 0;
}