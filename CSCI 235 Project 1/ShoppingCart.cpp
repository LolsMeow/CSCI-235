#include "ShoppingCart.hpp"
#include <iostream>
#include <iomanip>
ShoppingCart::ShoppingCart()
{
}
ShoppingCart::~ShoppingCart()
{
}
   
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
            DynamicArray::add(new_entry);
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
    if(contains(an_item))
    {
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
    for(int i = 0; i < item_count_; i++)
    {
        if(items_[i]->getQuantity() == 0)
        {
            for(int j = i; j < item_count_-1; j++)
            {
                items_[j] = items_[j+1];
            }
            item_count_--;
            resize();
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
}
