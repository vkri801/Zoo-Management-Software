#include "Monkey.hpp"

using namespace std;

// the constructor is set up to give values to the animal's Daily Food Intake and hunger level.
Monkey::Monkey() {
	Daily_Food_Intake = 800;
	hunger_level = Daily_Food_Intake;

}

// Function returns ENUM type of animal without making any changes.
Animal::AnimalType Monkey::type() const {

    return AT_MONKEY;
}


// a function that returns a bool based on if animal likes food or not.
bool Monkey::likesFood(const Food& food) const {
	//each animal has a different implementation depending on the food they like with an
		//if statement comparing the food's name to the food the animal will like
	if (food.getName() == "banana" || food.getName()== "watermelon" || food.getName() == "mealworms"){
		return true;
		}
		else {
			return false;
		}
}


