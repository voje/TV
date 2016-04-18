#include <iostream>
#include <string>
#include <cstring> // C string support
#include <cstdio>

int main()
{
  const char* cstring = "This is a C string";
  std::string cppstring("This is a C++ string");

  // C strings can be in most cases automatically converted to C++
  std::cout << cppstring << std::endl;
  std::cout << cstring << std::endl;

  printf("%s\n", cstring);
  printf("%s\n", cppstring.c_str()); // C++ string has to be manually converted to C

  return 0;
}


