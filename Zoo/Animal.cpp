#include "Animal.hpp"

Animal::~Animal() {
}

Animal::AnimalType Animal::type() const {
	// the default constructor if a specific valid type isn't specified is AT_INVALID.
    return AT_INVALID;
}
// The next two functions are inherited by each animal subclass therefore the declarations
//and implementations were removed within those scripts.

unsigned int Animal::hungerLevel() const {
// a getter function which returns the value of hunger level for an individual particular animal
	return hunger_level;
}

void Animal::resetToHungry() {
	// no input or output
	//a function that resets the hunger level of an animal, can be called daily to reset level.
	hunger_level = Daily_Food_Intake;
}

bool Animal::likesFood(const Food& food) const {
	//the default if the function within a subclass isn't implemented.
    return false;
}

//The feed function is also inherited by animal subclasses.
unsigned int Animal::feed(Food& food) {
	// the input is a class type Food.
	//A condition is set up to test if animal likes the food input specified using likesFood function.
	if (likesFood(food)){
		// if animal likes food, it will eat an amount specified. The equation
		// adds an integer quotient to either 1 or 0 depending on if there is a remainder.
		count = (hunger_level / food.getEnergy())+ ((hunger_level % food.getEnergy()) != 0);
		if (count< food.getQuantity()){
			// if the count is less than the quantity, food is consumed appropriate amount using
			//consume function and hunger level is set to 0 while count is returned.
			    	food.consume(count);
			    	hunger_level = 0;
			    	return count;
			    	}
		else {
			//if count is more than quantity, there is not enough food.
			//The food available is consumed and hunger level is decreased by appropriate amount.
			count = food.getQuantity();
			food.consume(food.getQuantity());
			// new hunger level is calculated from count multiplied with energy available from food.
			hunger_level -= count*food.getEnergy();
			return count;
		}
	}
	else return 0;
}

