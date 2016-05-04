/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <fstream>
#include <stack>
#include <regex>

#include "php.h"

#include "tuple.h"

using namespace std;

class StackItem {
    public:
        char opcode;
        int someInt;
	char* someString;
	Tuple* someTuple;
	int theMark;
	int lastMark;
        StackItem()
	{
	    theMark = 0;
	}
        StackItem(const StackItem &otherItem)
	{
	    opcode = otherItem.opcode;
	    someInt = otherItem.someInt;
	    someString = otherItem.someString;
	    theMark = otherItem.theMark;
	    lastMark = otherItem.lastMark;
	    someTuple = otherItem.someTuple;
	}
	StackItem& operator= (const StackItem &otherItem);
	void initializeTuple();
	void setIndex(int theIndex);
	void setModuleName(char* theModuleName);
	void setClassName(char* theClassName);
	char* getModuleName();
	char* getClassName();
	int getIndex();
};
