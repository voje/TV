#ifndef _MY_COLOR_EXTRACTOR_
#define _MY_COLOR_EXTRACTOR_

#include <opencv2/opencv.hpp>

using namespace cv;

class ColorExtractor{
	Mat bg;
	bool full;
	Point max_value;
	int n_max;
	int max_counter;
	int color_margin;
public:
	Point update_bg(Mat &src);
	Point BGR_to_bg(Vec3b BGR);
	Point get_max_square();
	ColorExtractor();
	Mat get_bg();
	bool is_full();
	void display_bg();
	void set_max_value();
	void check_fullness();
};

#endif