#include <iostream>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "ball.hpp"

#define WINDOW_NAME "bouncy_ball"
#define WAIT_KEY_DELAY 50	//miliseconds
#define RADIUS 16 //screen.width / 16
#define ACCELERATION 0.9

using namespace cv;
using namespace std;

Mat prev_frame, now_frame;
vector<Point2f> flow_vectors, prev_points, now_points;
Ball* bl = 0;

Ball::Ball(Point2f cent, int rad, Scalar co, Point2f sp, float acc){
	center = cent;
	radius = rad;
	color = co;
	speed = sp;
	acceleration = acc;	
}

//changes position
void Ball::move(){
	Size size = now_frame.size();
	if(center.x - radius < 0){
		center.x = radius;
		speed.x = abs(speed.x);
	}
	if(center.x + radius > size.width-1){
		center.x = size.width-1-radius;
		speed.x = -abs(speed.x);
	}
	if(center.y - radius < 0){
		center.y = radius;
		speed.y = abs(speed.y);
	}
	if(center.y + radius > size.height-1){
		center.y = size.height-1-radius;
		speed.y = -abs(speed.y);
	}
	center = center + speed*WAIT_KEY_DELAY;
	//cout << "speed: " << speed << endl;
}

//changes speed
void Ball::shove(vector<Point2f> shove_vectors){
	if(shove_vectors.size() == 0){
		return;
	}
	speed = 0.99 * speed + 0.01 * shove_vectors[0];
	speed *= acceleration;
	//cout << "shove: " << shove_vectors[0] << endl;
}

Point2f Ball::get_center_pos(){
	return center; 
}

void Ball::draw(Mat& m){
	circle(m, center, radius, color, 4);
}

void Ball::toString(){
	cout 	<< "center: " << center << ", "
			<< "radius: " << radius << ", "
			<< "speed: " << speed << ", "
			<< "acceleration: " << acceleration << endl;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata){
	if(event == EVENT_LBUTTONDOWN){
		//now_points help calcuate flow vectors
		prev_points.clear();
		now_points.clear();
		now_points.push_back(Point2f(x,y));
		//create the ball object
		//toDo
		//cout << Point2f(x,y) << endl;
		int r = int(now_frame.size().width/RADIUS);
		bl = new Ball(Point2f(x,y), r, Scalar(0,255,0), Point2f(0,0), ACCELERATION);
		bl -> toString();
	}
}

int main(){

	cout << "Click on the screen to place the ball." << endl;
	//VideoCapture video("../video.avi");
	VideoCapture video(0);

	namedWindow(WINDOW_NAME, 2);
	setMouseCallback(WINDOW_NAME, CallBackFunc, NULL);

	for(;;){
		video >> now_frame;
		flip(now_frame, now_frame, 1);
		if(now_frame.empty()) break;

		if( !prev_frame.empty() && !prev_points.empty() ){
			vector<uchar> status;
			vector<float> err;
			calcOpticalFlowPyrLK(prev_frame, now_frame, prev_points, now_points, status, err, Size(21,21), 3);

			//calculate the vectors
			flow_vectors.reserve(prev_points.size());
			//assuming we have 1 point
			flow_vectors.clear();
			flow_vectors.push_back(now_points[0] - prev_points[0]);
		}

		//move the ball and draw it (if we have one)
		if( bl != 0 ){
			bl->shove(flow_vectors);
			bl->move();
			bl->draw(now_frame);
			now_points[0] = bl->get_center_pos();
		}

		imshow(WINDOW_NAME, now_frame);	

		waitKey(WAIT_KEY_DELAY);

		std::swap(now_points, prev_points);
		cv::swap(now_frame, prev_frame);
	}

	delete bl;
	return 0;
}