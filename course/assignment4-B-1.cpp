/* Here we go */

#include <iostream>
using namespace std;

class personType2{
public:
	
  personType2(string first = "NotSet", string last = "NotSet") {
    firstName = first;
    lastName = last;
  }
	
  void setFirstName(string name) {
    firstName = name;
  }

  string getFirstName() {
    return firstName;
  }

  void setLastName(string name) {
    lastName = name;
  }

  string getLastName(){
    return lastName;
  }
	
  void printName() {
    cout << firstName << " " << lastName << endl;
  }
	
private:
  string firstName;
  string lastName;
	
};

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

  string getFirstName() {
    return firstName;
  }

  void setLastName(string name) {
    lastName = name;
  }

  string getLastName(){
    return lastName;
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
  cout << "A person created with personType, using default constructor: ";
  bob.printName();
  bob.setFirstName("Bob");
  bob.setLastName("Carlile");
  cout << "Same person, after calling setFirstName() and setLastName(): ";
  bob.printName();
  cout << "A person created with personType, using second constructor: ";
  richard.printName();

  personType2 jane;
  personType2 jennie("Jennie", "Harolds");
  cout << "A person create with personType2, using default constructor arguments: ";
  jane.printName();
  jane.setFirstName("Jane");
  jane.setLastName("Jones");
  cout << "We can use getFirstName() and getLastName() to print the names seperately." << endl;
  cout << "First name is: "<< jane.getFirstName() << " and last name: " << jane.getLastName() << endl;

  cout << "A person created with personType2, using constructor with arguments: ";
  jennie.printName();
  
}
