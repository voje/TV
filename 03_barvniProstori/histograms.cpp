#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Histograms and color spaces"
#define TRACKBAR_NAME "Number of bins"

#define COLORSPACE_GRAY -1
#define COLORSPACE_RGB 0
#define COLORSPACE_B 1
#define COLORSPACE_G 2
#define COLORSPACE_R 3
#define COLORSPACE_HSV 4
#define COLORSPACE_HS 5
#define COLORSPACE_YCrCb 6

Mat src, converted, mask;
int bins = 25;
int colorspace = COLORSPACE_RGB;

void update_histogram(int, void*) {

  Mat histogram;
  bins = MAX(bins, 2);
  float range1[] = {0, 255};
  float range2[] = {0, 255};
  float range3[] = {0, 255};
  float *ranges[] = {range1, range2, range3};
	int histogram_bins[] = {bins, bins, bins};
	int channels[] = {0, 1, 2};
	int dimensions = 3;

  switch(colorspace) {
    case COLORSPACE_GRAY: {
      cvtColor(src, converted, CV_BGR2GRAY);
			dimensions = 1;
      break;
    }
    case COLORSPACE_R: {
      src.copyTo(converted);
			dimensions = 1;
      break;
    }
    case COLORSPACE_G: {
      src.copyTo(converted);
			dimensions = 1;
			channels[0] = 1;
      break;
    }
    case COLORSPACE_B: {
      src.copyTo(converted);
			dimensions = 1;
			channels[0] = 2;
      break;
    }
    case COLORSPACE_HS: {
      cvtColor(src, converted, CV_BGR2HSV); //cvtColor(src,dst,ColorMode) converts image btween colorspaces
			ranges[0][1] = 180;
			dimensions = 2;
      break;
    }
    case COLORSPACE_HSV: {
      cvtColor(src, converted, CV_BGR2HSV);
			ranges[0][1] = 180;
      break;
    }
    case COLORSPACE_YCrCb: {
      cvtColor(src, converted, CV_BGR2YCrCb);
      break;
    }
    default: {
      src.copyTo(converted);
      break;
    }
  }

  calcHist(&converted, 1, channels, mask, histogram, dimensions, histogram_bins, (const float**) ranges, true, false);
  histogram = histogram / (sum(histogram)[0] / 255);

  Mat backproject;
  calcBackProject(&converted, 1, channels, histogram, backproject, (const float**) ranges, 1, true);

  imshow(WINDOW_NAME, backproject);
}

int main(int argc, char** argv) {

  src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  
	if (argc > 2) {
		mask = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
		threshold(mask, mask, 255, 1, THRESH_BINARY);
	}

  namedWindow(WINDOW_NAME, CV_WINDOW_AUTOSIZE);
  createTrackbar(TRACKBAR_NAME, WINDOW_NAME, &bins, 256, update_histogram);
  update_histogram(0, 0);

	cout << "Press: \n * 1: Gray \n * 3: RGB \n * r: Red \n * g: Green \n * b: Blue \n * 2: HS \n * h: HSV \n * y: YCrCb \n";

  while (true)
  {
    int c = waitKey(0);
    switch(c % 256) {
      case 'q':
      case 27: {
        return 0;
      }
      case '1': {
        colorspace = COLORSPACE_GRAY;
        break;
      }
      case '3': {
        colorspace = COLORSPACE_RGB;
        break;
      }
      case 'r': {
        colorspace = COLORSPACE_R;
        break;
      }
      case 'g': {
        colorspace = COLORSPACE_G;
        break;
      }
      case 'b': {
        colorspace = COLORSPACE_B;
        break;
      }
      case '2': {
        colorspace = COLORSPACE_HS;
        break;
      }
      case 'h': {
        colorspace = COLORSPACE_HSV;
        break;
      }
      case 'y': {
        colorspace = COLORSPACE_YCrCb;
        break;
      }
    }
    update_histogram(0, 0);
  }

  return 0;
}

