/* A program to get Students' GPAs. */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define NAMELGTH 20

struct StudentRecord {
  char name[NAMELGTH];
  int id;
  float gpa;
};

int main() {
  // Set up some funtion prototypes
  void printStudent(StudentRecord);
  StudentRecord getStudent();
  
  // Create the first Super Programmer Student
  StudentRecord TESCStudent;
  strncpy(TESCStudent.name, "SuperProgrammer", NAMELGTH);
  TESCStudent.id = 1234;
  TESCStudent.gpa = 4.0;

  // and print his details
  printStudent(TESCStudent);

  // Request a student be entered from the keyboard
  StudentRecord a = getStudent();
  printStudent(a);
}

void printStudent(StudentRecord student) {
  // Print the student's name
  cout << "The student named " << student.name
    // Print it's id
       << " has an id of " << student.id
    // Print it's GPA, always showing two digits after the decimal point.
       << " and a GPA of " << setprecision(3) << showpoint << student.gpa << endl;
}

StudentRecord getStudent() {
  string studentName;
  StudentRecord student;
  float studentGpa;

  // Ask for the student's name
  cout << "Please enter student's name: ";
  cin >> studentName;

  // Check that it is able to fit in the char array, and crop it if it's too
  // long
  if(studentName.length() > NAMELGTH) {
    cout << "The name you entered was too long, and has been cropped to 20 characters long." << endl;
  }
  for(int i = 0; i<NAMELGTH; i++) {
    student.name[i] = studentName[i];
  }

  // Ask for the student's id
  cout << "Please enter student's id: ";
  cin >> student.id;

  // Ask for the student's GPA
  cout << "Please enter student's GPA: ";
  cin >> studentGpa;

  // Check that the GPA is positive, and less than 4
  if(studentGpa > 4) {
    cout << "You entered a GPA greater than 4, and the GPA has been set to 4,"
      " the maximum possible GPA" << endl;
    student.gpa = 4;
  } else if (studentGpa < 0) {
    cout << "You entered a GPA of less than 0, and the GPA has been set to 0, "
      "the minimum possible GPA" << endl;
    student.gpa = 0;
  } else {
    student.gpa = studentGpa;
  }
  

  return student;
}
