/* Here we go */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const unsigned int numLetters = 26;

int main() {
  // Create the variables
  unsigned int letters[numLetters], lines;

  // Function prototypes
  void initialiseVars(unsigned int *, unsigned int &);
  void copyTxt(ifstream &, ofstream &, unsigned int *, unsigned int &);
  void writeTotal(unsigned int *, unsigned int &);

  // Open input file
  ifstream inFile( "textinput" , ios::in );

  if( !inFile ) {
    cerr << "Input file could not be opened" << endl;
    exit(1);
  }

  // Open output file
  ofstream outFile( "textoutput", ios::out );

  if( !outFile ) {
    cerr << "Output file could not be opened" << endl;
    exit(2);
  }

  // Initialise the variables
  initialiseVars(letters, lines);
  
  // Copy the text accross, and count the characters.
  copyTxt(inFile, outFile, letters, lines);

  // Output the number of numbers and letters in the file.
  for(int i = 0; i < numLetters; i++) {
    cout << (char) (i+97) << ":" << letters[i] << "  ";
  }
  cout << "lines:" << lines;
  cout << endl;

  // Output the results to a file
  writeTotal(letters, lines);
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
  cout << "Writing Results to results.txt" << endl;

  // Open results file0
  ofstream resultsFile("results.txt", ios::out);
  if( !resultsFile ) {
    cerr << "Results file could not be opened" << endl;
    exit(3);
  }

  // Output the number of numbers and letters in the file to results.txt
  for(int i = 0; i < numLetters; i++) {
    resultsFile << (char) (i+97) << ":" << letters[i] << "  ";
  }
  resultsFile << "lines:" << lines << endl;
}
