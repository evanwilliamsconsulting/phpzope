#include "stackitem.h"

StackItem& StackItem::operator=(const StackItem& otherItem)
{
	int i = 0;
	opcode = otherItem.opcode;
	someInt = otherItem.someInt;
	someString = otherItem.someString;
	return *this;
}

// Function to add item x to stack
void Stack::push(StackItem x)
{
    StackItem currentItem;
    if(!isfull()){
	this->items[this->top] = x;
        this->top++;
        return; }
    else
        return;
}

// Function to remove and return top item of stack
StackItem *Stack::pop()
{
	return &items[--top];
}
