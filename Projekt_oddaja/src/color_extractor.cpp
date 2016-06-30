#include "color_extractor.h"
#include <iostream>

using namespace std;

ColorExtractor::ColorExtractor(){
	this->bg = Mat::zeros(Size(100, 100), CV_16UC1);
	this->full = false;	//bg is full after n_max fields have max_counter value
	this->max_value = Point(-1, -1);
	this->n_max = 4;	//how many point in bg should we fill to max
	this->max_counter = 1000;
}

Point ColorExtractor::BGR_to_bg(Vec3b BGR){
	//converts BGR onto a 100x100 bg color space
	double sum = BGR[0] + BGR[1] + BGR[2];
	sum += 1e-9;
	Vec3d bgr(BGR[0], BGR[1], BGR[2]);
	bgr /= sum;
	//scale [0, 1] to [0, 100)
	bgr *= 100;
	Point p((int)bgr[0], (int)bgr[1]);
	return p;
}

//obsolete
Point ColorExtractor::get_max_square(){
	//find area in bg with hightes values
	//square size: (color_margin + 1 + color_margin)^2
	int area_max = 0;
	Point point_max = Point(-1, -1);
	for(int i=color_margin; i<bg.rows-color_margin; i++){
		for(int j=color_margin; j<bg.cols-color_margin; j++){
			Mat square = bg(Range(i-color_margin, i+color_margin), Range(j-color_margin, j+color_margin));
			Scalar sc = sum(square);
			int s = sc[0];
			if(s > area_max){
				area_max = s;
				point_max = Point(j, i);
			}
		}
	}
	return point_max;
}

void ColorExtractor::set_max_value(){
	//similar to get_max_square
	int r = 1;
	Point point_max(-1, -1);
	int area_max = 0;
	for(int i=r; i<bg.rows-r; i++){
		for(int j=r; j<bg.cols-r; j++){
			Mat square = bg(Range(i-r, i+r), Range(j-r, j+r));
			Scalar sc = sum(square);
			int s = sc[0];
			if(s > area_max){
				area_max = s;
				point_max = Point(j, i);
			}
		}
	}
	this->max_value = point_max;
}

void ColorExtractor::check_fullness(){
	int c = 0;
	for(int i=0; i<bg.rows; i++){
		for(int j=0; j<bg.cols; j++){
			if(bg.at<int>(Point(j, i)) == max_counter){
				c += 1;
			}
		}
	}
	if(c == n_max){
		this->full = true;
	}
}

Point ColorExtractor::update_bg(Mat &src){
	//keep updating color space until there's one full column (most prominent color)
	//return position of the full column when full
	if(full){
		return this->max_value;
	}
	for(int i=0; i<src.rows; i++){
		for(int j=0; j<src.cols; j++){
			Vec3b BGR = src.at<Vec3b>(Point(j, i));
			Point p = ColorExtractor::BGR_to_bg(BGR);
			/*
			std::cout << sum << std::endl;
			std::cout << BGR << std::endl;
			std::cout << bgr << std::endl;
			std::cout << p << std::endl;
			*/
			int counter = bg.at<int>(p);
			if(counter < max_counter){
				counter += 1;
				bg.at<int>(p) = counter;
			}else{
				this->check_fullness();
				this->set_max_value();
				//max_value = get_max_square();
				this->max_value = p;
			}
		}
	}
	return Point(-1, -1);
}

Mat ColorExtractor::get_bg(){
	return bg;
}

void ColorExtractor::display_bg(){
	Mat bg_show;
	bg.convertTo(bg_show, CV_8U);
	//imshow("bg_show", bg_show);
}

bool ColorExtractor::is_full(){
	return full;
}
