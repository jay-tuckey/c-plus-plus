/* A program to sort letters */

#include <iostream>
#include <string>
using namespace std;

#define NUMC 10

int main() {
	string input;
	char letters[NUMC], c = 127;
	
	char firstLetter(char, char);
	
	cout << "Enter 10 letters" << endl;
	for(int i = 0; i< NUMC; i++) {
		cout << "Please enter a letter: ";
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
