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

using namespace std;

class StackItem {
    public:
        char opcode;
        int someInt;
        StackItem()
	{
	}
        StackItem(const StackItem &otherItem)
	{
	    opcode = otherItem.opcode;
	    someInt = otherItem.someInt;
	}
	StackItem& operator= (const StackItem &otherItem);
};
