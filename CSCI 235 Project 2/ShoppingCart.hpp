#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "ArrayBag.hpp"
#include "Grocery.hpp"
#include <iostream>

class ShoppingCart : public ArrayBag<Grocery*>
{
public:
    ShoppingCart();
    ~ShoppingCart();
    /**
    bool add(Grocery * new_entry);
    bool remove(Grocery * an_item);
    void garbageClear();
    double getCurrentWeight();
    double checkout();
    **/
    /**
   Implements Greater Than Comparison
   A ShoppingCart is greater than another ShoppingCart if the total cost of its items is greater.
   @param a_cart to be compared with this (the calling) cart
   @return true if the total cost of this (the calling) cart is greater than the total cost of items in a_cart.
    **/
    bool operator>(ShoppingCart a_cart);
    /**
   Implements Less Than Comparison
   A ShoppingCart is less than another ShoppingCart if the total cost of its items is less.
   @param a_cart to be compared with this (the calling) cart
   @return true if the total cost of this (the calling) cart is less than the total cost of items in a_cart.
    **/
    bool operator<(ShoppingCart a_cart);

private:
    double curr_contents_weight_;
};
#endif