#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{

  if (argc > 2) {

    FileStorage fs(argv[1], FileStorage::WRITE);

    Mat matrix(5, 5, CV_32FC1);
    randu(matrix, 0, 1);

    fs << "matrix" << matrix;
    fs << "arguments" << "{";
    for (int i = 2; i < argc; i++) {
      fs << format("arg%d", i-1) << string(argv[i]);
    }
    fs << "}";
    fs.release();

  } else if (argc == 2) {

    FileStorage fs(argv[1], FileStorage::READ);

    Mat matrix;
    fs["matrix"] >> matrix;
    cout << "Matrix: " << matrix << endl;

    FileNode arguments = fs["arguments"];
    for(FileNodeIterator it = arguments.begin(); it != arguments.end(); ++it)
      cout << (*it).name() << " = " << string(*it) << endl;
    
    fs.release();

  } else return -1;

  return 0;
}
