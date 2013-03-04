#include <iostream>
using namespace std;

void Increment(int &);
int main()
{
  
  for(int count = 1; count < 10;) {
    cout << " The number after " << count;
    count++;
    cout << " is " << count << endl;
  }
  return 0;
}
