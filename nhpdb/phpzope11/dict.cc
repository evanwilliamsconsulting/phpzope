#include "dict.h"

Dict& Dict::operator=(const Dict& otherItem)
{
	count = otherItem.count;
	return *this;
}
void Dict::insertPair(char* theKey,char* theValue)
{
	keys[keyIndex] = theKey;
	values[keyIndex] = theValue;
	keyIndex++;
}
char* Dict::printDict()
{
	char* buf;
	buf = output;
	buf += sprintf(output,"DICT: ");
	for (int i = 0; i<keyIndex; i++)
	{
	    buf += sprintf(buf," %s => %s ",keys[i],values[i]);
        }
	return output;
}
