#ifndef DRINK_HPP
#define DRINK_HPP

#include "Grocery.hpp" 
#include <iostream>

class Drink: public Grocery
{
public:
    Drink(std::string name, double price, double weight);
    void updateCost();
};

#endif