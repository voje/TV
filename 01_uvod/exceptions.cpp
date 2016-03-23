#include <iostream>
#include <exception>

using namespace std;

int main ()
{

  try
  {
      throw 1;
  }
  catch (int e)
  {
      cout << "Caught: " << e << endl;
  }

  try
  {
      int* myarray = new int[1000];
  }
  catch (exception& e)
  {
      cout << "Standard exception: " << e.what() << endl;
  }

  return 0;
}
