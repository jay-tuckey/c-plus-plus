/* A program to convert numbers to words. */

#include <iostream>
using namespace std;

int main() {
  int c;
  cout << "Please enter a number between 0 and 11: ";
  cin >> c; /* Take a value from the keyboard */
  cout << "You entered a ";
  /* Choose an output. */
  switch(c) {
  case 0:
    cout << "zero";
    break;
  case 1:
    cout << "one";
    break;
  case 2:
    cout << "two";
    break;
  case 3:
    cout << "three";
    break;
  case 4:
    cout << "four";
    break;
  case 5:
    cout << "five";
    break;
  case 6:
    cout << "six";
    break;
  case 7:
    cout << "seven";
    break;
  case 8:
    cout << "eight";
    break;
  case 9:
    cout << "nine";
    break;
  case 10:
    cout << "ten";
    break;
  case 11:
    cout << "eleven";
    break;
  default:
    cout << "The number you entered was not in the valid range of values that this program understands.\n";
    return 1;
    break;
  }
  /* And print a little formatting */
  cout << ".\n";



}
