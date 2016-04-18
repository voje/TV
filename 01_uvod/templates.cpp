
#include <iostream>

using namespace std;

template <typename T>
class Counter
{
    T element;
  public:
    Counter(T arg) : element (arg) {}

    T increase () 
    {
      return ++element;
    }
};

template <typename T>
T sum(const T *array, int length)
{
    T result = 0;
    for (int i = 0; i < length; i++)
        result += array[i];

    return result;
}


int main () 
{

  Counter<int> ac (7);
  Counter<float> fc (0.3);

  cout << ac.increase() << endl;
  cout << fc.increase() << endl;

  int a[] = {0, 1, 3, 4, 5};
  float f[] = {0.4, 2.1, 5.2, 0.2, 0.3};

  cout << sum(a, 5) << endl;
  cout << sum(f, 5) << endl;

  return 0;
}
