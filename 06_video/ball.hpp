#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class Ball{
public:
	Ball(Point2f, int, Scalar, Point2f, float);
	void move();	
	Point2f get_center_pos();
	void draw(Mat&);
	void toString();
	void shove(vector<Point2f>);
private:
	Point2f center;
	int radius;
	Scalar color;
	Point2f speed;
	float acceleration;
};