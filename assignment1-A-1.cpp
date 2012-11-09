/* Here we go */

#include <iostream>
using namespace std;

int main() {
  int i;
  double max = 0, num;
  double larger(double, double);

  cout << "This program will take 15 integers, and then print out the largest.\n";
  for(i=0; i<15; i++) {
    cout << "Please enter an integer: ";
    cin >> num;
    max = larger(max, num);

  }
  cout << "The largest number is ";
  cout << max;
  cout << "\n";
  
}

double larger(double x, double y) {
  if(x<y)
    return y;
  else
    return x;
}
