#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Thresholding"
#define TRACKBAR_NAME "Threshold value"
#define MAX_BINARY_VALUE 255

int threshold_value = 128;
int threshold_type = THRESH_BINARY;
Mat src, dst;

void do_threshold( int, void* )
{
  if (threshold_value < 0) {
    int threshold_value = 0;
    threshold_value = threshold(src, dst, threshold_value, MAX_BINARY_VALUE, threshold_type | THRESH_OTSU);
    setTrackbarPos(TRACKBAR_NAME, WINDOW_NAME, threshold_value);
  } else {
    threshold(src, dst, threshold_value, MAX_BINARY_VALUE, threshold_type);
  }

  imshow(WINDOW_NAME, dst);
}


int main( int argc, char** argv )
{
  src = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

  namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);

  cout << "Press: \n * b: Binary \n * i: Binary Inverted \n * t: Truncate \n * z: To Zero \n * v: To Zero Inverted \n * o: Otsu's method \n";

  createTrackbar(TRACKBAR_NAME, WINDOW_NAME, &threshold_value, MAX_BINARY_VALUE, do_threshold);

  do_threshold(0, 0);

  while (true)
  {
    int c = waitKey(0);
    switch(c % 256) {
      case 'q':
      case 27: {
        return 0;
      }
      case 'b': {
        threshold_type = THRESH_BINARY;
        break;
      }
      case 'i': {
        threshold_type = THRESH_BINARY_INV;
        break;
      }
      case 't': {
        threshold_type = THRESH_TRUNC;
        break;
      }
      case 'z': {
        threshold_type = THRESH_TOZERO;
        break;
      }
      case 'v': {
        threshold_type = THRESH_TOZERO_INV;
        break;
      }
      case 'o': {
        threshold_value = -1;
        break;
      }
    }
    do_threshold(0, 0);
  }

  return 0;

}


