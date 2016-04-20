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
        StackItem()
	{
	}
        StackItem(const StackItem &otherItem)
	{
	    opcode = otherItem.opcode;
	    someInt = otherItem.someInt;
	    someString = otherItem.someString;
	}
	StackItem& operator= (const StackItem &otherItem);
};

class Stack {
    public:
        Stack()
	{
	   top=0;
	}
	int depth()
	{
		return top;
	}
        void push(StackItem);
        StackItem *pop();
        bool isempty() {
		if (top==0)
			return -1;
		else
			return 0;
        }
        bool isfull() {
		if (top==1000)
			return -1;
		else
			return 0;
	}
    private:
        StackItem items[1001];
        int top;
};
