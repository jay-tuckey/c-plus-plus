/* A program to sort letters */

#include <iostream>
#include <string>
using namespace std;

#define NUMC 10

int main() {
	// Create a string to filter input, and an array of letters.
	string input;
	char letters[NUMC], c = 127;
	
	// Function prototype
	char firstLetter(char, char);
	
	// Request the user to enter ten letters
	cout << "Enter 10 letters" << endl;
	for(int i = 0; i< NUMC; i++) {
		cout << "Please enter a letter: ";
		// Input the letters into a string then take the first letter
		// from the string and add it to the array. This prevents
		// newlines, and multiple entered characters from skipping
		// input opportunities
		cin >> input;
		letters[i] = input[0];
	}
	cout << endl;
	
	for(int i = 0; i < NUMC; i++) {
		c = firstLetter(c, letters[i]);
	}
	
	cout << "The first letter is: " << c << endl;
	
}

char firstLetter(char x, char y) {
	if(x <= y)
		return(x);
	else
		return(y);
}
