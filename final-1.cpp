/* Here we go */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal {
public:
  Animal(int p = 1) {
    position = p;
  }
  int getPosition() {
    return position;
  }

  virtual void move() {
    // Implement in each animal
  }
  
  int getRand() {
    return rand () % 10;
  }
private:
  
  int position;
};  

class Rabbit : public Animal {
public:
  virtual void move() {
    int n = getRand();
    if(n <= 4) {
      cout << "fast plod" << endl;
    } else if( n <= 6) {
      cout << "slip" << endl;
    } else if( n <= 9) {
      cout << "slow plod" << endl;
    }
  }
};

class Tortoise : public Animal {
public:
  virtual void move() {
    int n = getRand();
    if(n <= 1) {
      cout << "sleep" << endl;
    } else if( n <= 3) {
      cout << "big hop" << endl;
    } else if( n <= 4) {
      cout << "big slip" << endl;
    } else if( n <= 7) {
      cout << "small hop" << endl;
    } else if( n <= 9) {
      cout << "small slip" << endl;
    }
  }
};


int main() {
  srand(time( 0 ));
  Tortoise tortoise;
  Rabbit rabbit;
  Animal *t = &tortoise, *r = &rabbit;

  cout << "Bang! Off they go!" << endl;
  t->move();
  r->move();

}
