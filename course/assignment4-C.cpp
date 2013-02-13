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

class PolyTerm {
public:
  PolyTerm(int coef = 0, int exp = 0) {
    setCoefficient(coef);
    setExponent(exp);
  }
  
  void setCoefficient(int coef) {
    coefficient = coef;
  }
  
  int getCoefficient() {
    return coefficient;
  }
  
  void setExponent(int exp) {
    exponent = exp;
  }

  int getExponent() {
    return exponent;
  }

  string toString() {     // A function to convert the object into a string
    string toReturn = "";
    toReturn += NumberToString(coefficient);
    toReturn += "X^";
    toReturn += NumberToString(exponent);
    return toReturn;
  }

private:
  int coefficient;
  int exponent;
};

class Polynomial {
public:
  Polynomial(int plysize = 10, int firstTermExp = 10) {
    if( plysize >0 ) // Check the size of the polynomial
      size = plysize;
    else
      throw invalid_argument("Polynomial must have at least one term" );
    
    start = firstTermExp;
    ptr = new PolyTerm[ size ]; // Create space for the terms
    for(int i = 0; i<size; i++) {
      setTermExp(i, 0, firstTermExp - i);
    }
  }

  ~Polynomial() {
    delete [] ptr;
  }

  Polynomial operator+( const Polynomial &poly ) const {
    // Check that the polynomials are the same size, and start with the same exponential
    if(size != poly.size )
      throw invalid_argument("Unmatched sizes");
    if(start != poly.start )
      throw invalid_argument("Exponents not aligned");

    // Create a polynomial that will contain the results of the addition
    Polynomial p(size, start);
    // Add all terms
    for(int i = 0; i < size; i++) {
      p.setTerm(i, ptr[i].getCoefficient() + poly.ptr[i].getCoefficient());
    }
    return p;
  }

  Polynomial operator-( const Polynomial &poly ) const {
    // Check that the polynomials are the same size, and start with the same exponential
    if(size != poly.size )
      throw invalid_argument("Unmatched sizes");
    if(start != poly.start )
      throw invalid_argument("Exponents not aligned");

    // Create a polynomial that will contain the results of the subtraction
    Polynomial p(size, start);
    // Subtract all terms
    for(int i = 0; i < size; i++) {
      p.setTerm(i, ptr[i].getCoefficient() - poly.ptr[i].getCoefficient());
    }
    return p;
  }
  
  
  void setTerm(int term, int coef) {
    ptr[term].setCoefficient(coef);
  }

  int getSize() {
    return size;
  }

  PolyTerm getTerm(int term) {
    return ptr[term];
  }

  void printTerms() {
    cout << "Printing: ";
    for(int i = 0; i < size; i++) {
      PolyTerm a = getTerm(i);
      if(a.getCoefficient() != 0)   // Only print terms if they have a coefficient that is not 0
	cout << "  " << a.toString();
    }
    cout << endl;
  }
  
private:
  // A function to set up the exponents. Private, so it can't be called after the exponents have been set.
  void setTermExp(int term, int coef, int exp) {
    ptr[term].setCoefficient(coef);
    ptr[term].setExponent(exp);
  }
  
  int size;
  int start;
  PolyTerm *ptr;
};

int main() {
  Polynomial a, b(5), c(5,5);
  cout << "A: ";
  a.setTerm(0, 15);
  a.setTerm(2, 4);
  a.setTerm(4,8);

  a.printTerms();

  cout << "B: ";
  b.setTerm(0, 4);
  b.setTerm(2, 5);
  b.setTerm(4, 3);

  b.printTerms();

  cout << "C: ";
  c.setTerm(0, 5);
  c.setTerm(2,9);
  c.setTerm(4,9);

  c.printTerms();

  cout << "Trying to add two polynomials of different size." << endl;
  try{
    Polynomial d = a+c;
  } catch ( exception &e )
    {
      cerr << "Exception occurred: " << e.what() << endl;
    }

  cout << "Trying to add two polynomials with different exponents." << endl;
  try{
    Polynomial d = b+c;
  } catch ( exception &e )
    {
      cerr << "Exception occurred: " << e.what() << endl;
    }
  Polynomial e(4,6), f(4,6);

  cout << "E: ";
  e.setTerm(0, 3);
  e.setTerm(1, 5);
  e.setTerm(2, 5);
  e.setTerm(3,9);
  e.printTerms();
  
  cout << "F: ";
  f.setTerm(0, 3);
  f.setTerm(1, 5);
  f.setTerm(2, 5);
  f.setTerm(3,9);
  f.printTerms();

  cout << "Retrying the adding of polynomials, with same size and exponents." << endl;
  cout << "D: ";
  Polynomial d = e+f;
  d.printTerms();

  cout << "And subtracting F from D." << endl;
  cout<< "G: ";
  Polynomial g = d - f;
  g.printTerms();
}
