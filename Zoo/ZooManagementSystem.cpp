#include "ZooManagementSystem.hpp"

using namespace std;
//the constructor gives value to Balance which is an input double. It also gives value to the
//price of Adult tickets as well as children and the discount value.
//For the auto feed function, it also gives value to used variables.
ZooManagementSystem::ZooManagementSystem(double initialBalance) {
	Balance = initialBalance;
	Adult_Price = 14;
	Children_Price = 5;
	Family_Pass_Discount = 8;
	Success_Output = FR_SUCCESS;
	quantity = 0;
	hungriest_index = 0;
	food_index = 0;


}
//the destructor is not default since memory that was allocated to heap had to be deleted
ZooManagementSystem::~ZooManagementSystem() {
	//a for loop cycles through a pointer vector and deletes all instances
	for ( unsigned int i = 0; i < getAnimals().size(); i++ ){

	        delete Animal_vector[i];
	    }
	    Animal_vector.clear();
	    Food_vector.clear();
}

string ZooManagementSystem::author() {
//this function has no input and outputs a string with the author's ID.
    return "vkri801";
}

double ZooManagementSystem::getBalance() const {
//This is a getter function that returns the current balance of the zoo.
    return Balance;
}

//the admnitVisitors function takes in two inputs. It calculates the
//cost of admission for the visitors and increases balance accordingly.

double ZooManagementSystem::admitVisitors(unsigned int adults, unsigned int children) {
	double temp_admission_cost;
	// The temp_admission_cost is set up to give total price without discount.
	temp_admission_cost = adults*Adult_Price + children*Children_Price;

	// the while loop then calculates the discount capability and subtracts amount accordingly
	while ((adults >= 2) && (children >= 2)){
		temp_admission_cost -= Family_Pass_Discount;
		adults -=2;
		children -=2;

	}
	//the balance is then altered and the total cost returned.
	Balance += temp_admission_cost;
    return temp_admission_cost;
}

vector<Food> ZooManagementSystem::getFood() const {
//A getter function that returns a vector with the list of all food on stock.
    return Food_vector;
}

void ZooManagementSystem::addFood(const Food& new_food) {
	//this function takes in a class food type input and appends it to the vector mentioned
	//in getFood function
    Food_vector.push_back(new_food);
}
// this next function takes in three inputs. One of the inputs however is utilized as an output
// by a pointer reference.
bool ZooManagementSystem::purchaseFood(double& cost, unsigned int index, unsigned int quantity) {
	// the first line checks condition if index is within range while also
	// checking if there is enough balance to buy the quantity of food specified.
    if ((index < getFood().size()) && (getBalance() < (getFood()[index].getCost() * quantity))){
    	// if there isn't enough balance, cost is calculated and returned and the bool false to
    	//show that purchase wasn't made.
    	cost = getFood()[index].getCost() * quantity;
    	return false;
    }
    else if (index < getFood().size()){
    	// if there is enough balance, the cost is calculated and food is purchased
    	// balance is also changed accordingly and true is returned to show purchase made
    	cost = getFood()[index].getCost() * quantity;
    	Food_vector[index].purchase(quantity);
    	Balance -= cost;
    	return true;

    }
    else {
    	// if index input is invalid, false is returned with cost being 0.0.
    	cost = 0.0;
    	return false;
    }
}

vector<Animal*> ZooManagementSystem::getAnimals() const {
// this getter function returns a vector full of pointers to animal classes.
    return Animal_vector;
}

bool ZooManagementSystem::addAnimal(Animal::AnimalType new_animal_type) {
// this function adds a new animal to the vector mentioned in getAnimals function
	// if conditions are set up to check animal enum. If a match is made, a new instance
	// is made of that animal and appended onto the vector.
	// true is returned if a valid animal was inputed.
	if (new_animal_type == Animal::AT_MONKEY){
		//constructor for the animal class specified from input is called and a pointer initialized
		Animal *Animal_Pointer = new Monkey();
		Animal_vector.push_back(Animal_Pointer);
		return true;
	}
	else if (new_animal_type == Animal::AT_OTTER){
		//constructor for the animal class specified from input is called and a pointer initialized
		Animal *Animal_Pointer = new Otter();
		Animal_vector.push_back(Animal_Pointer);
		return true;
	}
	else if (new_animal_type == Animal::AT_SNAKE){
		//constructor for the animal class specified from input is called and a pointer initialized
		Animal *Animal_Pointer = new Snake();
			Animal_vector.push_back(Animal_Pointer);
			return true;
		}
	else if (new_animal_type == Animal::AT_LION){
		//constructor for the animal class specified from input is called and a pointer initialized
		Animal *Animal_Pointer = new Lion();
			Animal_vector.push_back(Animal_Pointer);
			return true;
		}
	else if (new_animal_type == Animal::AT_ELEPHANT){
		//constructor for the animal class specified from input is called and a pointer initialized
		Animal *Animal_Pointer = new Elephant();
			Animal_vector.push_back(Animal_Pointer);
			return true;
		}
	else return false;

}


// the next function feeds animals and outputs a result. One of it's inputs is also an output.
// the two main inputs are animal index number and food index number.
ZooManagementSystem::FeedResult ZooManagementSystem::feedAnimal(unsigned int& quantity_eaten, unsigned int animal_index, unsigned int food_index) {
   // the two first if statements check for validity of index. The animal index is
	// checked first due to the fact that FR_INVALID_ANIMAL must be returned if
	// both animal and food indices are invalid.
	if (animal_index < getAnimals().size()) {
    	if (food_index < getFood().size()){
    		// the next line checks if the animal specified likes the food specified.
    		if (getAnimals()[animal_index]->likesFood(getFood()[food_index])){
    			// if animal likes food, it eats a certain amount.
    			quantity_eaten = Animal_vector[animal_index]->feed(Food_vector[food_index]);
    			//if there was enough food, hunger level would be zero and this is checked for,
    			//if it is 0, success is returned.
    			if (getAnimals()[animal_index]->hungerLevel()==0){
    				return FR_SUCCESS;
    			}
    			//if hunger level isn't 0, there wasn't enough food and therefore
    			//FR_EXHAUSTED is returned.
    			else return FR_EXHAUSTED;
    		}
    		else  {
    			//if animal doesn't like the food, FR_INCOMPATIBLE is returned.
    			quantity_eaten = 0;
    			return FR_INCOMPATIBLE;
    		}
    	}
    	else {
    		quantity_eaten = 0;
    		return FR_INVALID_FOOD;
    	}
    }
    else {
    	quantity_eaten = 0;
    	return FR_INVALID_ANIMAL;
    }
}



void ZooManagementSystem::resetAllAnimals() {
	//all animals within the food vector are reset to Hungry using a previously
	//implemented function.
   for ( unsigned int i = 0; i < getAnimals().size(); i++ ){
	   getAnimals()[i]->resetToHungry();
   }
}

void ZooManagementSystem::feedAllAnimals() {
	// the first line sets up a pointer known as quantity_eaten
	unsigned int& quantity_eaten = quantity;
	//for loops are utilized to sort through the hungriest animals in vector.
	//The positions are not changed but merely contained within a variable for use.
	for (unsigned int j = 0; j < getAnimals().size();j++){
		//the first for loop will cycle through animals after hungriest has been fed.
		//the second for loop cycles through animals to find the hungriest.
		for (unsigned int i = 0; i < (getAnimals().size());i++){
			//first if condition checks if current variable index points to an animal
			//hungrier than current for loop variable animal.
			//if a hungrier animal is found, hungriest_index is updated.
			// but only after making sure that the hungriest animal hasn't already been completed
			for (unsigned int k=0; k< Completed_Animals.size();k++){
				if (getAnimals()[hungriest_index]->hungerLevel() < getAnimals()[i]->hungerLevel() && i != Completed_Animals[k]){
							hungriest_index = i;
							}
			}

		}

		//after hungriest animal has been found, appropriate food is searched for.
		for (unsigned int i = 0; i < (getFood().size());i++){
			//the first for loop cycles through all foods in the vector.
			//if the animal doesn't like the food the current food index is on, index is updated.
			if (!(getAnimals()[hungriest_index]->likesFood(getFood()[food_index]))){
				food_index++;
			}
			else if (getFood()[food_index].getQuantity()==0){
				food_index++;
				if (food_index == getFood().size()){
					Completed_Animals.push_back(hungriest_index);
				}
				//if the current index specified for food has a quantity of zero
				// then food index is updated
			}
			//if the animal does like the food, another food that the animal likes and
			//is also of a higher quantity is searched for.
			else if (getAnimals()[hungriest_index]->likesFood(getFood()[food_index])&& getFood()[food_index].getQuantity()<getFood()[i].getQuantity()){
				food_index = i;
				// if found, index updated, if not, index stays as it is.
			}
		}
		// if food is found that animal likes and has a quantity that isn't zero,
		//animal is fed.
		//the success value is returned by the function which was implemented previously.
		if (getFood()[food_index].getQuantity() != 0){
			Success_Output = ZooManagementSystem::feedAnimal(quantity_eaten,hungriest_index,food_index);
			Food_vector[food_index].consume(quantity);
		}
		//after eating, whether hunger level is zero or not, quantity is updated for food.
		while (Success_Output == ZooManagementSystem::FR_EXHAUSTED){
			//if food stores were exhausted before hunger level reached zero,
			//then another food that the animal likes is searched for.
			for (unsigned int i = 0; i < (getFood().size());i++){
						if (!(getAnimals()[hungriest_index]->likesFood(getFood()[food_index]))){
							food_index++;
						}
						else if (getAnimals()[hungriest_index]->likesFood(getFood()[food_index])&& getFood()[food_index].getQuantity()<getFood()[i].getQuantity()){
							food_index = i;
						}

			}
			// if no food animals likes with non zero quantity found, while loop exited out of
			// and the animal is skipped.
			if (getFood()[food_index].getQuantity()==0){
				Success_Output = 0;
			}
			else {
				Success_Output = ZooManagementSystem::feedAnimal(quantity_eaten,hungriest_index,food_index);
				Food_vector[food_index].consume(quantity_eaten);
			}
		}
	}
}
