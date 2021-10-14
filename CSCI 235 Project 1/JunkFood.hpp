#ifndef JUNKFOOD_HPP
#define JUNKFOOD_HPP

#include "Grocery.hpp" 
#include <iostream>

class JunkFood: public Grocery
{
public:
    JunkFood(std::string name, double price, double weight);
    void updateCost();
};

#endif