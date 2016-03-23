#include <iostream>
#include <algorithm>

using namespace std; // Importing namespace

int main()
{
  int a1[10] = {0, 1, 3, 4};

  int len = 10;
  int *a = new int[len];

  // Normal, long way to fill array
  for (int i = 0; i < len; i++)
  {
    a[i] = 0;
  }

  fill(a, a + len, 0); // C++ way to fill array

}
