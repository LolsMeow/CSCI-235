#include "ShoppingCart.hpp"
#include <iostream>
#include <iomanip>
ShoppingCart::ShoppingCart()
{
}
ShoppingCart::~ShoppingCart()
{
}
/**  
bool ShoppingCart::add(Grocery * new_entry)
{
    if(curr_contents_weight_ < 350)
    {
        if(contains(new_entry))
        {
            items_[getIndexOf(new_entry)]->incrementQuantity();
            curr_contents_weight_ = curr_contents_weight_ + items_[getIndexOf(new_entry)]->getUnitWeight();

        }
        else
        {
            ArrayBag::add(new_entry);
            items_[getIndexOf(new_entry)]->incrementQuantity();
            items_[getIndexOf(new_entry)]->decrementQuantity();
            curr_contents_weight_ = curr_contents_weight_ + items_[getIndexOf(new_entry)]->getUnitWeight();
        }
        return true;
    }
    return false;
}
bool ShoppingCart::remove(Grocery * an_item)
{
    if(contains(an_item) && an_item->getQuantity() >=2)
    {
        items_[getIndexOf(an_item)]->decrementQuantity();
        curr_contents_weight_ = curr_contents_weight_ - items_[getIndexOf(an_item)]->getUnitWeight();
        garbageClear();
        return true;
    }
    else if(contains(an_item))
    {
        ArrayBag::remove(an_item);
        items_[getIndexOf(an_item)]->incrementQuantity();
        items_[getIndexOf(an_item)]->decrementQuantity();
        curr_contents_weight_ = curr_contents_weight_ - items_[getIndexOf(an_item)]->getUnitWeight();
        garbageClear();
        return true;
    }
    else
    {
    return false;
    }
}
void ShoppingCart::garbageClear()
{
    for(int i = 0; i < current_capacity_ - 1; i++)
    {
        if(items_[i]->getQuantity() == 0)
        {
            remove(items_[i]);
        }
    }
}
double ShoppingCart::getCurrentWeight()
{
    return curr_contents_weight_;
}

double ShoppingCart::checkout()
{
   if (item_count_ == 0)
   {
      std::cout << "Your cart is empty!" << std::endl;
      return 0;
   }

   double total = 0;
   for (size_t i = 0; i < item_count_; i++)
   {
      std::cout << "\n" << std::setw(10) << std::left << 
            items_[i]->getName() << "\t" << items_[i]->getQuantity() 
            << "\t" << std::fixed << std::setprecision(2) 
            << items_[i]->getTotalPrice();
      total += items_[i]->getTotalPrice();
   }
   std::cout << std::setfill('-') << std::setw(40) << "\n" 
         << std::endl << "Total:                  " 
         << total << std::endl << std::endl;
   clear();
   return total;
}**/

/**
   Implements Greater Than Comparison
   A ShoppingCart is greater than another ShoppingCart if the total cost of its items is greater.
   @param a_cart to be compared with this (the calling) cart
   @return true if the total cost of this (the calling) cart is greater than the total cost of items in a_cart.
**/
bool ShoppingCart::operator>(ShoppingCart a_cart)
{
    int thisTotal = 0;
    int aTotal = 0;
    for(int i = 0; i < item_count_; i++)
    {
        thisTotal += items_[i]->getTotalPrice();
    }
    for(int i = 0; i < a_cart.item_count_; i++)
    {
        aTotal += a_cart.items_[i]->getTotalPrice();
    }
    return thisTotal > aTotal;
}

/**
   Implements Less Than Comparison
   A ShoppingCart is less than another ShoppingCart if the total cost of its items is less.
   @param a_cart to be compared with this (the calling) cart
   @return true if the total cost of this (the calling) cart is less than the total cost of items in a_cart.
**/
bool ShoppingCart::operator<(ShoppingCart a_cart)
{
    int thisTotal = 0;
    int aTotal = 0;
    for(int i = 0; i < item_count_; i++)
    {
        thisTotal += items_[i]->getTotalPrice();
    }
    for(int i = 0; i < a_cart.item_count_; i++)
    {
        aTotal += a_cart.items_[i]->getTotalPrice();
    }
    return thisTotal < aTotal;
}

