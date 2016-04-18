#include <iostream>
#include <opencv2/core/core.hpp>

using namespace std;

int main()
{
  // Basic structures

  cv::Point2f p1, p2;

  p1.x = 1;
  p1.y = 0;

  p2 = cv::Point2f(2, 3);

  std::cout << "Point 1: " << p1 << std::endl;
  std::cout << "Point 2: " << p2 << std::endl;

  p1 = p1 + p2;
  p2 *= 3;

  cv::Size s;
  s.width = 100;
  s.height = 200;

  cv::Rect2f r1, r2;

  r1.x = 10;
  r1.y = 10;
  r1.width = 100;
  r1.height = 100;

  r2.x = 50;
  r2.y = 50;
  r2.width = 100;
  r2.height = 100;

  std::cout << "Rect 1: " << r1 << std::endl;
  std::cout << "Rect 2: " << r2 << std::endl;

  std::cout << "Union: " << (r1 & r2) << std::endl;
  std::cout << "Intersection: " << (r1 | r2) << std::endl;

  // Matrix class

  cv::Mat m1 = (cv::Mat_<float>(3,3) << 100, 0, 32, 0, 100, 20, 0, 1, 1);

  cv::Mat m2(3, 3, CV_32FC1);
  m2.setTo(1);

  cv::Mat m = m1 + m2;

  std::cout << "Matrix size: " << m.cols << " x " << m.rows << " x " << m.channels() << std::endl;

  float* ptr = (float*) m.data;
  for (int i = 0; i < m.cols * m.rows * m.channels(); i++)
    std::cout << ptr[i] << ", ";
  std::cout << std::endl;

  // How to get only 1 row/col?
  std::cout << "Accessing first row:" << std::endl;
  int i=0;
  for(int j=0; j<m.rows; j++){
    std::cout << m.at<float>(i, j) << std::endl;
  }

  std::cout << "Accessing first col:" << std::endl;
  for(int i=0; i<m.rows; i++){
    int j=0;
    std::cout << m.at<float>(i, j) << std::endl;
  }
  return 0;

}













