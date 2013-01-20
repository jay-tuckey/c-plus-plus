/* Final project 3 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  // Create some variables
  int c, wordCounter = 0;
  bool wordStarted;
  
  // Open input and output files
  ifstream infile("input.txt", ios::in);
  if(!infile) {
    cerr << "Input file failed to open" << endl;
    exit(1);
  }
  ofstream outfile("output.txt", ios::out);
  if(!outfile) {
    cerr << "Output file failed to open" << endl;
    exit(1);
  }

  // Loop through the file, adding up the words, and then printing the number when the word ends;
  c = infile.get();
  while(!infile.eof()) {
    if(c >= 97 && c <= 122) {
      wordStarted = true;
      wordCounter++;
    }
    else if(c >= 65 && c <= 90) {
      wordStarted = true;
      wordCounter++;
    } else {
      if(wordStarted) {
	wordStarted = false;
	outfile << wordCounter;
	wordCounter = 0;
      }
      outfile << (char) c;
    }
    c = infile.get();
  }
}
