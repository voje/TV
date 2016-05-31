#include "color_extractor.h"

ColorExtractor::ColorExtractor(){
	bg = Mat::zeros(Size(255, 255), CV_8U);	
	full = false;
}

void ColorExtractor::update_bg(Mat &src){
	//keep updating color space until there's one full column (most prominent color)
	if(full){
		return;
	}
	imshow("test_show", src);
	for(int i=0; i<src.rows; i++){
		for(int j=0; j<src.cols; j++){
			Vec3d BGR = src.at<unsigned char>(Point(j, i));
			int sum = BGR[0] + BGR[1] + BGR[2];
			Vec3d bgr = BGR/sum;
			int counter = bg.at<unsigned char>(Point(bgr[0], bgr[1]));
			if(counter < 255){
				counter += 1;
			}else{
				full = true;
			}
			bg.at<unsigned char>(Point(bgr[0], bgr[1])) = counter;
		}
	}	
}

Mat ColorExtractor::get_bg(){
	return bg;
}

bool ColorExtractor::is_full(){
	return full;
}
