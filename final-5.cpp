/* Final project 5 */

#include <iostream>
#include <stdexcept>
using namespace std;

// The square class
class square {
public:
  square(float s = 1) {
    if(s <= 0)
      throw invalid_argument("Side cannot be less than or equal to 0");
    else
      side = s;
  }

  float calcVal() {
    return side * side;
  }

protected:
  float side;
};

// The cube class, using public inheritence, so it can access the protected variable
class cube : public square {
public:
  cube(float s = 1) {
    if(s <= 0)
      throw invalid_argument("Side cannot be less than or equal to 0");
    else
      side = s;
  }

  float calcVal() {
    return side * square::calcVal();
  }
};

int main() {
  // A square and a cube
  square a(5.4);
  cube b(5.4);

  cout << "Area of square a is: " << a.calcVal() << endl;
  cout << "Volume of cube b is: " << b.calcVal() << endl;
}
