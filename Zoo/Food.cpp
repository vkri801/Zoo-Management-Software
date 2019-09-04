#include "Food.hpp"
#include <string>

using namespace std;

Food::Food(const string& new_name, double new_cost, unsigned int new_energy) {
	//The constructor creates an instance of a food with set parameters via inputs for this function.
	/*this-> is used to signify the variable on left is referring to the particular instance.
	 *It is however not needed due to the different variable names. */
	 	this->name = new_name;
	    this->Cost = new_cost;
	    this->Energy = new_energy;
	    // Quantity is set to 0 to signify initial quantity of a particular food item as 0
	    this->Quantity = 0;
}

// The getter functions are required due to variables being encapsulated as private in the class declarations.
string Food::getName() const {

	//It's function is to simply return the name of a food item.
    return this->name;
}

double Food::getCost() const {
    // A getter function which returns Cost of food item.
    return this->Cost;
}

unsigned int Food::getQuantity() const {
    // A getter function which returns the current Quantity of a particular food item.
    return this->Quantity;
}

unsigned int Food::getEnergy() const {
    //A getter function which returns the Energy of a particular food item.
    return this->Energy;
}

unsigned int Food::consume(unsigned int count) {
    /* A function which decreases value of Quantity depending on the value of count which is food
	 *Quantity that has been consumed.*/

	/*An if statement is set up to check if food required to be consumed (count) is more than Quantity
	 *If count is more, Quantity is set to zero. The amount of food consumed which
	 *was Quantity value before function was called, is returned.
	 */
	if (getQuantity()<count){
		count = Quantity;
		Quantity = 0;
		return count;
	}
	/* If count is not more than Quantity, Quantity is updated by subtracting amount consumed
	 * and count is returned.*/

	else {
		Quantity -= count;
		return count;
	}
}

//note: Changed input variable name from "quantity" to "count"
void Food::purchase(unsigned int count) {
    //Function increases value of Quantity to signify purchase of food items by amount count.
	Quantity += count;
}
