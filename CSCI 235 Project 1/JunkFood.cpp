#include "JunkFood.hpp"

JunkFood::JunkFood(std::string name, double price, double weight) : Grocery(name, price, weight)
{
}

void JunkFood::updateCost()
{
    total_price_ = quantity_ * unit_price_; 
}