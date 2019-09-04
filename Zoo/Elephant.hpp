#ifndef ELEPHANT_HPP
#define ELEPHANT_HPP

#include "Animal.hpp"


class Elephant : public Animal {
public:
    Elephant();

    // Overridden  so we can return AT_ELEPHANT
    virtual AnimalType type() const;

    // Overridden to indicate which foods the Elephant likes
    virtual bool likesFood(const Food& food) const;





};

#endif /* end of include guard: ELEPHANT_HPP */
