#include "Lion.hpp"



using namespace std;
// the constructor is set up to give values to the animal's Daily Food Intake and hunger level.
Lion::Lion() {
	Daily_Food_Intake = 2200;
	hunger_level = Daily_Food_Intake;
}
// Function returns ENUM type of animal without making any changes.
Animal::AnimalType Lion::type() const {

    return AT_LION;
}




// a function that returns a bool based on if animal likes food or not.

bool Lion::likesFood(const Food& food) const {
	//each animal has a different implementation depending on the food they like with an
		//if statement comparing the food's name to the food the animal will like
	if (food.getName() == "steak" || food.getName()== "mouse" || food.getName() == "fish"){
		return true;
		}
		else {
			return false;
		}

}


