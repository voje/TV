#include <iostream>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main( int argc, const char** argv )
{
  CommandLineParser parser(argc, argv,
      "{help h      |         | Print this help}"
      "{operation o | sum     | Operation to use}"
      "{name n      | user    | User name}"
      "{@value1||First value}{@value2||Second value}"
  );

  parser.about("Command line parsing example");

  if (!parser.check()) {
    parser.printErrors();
    return -1;
  }

  if (parser.has("help"))
  {
    parser.printMessage();
    return 0;
  }

  if (!parser.has("@value1") || !parser.has("@value2")) {
    cout << "Missing values" << endl;
    return -2;
  }

  string operation = parser.get<string>("operation");
  string name = parser.get<string>("name");
  float value1 = parser.get<float>("@value1");
  float value2 = parser.get<float>("@value2");

  float result = 0;

  if (operation == "sum") {
    result = value1 + value2;
  } else if (operation == "product") {
    result = value1 * value2;
  } else if (operation == "division") {
    result = value1 / value2;
  } else {
    cout << "Unknown operation" << endl;
    return -3;
  }

  cout << format("Dear %s, the result is %.2f", name.c_str(), result) << endl;

  return 0;
}





