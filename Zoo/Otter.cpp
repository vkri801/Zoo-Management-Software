#include "Otter.hpp"

using namespace std;

// the constructor is set up to give values to the animal's Daily Food Intake and hunger level.
Otter::Otter() {
	Daily_Food_Intake = 750;
	hunger_level = Daily_Food_Intake;
}

// Function returns ENUM type of animal without making any changes.
Animal::AnimalType Otter::type() const {

    return AT_OTTER;
}


// a function that returns a bool based on if animal likes food or not.
bool Otter::likesFood(const Food& food) const {
	//each animal has a different implementation depending on the food they like with an
		//if statement comparing the food's name to the food the animal will like
	if (food.getName() == "fish" || food.getName()== "mouse"){
		return true;
		}
		else {
			return false;
		}
}


