/* Final project 1 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// A parent class for the two animals
class Animal {
public:
  Animal(int p = 1) {
    position = p;
    won = false;
  }
  int getPosition() {
    return position;
  }

  virtual void move() {
    // Implement in each animal
  }
  
  // Try to move, but don't go back further than square 1
  void tryMove(int d) {
    if(position + d > 1)
      position += d;
    else
      position = 1;

  }

  // Generate a random step
  int getRand() {
    return rand () % 10;
  }

  // Check if the animal has won yet
  void checkWin() {
    if(position >= 70)
      won = true;
  }

  // Variable to indicate if they have won the race
  bool won; 
private:
  
  int position;
};  // End of class Animal

class Rabbit : public Animal {
public:
  virtual void move() {
    int n = getRand();
    cout << "The rabbit ";
    if(n <= 1) {
      cout << "falls asleep.";
    } else if( n <= 3) {
      tryMove(9);
      cout << "has a big hop.";
    } else if( n <= 4) {
      tryMove(-12);
      cout << "has a big slip.";
    } else if( n <= 7) {
      tryMove(1);
      cout << "has a small hop.";
    } else if( n <= 9) {
      tryMove(-2);
      cout << "has a small slip.";
    }

    cout << " It is at square " << getPosition() << endl;
    checkWin();
  }
}; // End of class Rabbit

class Tortoise : public Animal {
public:
  virtual void move() {
    int n = getRand();
    cout << "The tortoise makes a ";
    if(n <= 4) {
      tryMove(3);
      cout << "fast plod.";
    } else if( n <= 6) {
      tryMove(-6);
      cout << "slip.";
    } else if( n <= 9) {
      tryMove(1);
      cout << "slow plod.";
    }
    cout << " It is at square " << getPosition() << endl;
    checkWin();
  }
}; // End of class Tortoise


int main() {
  // Make sure that the random numbers are new each game
  srand(time( 0 ));
  Tortoise tortoise;
  Rabbit rabbit;
  Animal *t = &tortoise, *r = &rabbit;

  // Start race
  cout << "Bang! Off they go!" << endl;
  while(!r->won && !t->won) {   // Keep going while neither has finished
    t->move();
    r->move();
    if(t->getPosition() == r->getPosition())  // Display BUMP if the both land on the same square
      cout << "BUMP!" << endl;
    cout << "Press Enter to continue";
    cin.get();
  }
  cout << endl;
  if(r->won == t->won)  // Check if they have drawn the race
    cout << "Tie score -- no winner!" << endl;
  else if(r->won)
    cout << "Yay! The rabbit won! He hops the fastest!" << endl;
  else
    cout << "Woo-hooo! Slow and steady wins the race! Congratulations, tortoise!" << endl;

}
