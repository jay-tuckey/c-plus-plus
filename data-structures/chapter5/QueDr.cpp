// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include "QueType.h"

using namespace std;
int GetLength(QueType&);

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed

  int number;
  int numCommands;

  char item;
  QueType queue(100), queue2(100);


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;
  if (!inFile)
    {
      cout << "file not found" << endl;
      exit(2);
    }
  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
    { 
      if (command == "LogCommand") {
	outFile << "Logging Test Command" << endl;
      }
      else if (command == "AddItem") {
	inFile >> item;
	outFile << "Adding item: " << item << endl;
	queue.Enqueue(item);
      }
      else if (command == "Print") {
	outFile << "Printing Queue: ";
	while(!queue.IsEmpty()) {
	  queue.Dequeue(item);
	  queue2.Enqueue(item);
	  outFile << item;
	}
	outFile << endl;
	while(!queue2.IsEmpty()) {
	  queue2.Dequeue(item);
	  queue.Enqueue(item);
	}
      }
      else if (command == "GetLength") {
	outFile << "Current Length is " << GetLength(queue) << endl;
      }
      else
	cout << command << " is not a valid command." << endl;
      numCommands++;
      cout <<  " Command number " << numCommands << " completed." 
	   << endl;
      inFile >> command;
    };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}

int GetLength(QueType& queue) {
  QueType queue2;
  int count;
  ItemType item;

  while(!queue.IsEmpty()) {
    queue.Dequeue(item);
    queue2.Enqueue(item);
    count++;
  }
  while(!queue2.IsEmpty()) {
    queue2.Dequeue(item);
    queue.Enqueue(item);
  }

  return count;
}
