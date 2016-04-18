#include <iostream>
#include <ctype.h>
#include <opencv2/video.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Optical flow"
#define MAX_COUNT 500

vector<Point2f> points_now, points_previous;

static void on_mouse( int event, int x, int y, int flags, void* param) {

    if( event == EVENT_LBUTTONDOWN )
        points_now.push_back(Point2f((float)x, (float)y));
}

int main( int argc, char** argv ) {

    TermCriteria termcrit(TermCriteria::COUNT | TermCriteria::EPS, 20, 0.03);
    Size subPixWinSize(10, 10), winSize(31, 31);

    VideoCapture capture("../video.avi");

    if( !capture.isOpened() )
        return -1;
    
    cout << "Press r to initialize track-points automatically on good positions, c to clear the track-point set." << endl;
    cout << "Click on the image to initialize a track point manually." << endl;

    namedWindow(WINDOW_NAME, 1);
    setMouseCallback(WINDOW_NAME, on_mouse, 0);

    Mat gray_now, gray_previous, image, frame;

    for(;;)
    {
        capture >> frame;
        if( frame.empty() )
            break;

        cvtColor(frame, gray_now, COLOR_BGR2GRAY);

        if( !points_previous.empty() && !gray_previous.empty() )
        {
            vector<uchar> status;
            vector<float> err;

            calcOpticalFlowPyrLK(gray_previous, gray_now, points_previous, points_now, status, err, winSize, 3, termcrit, 0, 0.001);

            unsigned int k = 0;
            for(unsigned int i = k = 0; i < points_now.size(); i++) {

                if( !status[i] )
                    continue;

                points_now[k++] = points_now[i];
                circle(frame, points_now[i], 3, Scalar(0,255,0), -1, 8);
            }
            points_now.resize(k);
        }

        imshow(WINDOW_NAME, frame);

    int c = waitKey(10);
        switch(c % 256)
        {
        case 27:
          return 0;
        case 'r':
            goodFeaturesToTrack(gray_now, points_now, MAX_COUNT, 0.01, 10, Mat(), 3, 0, 0.04);
            cornerSubPix(gray_now, points_now, subPixWinSize, Size(-1,-1), termcrit);
            break;
        case 'c':
            points_previous.clear();
            points_now.clear();
            break;
        }

        std::swap(points_now, points_previous);
        cv::swap(gray_now, gray_previous);
    }

    return 0;
}

