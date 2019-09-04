#ifndef OTTER_HPP
#define OTTER_HPP

#include "Animal.hpp"

class Otter : public Animal {
public:
    Otter();

    // Overridden  so we can return AT_OTTER
    virtual AnimalType type() const;

    // Overridden to indicate which foods the Otter likes
    virtual bool likesFood(const Food& food) const;



};

#endif /* end of include guard: ELEPHANT_HPP */
