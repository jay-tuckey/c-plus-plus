/* A program to pick an activity based on the temperature */

#include <iostream>
using namespace std;

int main() {
	int temp;
	
	void getTemp(int *);
	void printActivity(int);
	
	getTemp(&temp);
	printActivity(temp);
}

void getTemp(int *temp) {
	cout << "Please enter the temperature: ";
	cin >> *temp;
}

void printActivity(int temp) {
	cout << "Activity for today is ";

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
