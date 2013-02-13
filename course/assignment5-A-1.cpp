/* Here we go */

#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

// A function to convert numbers to strings;
template <typename T>
string NumberToString ( T Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}

// The fraction class
class Fraction {
public:
  // First constructor. You can either call it with a numerator and denominator,
  // just with a numerator, or empty, in which case the number is 1.
  // The assignment asked for 3 constructors, but I have only put in 1, since
  // this method of designing the constructor performs the function of all three of
  // the constuctor types that were requested.
  Fraction(int n = 1, int d = 1) {
      setNumerator(n);
      setDenominator(d);
      
  }
  
  void setNumerator(int n) {
    numerator = n;
  }
  
  int getNumerator() {
    return numerator;
  }

  void setDenominator(int d) {
    if(d != 0)
      denominator = d;
    else
      throw invalid_argument("Denominator must not be equal to 0");
  }
  
  int getDenominator() {
    return denominator;
  }

  float getFractionAsFloat() {
    return numerator/denominator;
  }

  string toString() {
    string tmp;
    tmp = NumberToString(numerator) + "/" + NumberToString(denominator);
    return tmp;
  }

  void readFraction() {
    int n, d;
    cout << "Please enter numerator: ";
    cin >> n;
    setNumerator(n);
    cout << "and denominator: ";
    cin >> d;
    setDenominator(d);

  }
  
  Fraction operator*( const Fraction &f ) const {
    Fraction tmp;
    tmp.setNumerator(numerator * f.numerator);
    tmp.setDenominator(denominator * f.denominator);
    return tmp;
  }

private:
  int numerator;
  int denominator;
};

int main() {
  cout << "Creating the fractions 3/4, 5/6, 1/2, and 1." << endl;
  Fraction f1(3,4), f2(5,6), f3(1,2), f4(1);
  cout << "The results of the following multiplications are: " << endl;

  // Using multiplication operator directly
  cout << "3/4 * 5/6 = " << (f1 * f2).toString() << endl;
  cout << "3/4 * 1 = " << (f1 *f4).toString() << endl;

  // Now demonstrating the multiplication operator using assignment
  Fraction f7, f8;
  f7 = f2 * f3;
  f8 = f2 * f4;
  cout << "5/6 * 1/2 = " << f7.toString() << endl;
  cout << "5/6 * 1 = " << f8.toString() << endl;

  cout << "Now enter two fractions, which will be multplied." << endl;
  Fraction f5, f6;
  try {
    cout << "Enter 1st fraction. ";
    f5.readFraction();
    cout << "Enter 2nd fraction. ";
    f6.readFraction();
    cout << f5.toString() << " * " << f6.toString() << " = " << (f5*f6).toString() << endl;
  }
  catch ( exception &e )
    {
      cerr << "Exception occurred: " << e.what() << endl;
    }

}
