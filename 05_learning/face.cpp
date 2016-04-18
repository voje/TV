#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

#define WINDOW_NAME "Face detection"

CascadeClassifier cascade;

int main( int argc, char** argv ) {

  if( !cascade.load("face_cascade.xml") ) {
      cerr << "Could not load classifier cascade" << endl;
      return -1;
  }

  VideoCapture camera(0); // ID of the camera
 
  if (!camera.isOpened()) {
    cerr << "Unable to access camera" << endl;
    return -1;
  }
 
  Mat frame, gray;
  vector<Rect> faces;

  while (true) {
   
    camera.read(frame);

    cvtColor(frame, gray, COLOR_BGR2GRAY);

    double t = 0;
    faces.clear();

    t = (double)getTickCount();
    cascade.detectMultiScale(gray, faces,
        1.1, 3, CASCADE_FIND_BIGGEST_OBJECT | CASCADE_DO_ROUGH_SEARCH | CASCADE_SCALE_IMAGE,
        Size(120, 120), Size(180, 180) );

    t = (double)getTickCount() - t;
    cout << format("Processing time %.2f s", t / (double)getTickFrequency()) << endl;

    for (unsigned int i = 0; i < faces.size(); i++) {
        Rect r = faces[i];

        rectangle(frame, Point(round(r.x), round(r.y)),
                   Point(round((r.x + r.width-1)), round((r.y + r.height-1))),
                   Scalar(255, 255, 255), 3, 8, 0);
    }
    imshow(WINDOW_NAME, frame);

    if (waitKey(10) >= 0)
      break;
  }

  return 0;
}



