#include <iostream>
using namespace std;

class A{
  friend class B;
private:
  int a;
};

class B{
public:
  int getA(A & aclass) {
    return aclass.a;
  }
private:
  int b;  
};

main() {
  
}
