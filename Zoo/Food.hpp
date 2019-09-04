
#ifndef FOOD_HPP
#define FOOD_HPP

#include <string>

//This is the header file which contains declarations for functions which are defined in Food.cpp

/*
The Food class is used to store types of food that can be fed to animals.

Each food has a name, cost, and quantity available.
*/
class Food {
public:
    /*
    The constructor takes the food's name and cost as parameters. These values cannot be changed
    after construction. The quantity property always starts at 0 for a new food type.
    */
    Food(const std::string& new_name, double new_cost, unsigned int new_energy);


    /*
    Return the food's name, e.g. "bananas"
    */
    std::string getName() const;

    /*
    Return the cost per item, in local $.
    */
    double getCost() const;

    /*
    Return the energy content per unit of this food.
    */
    unsigned int getEnergy() const;

    /*
    Return the quantity of the this food available on-hand at the Zoo
    */
    unsigned int getQuantity() const;

    /*
    Use some quantity of food as specified by the `count` parameter. If there is less of the food
    available than requested, consume as much as possible. Returns the quantity of this food
    consumed.
    */
    unsigned int consume(unsigned int count);

    /*
    Purchase more of this food. Returns the cost of the transaction and increments the class's
    internal quantity counter by the value of the `count` parameter.
    */
    void purchase(unsigned int count);

private:
    // These variables are stored as private to prevent changing from outside of class.
    //Name of food is stored on the variable name as type string.
    std::string name;

    //Energy which is an unsigned integer is stored within the next variable
     unsigned int Energy;

    //Cost as a double (since it represents value of money) is stored within next variable.
    double Cost;

    //Quantity is the amount of a particular food item on hand and is stored again as uint8
    unsigned int Quantity;

};

#endif /* end of include guard: FOOD_HPP */
