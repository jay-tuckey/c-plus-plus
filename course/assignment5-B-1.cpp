/* Here we go */

#include <iostream>
using namespace std;

template< typename T >
T myAbs( const T num ) {
  if(num > 0)
    return num;
  else
    return 0 - num;
}

int main() {
  int a = 5, b = -14, c = 0;
  float d = 16.2, e = -15, f = -0.0;
  double g = 1000.749, h = -2749.8130, i = -0;

  cout << "The absolute values of 5, -14, and 0 are: ";
  cout << myAbs(a) << "   " << myAbs(b) << "   " << myAbs(c) << endl;

  cout << "The absolute values of 16.2, -15, and -0.0 are: ";
  cout << myAbs(d) << "   " << myAbs(e) << "   " << myAbs(f) << endl;

  cout << "The absolute values of 1000.749, -2749.8130, and -0 are: ";
  cout << myAbs(g) << "   " << myAbs(h) << "   " << myAbs(i) << endl;

  cout << "Please enter a number: ";
  float j;
  cin >> j;
  cout << "The absolute value of " << j << " is: " << myAbs(j) << endl;
}
