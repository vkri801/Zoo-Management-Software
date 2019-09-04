#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Animal.hpp"

class Snake : public Animal {
public:
    Snake();

    // Overridden  so we can return AT_SNAKE
    virtual AnimalType type() const;

    // Overridden to indicate which foods the Snake likes
    virtual bool likesFood(const Food& food) const;



};

#endif /* end of include guard: SNAKE_HPP */
