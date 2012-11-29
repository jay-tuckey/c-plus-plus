/* A program to print out the english word for a number. */

#include <iostream>
using namespace std;

int main() {
  int a;
  cout << "This Program will take a number, and print out the english word corresponding to the character.\n";

  cout << "Enter a digit between 0 and 9, then press enter: ";
  /* Accepting a char, so that a character won't be equal to 0 */
  cin >> a;
  
  /* Check that the entered character is an acceptable number */
  if(a >= 0 && a <= 9) {
    cout << "You entered a ";
    /* Choose a word to answer with */
    switch(a) { 
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
    }
    cout << ".\n";
  }
  else {
    cout << "You entered an invalid character.\n";
  }
}
