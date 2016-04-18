#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
 
int main() {

  // Reading image
  Mat img = imread("aurora.jpg");

  imshow("Image", img);

  waitKey(10000); //parameter is ms, returns key value or -1 if time elapses without keypress

  // Writing image
  imwrite("out.png", img);

  // Reading video
  VideoCapture video("video.avi");

  Mat frame;
  while (true) {
   
    video.read(frame);
    if (frame.empty())
      break;

    imshow("Video", frame);

    if (waitKey(30) >= 0)
      break;
  }

  video.release();

  // Writing video

  VideoWriter writer("test.avi", VideoWriter::fourcc('P','I','M','1'), 25, img.size(), true);

  for (int i = 0; i < 100; i++)
    writer.write(img);

  writer.release();

  VideoCapture video1("test.avi");
  Mat frame1;
  while(true){
    video1.read(frame1);
    if(frame.empty())
      break;

    imshow("Video1", frame1);

    if(waitKey(2000) >= 0)
      break;
  }

  return 0;
}
