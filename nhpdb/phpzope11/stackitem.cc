#include "stackitem.h"

StackItem& StackItem::operator=(const StackItem& otherItem)
{
	int i = 0;
	opcode = otherItem.opcode;
	someInt = otherItem.someInt;
	someString = otherItem.someString;
	theMark = otherItem.theMark;
	lastMark = otherItem.lastMark;
	someTuple = otherItem.someTuple;
	return *this;
}
void StackItem::initializeTuple()
{
	someTuple = (Tuple*)emalloc(sizeof(Tuple));
}
void StackItem::setIndex(int theIndex)
{
	someTuple->index = theIndex;
}
void StackItem::setModuleName(char* theModuleName)
{
	someTuple->moduleName = (char*)emalloc(sizeof(char)*100);
	strcpy(someTuple->moduleName,theModuleName);
}
void StackItem::setClassName(char* theClassName)
{
	someTuple->className = (char*)emalloc(sizeof(char)*100);
	strcpy(someTuple->className,theClassName);
}
int StackItem::getIndex()
{
	return someTuple->index;
}
char* StackItem::getModuleName()
{
	return someTuple->moduleName;
}
char* StackItem::getClassName()
{
	return someTuple->className;
}
