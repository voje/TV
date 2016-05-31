#ifndef _MY_COLOR_EXTRACTOR_
#define _MY_COLOR_EXTRACTOR_

#include "opencv2/opencv.hpp"

using namespace cv;

class ColorExtractor{
	Mat bg;
	bool full;
public:
	void update_bg(Mat &src);
	ColorExtractor();
	Mat get_bg();
	bool is_full();
};

#endif