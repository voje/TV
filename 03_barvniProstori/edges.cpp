#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Edges"
#define TRACKBAR_NAME_LOW "Hysteresis low"
#define TRACKBAR_NAME_HIGH "Hysteresis high"
#define TRACKBAR_NAME_KERNEL "Smoothing"
#define MAX_THRESHOLD_SIZE 1000
#define MAX_KERNEL_SIZE 3

Mat src, dst;

int hysteresis_low = 5;
int hysteresis_high = 50;
int kernel_size = 1;

void do_canny(int, void*) {

  Canny(src, dst, hysteresis_low, hysteresis_high, MAX(1, kernel_size) * 2 + 1);

  imshow(WINDOW_NAME, dst);
}


int main(int argc, char** argv) {

  src = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

  namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);

  createTrackbar(TRACKBAR_NAME_LOW, WINDOW_NAME, &hysteresis_low, MAX_THRESHOLD_SIZE, do_canny);
  createTrackbar(TRACKBAR_NAME_HIGH, WINDOW_NAME, &hysteresis_high, MAX_THRESHOLD_SIZE, do_canny);
  createTrackbar(TRACKBAR_NAME_KERNEL, WINDOW_NAME, &kernel_size, MAX_KERNEL_SIZE, do_canny);

  do_canny(0, 0);

  waitKey(0);

  return 0;

}
