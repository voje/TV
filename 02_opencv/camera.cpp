#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 
int main() {

  VideoCapture camera(0); // ID of the camera
 
  if (!camera.isOpened()) {
    cout << "Unable to access camera" << endl;
    return -1;
  }
 
  Mat frame;

  cout << "Framerate: " << camera.get(CV_CAP_PROP_FPS) << endl;

  camera.set(CV_CAP_PROP_CONTRAST, 0.5);

  while (true) {
   
    camera.read(frame);
    imshow("Camera", frame);

    waitKey(0);

    //int a = waitKey(30);
    //cout << a << endl;

  }

  return 0;
}
