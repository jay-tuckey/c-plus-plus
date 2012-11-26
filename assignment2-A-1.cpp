/* A program to add two arrays together, then print the output. */

#include <iostream>
using namespace std;

#define ARRAYLGTH 20

int main() {
  /* Create the arrays */
  int first_array[ARRAYLGTH] = {
    1,82,04,18,84,
    82,18,50,27,28,
    27,40,05,72,96,
    45,48,6,97,41 }, second_array[ARRAYLGTH] = {
    27,40,05,72,96,
    82,18,50,27,28,
    45,48,6,97,41,
    1,82,04,18,84 }, third_array[ARRAYLGTH], i;
  
  /* Prototype the function that will add the arrays */
  void addArrays(int *, int *, int *, int);
  /* And use it */
  addArrays(first_array, second_array, third_array, ARRAYLGTH);
  
  /* Print the results */
  cout << "Array1  +  Array2  =  Array3" << endl;
  for(i=0;i<ARRAYLGTH;i++) {
    cout.width(6);
    cout << first_array[i] << "  +  ";
    cout.width(6);
    cout << second_array[i] << "  =  ";
    cout.width(6);
    cout << third_array[i] << endl;
  }
  

  
}

void addArrays(int *firstArray, int *secondArray, int *resultArray, int length) {
  int i;
  for(i=0; i<length; i++)
    resultArray[i] = firstArray[i]+secondArray[i];
  
}
