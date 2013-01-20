/* Here we go */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  int c, wordCounter = 0;
  bool wordStarted;

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
