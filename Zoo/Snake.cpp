#include "Snake.hpp"

using namespace std;

// the constructor is set up to give values to the animal's Daily Food Intake and hunger level.
Snake::Snake() {
	Daily_Food_Intake = 250;
	hunger_level = Daily_Food_Intake;
}

// Function returns ENUM type of animal without making any changes.
Animal::AnimalType Snake::type() const {

    return AT_SNAKE;
}




// a function that returns a bool based on if animal likes food or not.
bool Snake::likesFood(const Food& food) const {
	//each animal has a different implementation depending on the food they like with an
		//if statement comparing the food's name to the food the animal will like
	if (food.getName() == "mouse" || food.getName()== "egg"){
		return true;
		}
		else {
			return false;
		}
}


