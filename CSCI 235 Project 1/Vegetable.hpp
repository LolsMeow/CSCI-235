#ifndef VEGETABLE_HPP
#define VEGETABLE_HPP

#include "Grocery.hpp" 
#include <iostream>

class Vegetable: public Grocery
{
public:
    Vegetable(std::string name, double price, double weight);
    void updateCost();
};

#endif