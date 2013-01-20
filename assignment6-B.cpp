/* Here we go */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const unsigned int numLetters = 26;

int main() {

  unsigned int letters[numLetters], lines;

  void initialiseVars(unsigned int *, unsigned int &);
  void copyTxt(ifstream &, ofstream &, unsigned int *, unsigned int &);
  void writeTotal(unsigned int *, unsigned int &);

  ifstream inFile( "textinput" , ios::in );

  if( !inFile ) {
    cerr << "Input file could not be opened" << endl;
    exit(1);
  }

  ofstream outFile( "textoutput", ios::out );

  if( !outFile ) {
    cerr << "Output file could not be opened" << endl;
    exit(2);
  }

  initialiseVars(letters, lines);
  
  copyTxt(inFile, outFile, letters, lines);
  for(int i = 0; i < numLetters; i++) {
    cout << (char) (i+97) << ":" << letters[i] << "  ";
  }
  cout << "lines:" << lines;
  cout << endl;
}

void initialiseVars( unsigned int *letters, unsigned int &lines) {
  for(int i = 0; i < numLetters; i++) {
    letters[i] = 0;
  }
  lines = 0;
}

void copyTxt( ifstream &infile, ofstream &outfile, unsigned int *letters, unsigned int &lines) {
  
  void countChar(int, unsigned int *, unsigned int & );

  infile.seekg( 0 );
  int c = infile.get();
  while( !infile.eof() ) {
    countChar(c, letters, lines);
    outfile.put(c);
    c = infile.get();
  }
}

void countChar(int c, unsigned int *letters, unsigned int &lines) {
  if(c == 10) {
    ++lines;
  } else if(c >= 97 && c <= 122) {
    ++letters[c - 97];
  } else if(c >= 65 && c <= 90) {
    ++letters[c - 65];
  }

}

void writeTotal(unsigned int *letters, unsigned int &lines) {
  cout << "writing" << endl;
}
