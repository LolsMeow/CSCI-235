#include <iostream>
#include "ArrayBag.hpp"

/** default constructor**/
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): item_count_(0)
{
}

/**
 @return item_count_ : the current size of the bag
 **/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return item_count_;
}

/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return item_count_ == 0;
}

/**
 @return true if new_entry was successfully added to items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry)
{
    bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room){             
		items_[item_count_] = new_entry;                
		item_count_++;                                 
        return true;
    }
	return false;
}

/**
 @return true if an_entry was successfully removed from items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry)
{
    int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}
	return can_remove;
}

/**
 @post item_count_ == 0
 **/
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	item_count_ = 0;
}

/**
 @return true if an_entry is found in items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const
{
   int frequency = 0;   
   for(int i = 0; i < item_count_; i++){
      if (items_[i] == an_entry){
         frequency++;
      }   
   }
   return frequency;
}

/* implements Set Union
    The union of two sets A and B is the set of elements which are in A,
    in B, or in both A and B.
    @param a_bag to be combined with the contents of this (the calling) bag
    @post adds as many items from a_bag as space allows
*/
template<class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType>& a_bag){                
    for(int i = 0; i < a_bag.item_count_; i++){
        if(this-> contains(a_bag.items_[i])){
            i++;
        }        
        this-> add(a_bag.items_[i]);                                
    }
}

/* implements Set Difference
    The (set) difference between two sets A and B is the set that
    consists of the elements of A which are not elements of B
    @param a_bag to be subtracted from this (the calling) bag
    @post removes all data from is_ that is also found in a_bag
*/
template<class ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType>& a_bag){
    for(int i = 0; i < a_bag.item_count_; i++){             
        if(this-> contains(a_bag.items_[i])){                     
            this-> remove(a_bag.items_[i]);                      
        }
    }    
} 

/** implements Set Intersection
    The intersection of two sets A and B is the set that
    consists of the elements that are in both A and B
    @param a_bag to be intersected with this (the calling) bag
    @post items_ no longer contains data not found in a_bag
*/
template<class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType>& a_bag){
    for(int i = 0; i < item_count_; i++){                 
        if(!a_bag.contains(items_[i])){                           
            this-> remove(items_[i]);                             
        }
    }
}

/**
   Implements Equal Comparison
   Two ArrayBags are equal to each other if they contain the same elements
   the order of the elements do not matter.
   @param a_bag to be compared with this (the calling) bag
   @return true if the two bags contain the same elements, false otherwise
   Note that in order for two bags to be equal the must be of equal sizes.
**/
template<class ItemType>
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType> &a_bag){
    for(int i = 0; i < item_count_; i++){
        if(!a_bag.contains(items_[i])){
            return false;
        }
    }
    return true;
}
/**
   Implements Not Equal Comparison Opposite of the == operator, if two bags 
      have at least one element different they are not equal
   @param a_bag to be compared with this (the calling) bag
   @return true if two bags have a differing element, false if they are equal
      In this case we can be sure that two arrays are not equal if they have 
                                                              different sizes.
**/
template<class ItemType>
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType> &a_bag){
    for(int i = 0; i < item_count_; i++){
        if(!a_bag.contains(items_[i])){
            return true;
        }
    }
    return false;
}


// ********* PROTECTED METHODS **************//

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
   int result = -1;
   int search_index = 0;

   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  
   }  

   return result;
}