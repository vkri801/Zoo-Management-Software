#ifndef LION_HPP
#define LION_HPP

#include "Animal.hpp"

class Lion : public Animal {
public:
    Lion();

    // Overridden  so we can return AT_LION
    virtual AnimalType type() const;

    // Overridden to indicate which foods the Lion likes
    virtual bool likesFood(const Food& food) const;


};

#endif /* end of include guard: LION_HPP */
