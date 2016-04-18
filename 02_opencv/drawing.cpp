#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat frame;

void mouse(int event, int x, int y, int, void* data) {

  // Right click clears the image
  if( event == EVENT_RBUTTONDOWN ) {
    frame.setTo(0);
    return;
  }

  // Left click draws a blue filled circle
  if( event == EVENT_LBUTTONDOWN ) {
    circle(frame, Point(x, y), 10, Scalar(255, 0, 0, 0), -1);
    return;
  }

}

int main() {

  frame = Mat(480, 640, CV_8UC3);
  frame.setTo(0); // Clear to black

  namedWindow("Drawing");

  setMouseCallback("Drawing", mouse, NULL);

  // Repeat in loop
  while (true) {
    imshow("Drawing", frame);
    if (waitKey(30) >= 0)
      break;
  }

  return 0;
}
