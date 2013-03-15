// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include "unsorted.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedType& list);

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int number;
  ItemType item;
  UnsortedType list;
  bool found;
  int numCommands;


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
      if (command == "Log Command") {
	  inFile >> number; 
	  item.Initialize(number);
	  list.PutItem(item);
	  item.Print(outFile);
	  outFile << " is in list" << endl;
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


