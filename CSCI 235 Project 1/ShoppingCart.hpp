#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "DynamicArray.hpp"
#include "Grocery.hpp"
#include <iostream>

class ShoppingCart : public DynamicArray<Grocery*>
{
public:
    ShoppingCart();
    ~ShoppingCart();
    bool add(Grocery * new_entry);
    bool remove(Grocery * an_item);
    void garbageClear();
    double getCurrentWeight();
    double checkout();

private:
    double curr_contents_weight_;
};
#endif