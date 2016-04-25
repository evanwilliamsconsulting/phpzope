#include "stackitem.h"

StackItem& StackItem::operator=(const StackItem& otherItem)
{
	int i = 0;
	opcode = otherItem.opcode;
	someInt = otherItem.someInt;
	someString = otherItem.someString;
	return *this;
}
