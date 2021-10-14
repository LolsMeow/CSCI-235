#ifndef ARRAY_BAG_
#define ARRAY_BAG_


template<class ItemType>
class ArrayBag
{

public:
    /** default constructor**/
	ArrayBag();
    
    /**
     @return item_count_ : the current size of the bag
    **/
	int getCurrentSize() const;
    
    /**
     @return true if item_count_ == 0, false otherwise
     **/
	bool isEmpty() const;
    
    /**
     @return true if new_etry was successfully added to items_, false otherwise
     **/
	bool add(const ItemType& new_entry);
    
    /**
     @return true if an_etry was successfully removed from items_, false otherwise
     **/
	bool remove(const ItemType& an_entry);
    
    /**
     @post item_count_ == 0
     **/
	void clear();
    
    /**
     @return true if an_etry is found in items_, false otherwise
     **/
	bool contains(const ItemType& an_entry) const;
    
    /**
     @return the number of times an_entry is found in items_
     **/
	int getFrequencyOf(const ItemType& an_entry) const;

    /** implements Set Union
    The union of two sets A and B is the set of elements which are in A,
    in B, or in both A and B.
    @param a_bag to be combined with the contents of this (the calling) bag
    @post adds as many items from a_bag as space allows
    */
    void operator+=(const ArrayBag<ItemType>& a_bag);

    /** implements Set Difference
    The (set) difference between two sets A and B is the set that
    consists of the elements of A which are not elements of B
    @param a_bag to be subtracted from this (the calling) bag
    @post removes all data from items_ that is also found in a_bag
    */
    void operator-=(const ArrayBag<ItemType>& a_bag);

    /** implements Set Intersection
    The intersection of two sets A and B is the set that
    consists of the elements that are in both A and B
    @param a_bag to be intersected with this (the calling) bag
    @post items_ no longer contains data not found in a_bag
    */
    void operator/=(const ArrayBag<ItemType> &a_bag);

    /**
   Implements Equal Comparison
   Two ArrayBags are equal to each other if they contain the same elements
   the order of the elements do not matter.
   @param a_bag to be compared with this (the calling) bag
   @return true if the two bags contain the same elements, false otherwise
   Note that in order for two bags to be equal the must be of equal sizes.
    **/
    bool operator==(const ArrayBag<ItemType> &a_bag);

    /**
   Implements Not Equal Comparison Opposite of the == operator, if two bags 
      have at least one element different they are not equal
   @param a_bag to be compared with this (the calling) bag
   @return true if two bags have a differing element, false if they are equal
      In this case we can be sure that two arrays are not equal if they have 
                                                              different sizes.
    **/
    bool operator!=(const ArrayBag<ItemType> &a_bag);

protected:
    static const int DEFAULT_CAPACITY = 200;  //max size of items_
    ItemType items_[DEFAULT_CAPACITY];              // Array of bag items
    int item_count_;                         // Current count of bag items
    
   
    /**
     @param target to be found in items_
     @return either the index target in the array items_ or -1,
     if the array does not containthe target.
     **/
    int getIndexOf(const ItemType& target) const;
    
    
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif