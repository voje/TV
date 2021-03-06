#include "hand_tracker.h"

using namespace std;
using namespace cv;

HandTracker::HandTracker(string name){
	this->name = name;
	this->hand_point = Point(-1, -1);
	this->search_radius = 2;
}

bool HandTracker::is_left(){
	if(this->name.compare("left") == 0){
		return true;
	}else{
		return false;
	}
}

Point HandTracker::get_point(){
	return this->hand_point;
}

void HandTracker::find_hand(Mat &frame, Rect &face_rect){
	int face_mid_x;
	//if we don't have head position, assume middle of the screen
	if(face_rect.tl().x == -1){
		face_mid_x = floor(frame.cols/2);
	}else{
		//extend face rectangle a bit, so we don't search for hands where the face is
		int ext = floor( (face_rect.br().x - face_rect.tl().x)/2 );
		if(this->is_left()){
			face_mid_x = face_rect.tl().x - ext;
			if(face_mid_x < 0){
				return;
			}
		}else{
			face_mid_x = face_rect.br().x + ext; 
			if(face_mid_x >= frame.cols){
				return;
			}
		}
	}

	//create submat, left/right of face_rect
	Mat submat;	// [0, face_mid_x], [face_mid_x, frame.cols]
	if(this->is_left()){
		submat = frame(Range(0, frame.rows), Range(0, face_mid_x));
	}else{
		submat = frame(Range(0, frame.rows), Range(face_mid_x, frame.cols));
	}

	//find a dense area, traverse to the leftmost/rightmost point
	int r = this->search_radius;
	double area = -1;
	Point max_center(-1, -1);

	if(this->is_left()){
		for(int j=r; j<submat.cols-r; j++){
			for(int i=submat.rows-r; i>=r; i--){
				Scalar ssuma = sum(submat(Range(i-r, i+r), Range(j-r, j+r)));
				double suma = ssuma[0]*(submat.cols - j);
				if(suma > area){
					area = suma;
					max_center = Point(j, i);
				}
			}
		}
	}else{
		for(int j=submat.cols-r; j>=r; j--){
			for(int i=submat.rows-r; i>=r; i--){
				Scalar ssuma = sum(submat(Range(i-r, i+r), Range(j-r, j+r)));
				double suma = ssuma[0]*j;
				if(suma > area){
					area = suma;
					max_center = Point(j, i);
				}
			}
		}
	}

	//translate point back to original frame
	Point old_point = this->hand_point;
	hand_point = max_center;
	if(!this->is_left()){
		hand_point.x += face_mid_x;
	}
	Point vector(0, 0);
	vector -= old_point;
	vector += hand_point;
	double factor = 0.7;
	vector.x = floor(vector.x * factor);
	vector.y = floor(vector.y * factor);
	hand_point = old_point + vector;
	//cout << old_point << " -> " << hand_point << " : ";
	//cout << vector << endl;

	//testing
	//cout << frame.type() << endl; //8UC3
	//cout << submat.type() << endl; //8UC3
	//cout << max_center << endl;
	/*
	rectangle(submat, hand_point+Point(r, r), hand_point-Point(r, r), Scalar(0, 255, 0), 2, 8, 0);	
	imshow("submat", submat);
	rectangle(frame, hand_point+Point(r, r), hand_point-Point(r, r), Scalar(0, 255, 0), 2, 8, 0);	
	imshow("frame", frame);
	waitKey(0);
	*/
}