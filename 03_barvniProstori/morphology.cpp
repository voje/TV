#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Morphology"
#define TRACKBAR_NAME_EROSION "Erosion size"
#define TRACKBAR_NAME_DILATION "Dilation size"
#define MAX_SIZE 16

#define MODE_OPENING 1
#define MODE_CLOSING 2

Mat src, tmp, dst;

int structuring_element = MORPH_RECT;
int erosion_size = 0;
int dilation_size = 0;
int mode = MODE_OPENING;

void do_morphology(int, void*) {

  Mat erode_element = getStructuringElement(structuring_element, 
			Size(2 * erosion_size + 1, 2 * erosion_size + 1),
      	Point(erosion_size, erosion_size));

  Mat dilate_element = getStructuringElement(structuring_element, 
			Size(2 * dilation_size + 1, 2 * dilation_size + 1),
      	Point(dilation_size, dilation_size));

	switch (mode) {
	case MODE_OPENING:
		erode(src, tmp, erode_element);
		dilate(tmp, dst, dilate_element);
		break;
	case MODE_CLOSING:
		dilate(src, tmp, dilate_element);
		erode(tmp, dst, erode_element);
		break;
	}

  imshow(WINDOW_NAME, dst);
}

int main(int argc, char** argv) {

  src = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

	threshold(src, src, 0, 255, THRESH_BINARY | THRESH_OTSU);

  namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);

	cout << "Press: \n * o: Opening (erosion, dilation) \n * c: Closing (dilation, erosion) \n * 1: Rectangular structuring element \n * 2: Circular structuring element \n * 3: Cross structuring element \n";

  createTrackbar(TRACKBAR_NAME_EROSION, WINDOW_NAME, &erosion_size, MAX_SIZE, do_morphology);
  createTrackbar(TRACKBAR_NAME_DILATION, WINDOW_NAME, &dilation_size, MAX_SIZE, do_morphology);

	do_morphology(0, 0);

  while (true)
  {
    int c = waitKey(0);
    switch(c % 256) {
      case 'q':
      case 27: {
        return 0;
      }
      case 'o': {
        mode = MODE_OPENING;
        break;
      }
      case 'c': {
        mode = MODE_CLOSING;
        break;
      }
      case '1': {
        structuring_element = MORPH_RECT;
        break;
      }
      case '2': {
        structuring_element = MORPH_ELLIPSE;
        break;
      }
      case '3': {
        structuring_element = MORPH_CROSS;
        break;
      }
    }
    do_morphology(0, 0);
  }

  return 0;
}


