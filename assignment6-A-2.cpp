/* Here we go */

#include <iostream>
using std::cout;
using std::endl;

namespace globalType {
  const int n = 5;
  const float rate = 4.68;
  int count = 16;
  void printResult();

} // End namespace globalType

// Global variables
const int n = 2;
const float rate = 5.77;
int count = 13;

int main() {
  

  cout << "From main:" << endl <<
    "n = " << n << endl <<
    "rate = " << rate << endl <<
    "count = " << count << endl <<
    "::n = " << ::n << endl <<
    "::rate = " << ::rate << endl <<
    "::count = " << ::count << endl;

  globalType::printResult();
}

void globalType::printResult() {
  cout << "From printResult function:" << endl <<
    "n = " << n << endl <<
    "rate = " << rate << endl <<
    "count = " << count << endl <<
    "::n = " << ::n << endl <<
    "::rate = " << ::rate << endl <<
    "::count = " << ::count << endl;
}
