#include <iostream>
#include <fstream>

#include "StackType.h"


using namespace std;

int main()
{
  ifstream inFile;       // file containing operations
  string inFileName;     // input file external name

  StackType stack;

  // Prompt for file name, read file name, and prepare file
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  int c;
  ItemType item;
  bool error = false;

  while(inFile && !error) {
    c = inFile.get();
    switch(c){
      // Find opening symbols
    case ((int)'{'):
    case ((int)'('):
    case ((int)'['):
      item.Initialize(c);
    stack.Push(item);
    break;
    // Special case for /*
    case ((int)'/'):
      if( ((int)'*') == (c = inFile.get()) ) {
	item.Initialize(c);
	stack.Push(item);
      }
      break;
      // Find closing symbols, and check them
    case ((int)'}'):
      item.Initialize((int)'{');
      try {
	if(item.ComparedTo(stack.Top()) != EQUAL  )
	  error = true;
	else {
	  stack.Pop();
	}
      }
      catch(EmptyStack e) {
	error = true;
      }
      break;
    case ((int)')'):
      item.Initialize((int)'(');
      try {
	if(item.ComparedTo(stack.Top()) != EQUAL  )
	  error = true;
	else {
	  stack.Pop();
	}
      }
      catch(EmptyStack) {
	error = true;
      }
      break;
    case ((int)']'):
      item.Initialize((int)'[');
      try {
	if(item.ComparedTo(stack.Top()) != EQUAL  )
	  error = true;
	else {
	  stack.Pop();
	}
      }
      catch(EmptyStack) {
	error = true;
      }
      
      break;
    case ((int)'*'):
      if( ((int)'/') == (c = inFile.get()) ) {
	item.Initialize((int)'*');
	try {
	  if(item.ComparedTo(stack.Top()) != EQUAL  )
	    error = true;
	  else {
	    stack.Pop();
	  }
	}
	catch(EmptyStack) {
	  error = true;
	}
      }
      break;
    default:
      break;
    }
    
  }
  if(error)
    cout << "The input file is not balanced." << endl;
  else
    cout << "The input file is balanced" << endl;

}
