/* A program to calculate revenue values */

#include <iostream>
using namespace std;

// The Revenue class
class Revenue {
public:
	Revenue(int startDemand = 1, int startPrice = 1) {
		demand = startDemand;
		price = startPrice;
		
	}
	
	float calcRevenueValue() {
		return(demand*price);
	}
	
private:
	float demand, price;
};


int main() {
	// Declare a revenue object with demand 2000 and price 2
	Revenue revenue1(2000, 2);
	
	// Print the revenue value of the object
	cout << "The revenue value is: " << revenue1.calcRevenueValue() <<
			endl;
}


