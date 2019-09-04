#ifndef MONKEY_HPP
#define MONKEY_HPP

#include "Animal.hpp"

class Monkey : public Animal {
public:
    Monkey();

    // Overridden so we can return AT_MONKEY
    virtual AnimalType type() const;

    // Overridden to indicate which foods the Monkey likes
    virtual bool likesFood(const Food& food) const;




};

#endif /* end of include guard: MONKEY_HPP */
