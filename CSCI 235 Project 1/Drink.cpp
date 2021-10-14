#include "Drink.hpp"

Drink::Drink(std::string name, double price, double weight) : Grocery(name, price, weight)
{
}

void Drink::updateCost()
{
    total_price_ = quantity_ * unit_price_ * (unit_weight_ * 16/33.814); 
}