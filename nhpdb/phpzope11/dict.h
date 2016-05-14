/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string.h>
#include <stdexcept>
#include <fstream>
#include <regex>
#include <string>
#include <map>

using namespace std;

class Dict {
    public:
	char output[200];
	char *keys[20];
	char *values[20];
	int keyIndex;
	int count;
	void insertPair(char* theKey,char* theValue);
	char* printDict();
        Dict()
	{
	    count = 0;
	    keyIndex = 0;
	}
        Dict(const Dict &otherItem)
	{
	    count = otherItem.count;
	}
	Dict& operator= (const Dict& otherItem);
};
