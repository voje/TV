#ifndef _MY_COLOR_EXTRACTOR_
#define _MY_COLOR_EXTRACTOR_

#include "opencv2/opencv.hpp"

using namespace cv;

class ColorExtractor{
	Mat bg;
	bool full;
	Point max_value;
	int max_counter;
public:
	Point update_bg(Mat &src);
	Point BGR_to_bg(Vec3b BGR);
	ColorExtractor(void);
	Mat get_bg();
	bool is_full();
	void display_bg();
};

#endif