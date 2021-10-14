#include "Vegetable.hpp"

Vegetable::Vegetable(std::string name, double price, double weight) : Grocery(name, price, weight)
{
}

void Vegetable::updateCost()
{
    total_price_ = quantity_ * unit_price_ * unit_weight_; 
}