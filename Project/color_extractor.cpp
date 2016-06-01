#include "color_extractor.h"
#include <iostream>

ColorExtractor::ColorExtractor(){
	bg = Mat::zeros(Size(100, 100), CV_16U);	// CV_U8 -> unsigned char	
	full = false;
	max_value = Point(-1, -1);
	max_counter = 1000;
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

Point ColorExtractor::update_bg(Mat &src){
	//keep updating color space until there's one full column (most prominent color)
	//return position of the full column when full
	if(full){
		return max_value;
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
			}else{
				full = true;
				max_value = p;
			}
			bg.at<int>(p) = counter;
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
	imshow("bg_show", bg_show);
}

bool ColorExtractor::is_full(){
	return full;
}
