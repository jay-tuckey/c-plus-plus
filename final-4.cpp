/* Here we go */

#include <iostream>
using namespace std;

// Template for switching two numbers
template <typename T>
void switchNumbers(T &first, T &second) {
  T temp = second;
  second = first;
  first = temp;
}

int main() {
  // Declare a bunch of variables to test with
  int a = 2, b = 7;
  float c = 7.9284, d = 83.59;
  double e = 7249238942, f = 1.999933;
  long g = 190238, h = 1839;

  // Print all the variables
  cout << "A = " << a << "   B = " << b <<
    "   C = " << c << "   D = " << d << endl <<
    "E = " << e << "   F = " << f <<
    "   G = " << g << "   H = " << h << endl;

  // Switch all the variables
  cout << "Running switchNumbers() on all the variables." << endl;
  switchNumbers(a, b);
  switchNumbers(c, d);
  switchNumbers(e, f);
  switchNumbers(g, h);

  // Print all the variables again
  cout << "A = " << a << "   B = " << b <<
    "   C = " << c << "   D = " << d << endl <<
    "E = " << e << "   F = " << f <<
    "   G = " << g << "   H = " << h << endl;
  
  
}
