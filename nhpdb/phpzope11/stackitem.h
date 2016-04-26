/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string.h>
#include <stdexcept>
#include <fstream>
#include <regex>

using namespace std;

class StackItem {
    public:
        char opcode;
        int someInt;
	char* someString;
	int theMark;
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
	}
	StackItem& operator= (const StackItem &otherItem);
};
