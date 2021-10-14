#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<class ItemType>
class DoubleNode{

public:
    DoubleNode(); 
    DoubleNode(const ItemType& anItem);
    DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* next_ptr);
    // Setter Functions
    void setItem(const ItemType &anItem);
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);
    void setNext(DoubleNode<ItemType> *nextNodePtr);

    // Getter Functions
    ItemType getItem() const;
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrevious() const;

private:
    ItemType item_;
    DoubleNode<ItemType> *next_;
    DoubleNode<ItemType> *prev_;
};


#include "DoubleNode.cpp"
#endif