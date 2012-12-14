/* A program to pick an activity based on the temperature */

#include <iostream>
using namespace std;

int main() {
	// Create a variable to store the temperature
	int temp;
	
	// Function prototypes
	void getTemp(int *);
	void printActivity(int);
	
	// Request the user to enter the temperature. Note that the address
	// of the variable is passed, so there in no need for the function
	// to return a value; the value is passed back using a pointer
	getTemp(&temp);
	
	// Print the activity to do
	printActivity(temp);
}

void getTemp(int *temp) {
	cout << "Please enter the temperature: ";
	cin >> *temp;
}

void printActivity(int temp) {
	cout << "Activity for today is ";

	// Choose an activity based on the temperature
	if(temp > 85)
		cout << "swimming";
	else if(temp > 70)
		cout << "baseball";
	else if(temp > 32)
		cout << "basketball";
	else
		cout << "nothing. Go home";
	cout << "." << endl;
}
