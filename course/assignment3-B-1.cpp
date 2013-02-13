/* A program to print the area and circumference of a field

   I've put the whole program into one file, to make it easy to move and stuff,
   even though the book suggests using multiple files */

#include <iostream>
#include <stdexcept>
using namespace std;

// Declare the class
class Plot {
public:
  Plot(float length, float width) {
    setLength(length);
    setWidth(width);
  }
  
  void setLength(float l) {
    if(l > 0) {
      length = l;
    } else {
      throw invalid_argument("length must be greater than 0");
    }
  }
  
  void setWidth(float w) {
    if(w > 0) {
      width = w;
    } else {
      throw invalid_argument("width must be greater than 0");
    }
  }
  
  float calculateArea() {
    return(width * length);
  }

  float calculateCircumference() {
    return( (width + length) * 2);
  }

  void printValues() {
    cout << "The area of the field with length " << length << " and width " <<
      width << " is " << calculateArea() << " and the "
      "circumference of the field is " << calculateCircumference() << "." << 
      endl;
  }

private:
  float length;
  float width;
  
 
};


int main() {
  
  // Create a field of small size
  try {
    Plot p(4, 19);
    p.printValues();

  } catch ( invalid_argument &ex ) {
    cout << "An exception occurred: " << ex.what() << endl;
  }

  // One with larger size
  try {
    Plot p2(86, 93);
    p2.printValues();
  } catch ( invalid_argument &ex ) {
    cout << "An exception occurred: " << ex.what() << endl;
  }

  // One to demonstrate floating point field sizes
  try {
    Plot p3(2.04, 0.67);
    p3.printValues();
  } catch ( invalid_argument &ex ) {
    cout << "An exception occurred: " << ex.what() << endl;
  }

  // And one to show error checking
  try {
    Plot abc(0, 2);
    abc.printValues();
  } catch ( invalid_argument &ex ) {
    cout << "An exception occurred: " << ex.what() << endl;
  }

  // And finally, the one of the size required by the assignment
  try {
    Plot field(7, 9);
    field.printValues();
  } catch ( invalid_argument &ex ) {
    cout << "An exception occurred: " << ex.what() << endl;
  }

    
  
}



