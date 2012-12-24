/* Here we go */

#include <iostream>
using namespace std;

class personType{
public:
	personType() {
		firstName = "NotSet";
		lastName = "NotSet";
	}
	
	personType(string first, string last) {
		firstName = first;
		lastName = last;
	}
	
	void setFirstName(string name) {
		firstName = name;
	}
	void setLastName(string name) {
		lastName = name;
	}
	
	void printName() {
		cout << firstName << " " << lastName << endl;
	}
	
private:
	string firstName;
	string lastName;
	
};

int main() {
	personType bob;
	personType richard("Richard", "Dominique");
	bob.printName();
	richard.printName();
	
}
