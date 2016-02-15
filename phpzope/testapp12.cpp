/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <regex>
#include <fstream>

/* MySQL Connector/C++ specific headers */
#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include <warning.h>

using namespace std;
using namespace sql;

//ifndef MYLIB_CONSTANTS_H
//define MYLIB_CONSTANTS_H

//  File Name : LibConstants.hpp    Purpose : Global Constants for Lib Utils
// Pickle opcodes.  See pickletools.py for extensive docs.  The listing
// here is in kind-of alphabetical order of 1-character pickle code.
// pickletools groups them by purpose.

enum pycodes {
  MARK,
  STOP,
  POP,
  POP_MARK,
  DUP,
  FLOAT,
  INT,
  BININT,
  BININT1,
  LONG,
  BININT2,
  NONE,
  PERSID,
  BINPERSID,
  REDUCE,
  STRING,
  BINSTRING,
  SHORT_BINSTRING,
  UNICODE,
  BINUNICODE,
  APPEND,  
  BUILD,  
  GLOBAL,
  DICT,
  EMPTY_DICT,
  APPENDS,
  GET,    
  BINGET,
  INST, 
  LONG_BINGET,
  LIST,     
  EMPTY_LIST,
  OBJ,     
  PUT,    
  BINPUT,
  LONG_BINPUT,
  SETITEM,  
  TUPLE,   
  EMPTY_TUPLE,
  SETITEMS, 
  BINFLOAT,
  PROTO,  
  NEWOBJ,
  EXT1, 
  EXT2,
  EXT4,
  TUPLE1,
  TUPLE2,
  TUPLE3,
  TRUE,
  FALSE,
  LONG1,
  LONG4,
  OPCODE_COUNT
};

typedef int (*fn)(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);

class Opcode {
	protected:
	    std::string module;
	    std::string name;
	    std::string pid;
        public:
	    char opcode;
	    fn opfunc;
            Opcode(char opcodeChar,fn funct);
	    void setModule(std::string inModule);
	    void setName(std::string inName); 
	    void setPid(std::string inPid);
            static int fnSTOP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
	    static int fnMARK(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPOP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPOP_MARK(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnDUP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnFLOAT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnINT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnNONE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPERSID(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINPERSID(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnREDUCE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSHORT_BINSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnUNICODE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINUNICODE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnAPPEND(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnBUILD(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnGLOBAL(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnDICT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEMPTY_DICT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnAPPENDS(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);    
            static int fnBINGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnINST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnLONG_BINGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLIST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);     
            static int fnEMPTY_LIST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnOBJ(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);     
            static int fnPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);    
            static int fnBINPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG_BINPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSETITEM(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnTUPLE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);   
            static int fnEMPTY_TUPLE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSETITEMS(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnBINFLOAT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPROTO(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnNEWOBJ(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEXT1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnEXT2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEXT4(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE3(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTRUE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnFALSE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG4(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr);
};

Opcode::Opcode(char opcodeChar,fn funct)
{
    this->opcode = opcodeChar;
    this->opfunc = funct;
}
void Opcode::setModule(std::string inModule)
{
	this->module=inModule;
}
void Opcode::setName(std::string inName) 
{
	this->name=inName;
}
void Opcode::setPid(std::string inPid) 
{
	this->pid=inPid;
}

class Pickle {

    public:
        Pickle();
	Opcode *opcodes[OPCODE_COUNT];
};

Pickle::Pickle()
{
    opcodes[STOP] = new Opcode('.',Opcode::fnSTOP);
    opcodes[MARK] = new Opcode('(',Opcode::fnMARK);
    opcodes[POP] = new Opcode('0',Opcode::fnPOP);
    opcodes[POP_MARK] = new Opcode('1',Opcode::fnPOP_MARK);
    opcodes[DUP] = new Opcode('2',Opcode::fnDUP);
    opcodes[FLOAT] = new Opcode('F',Opcode::fnFLOAT);
    opcodes[INT] = new Opcode('I',Opcode::fnINT);
    opcodes[BININT] = new Opcode('J',Opcode::fnBININT);
    opcodes[BININT1] = new Opcode('K',Opcode::fnBININT1);
    opcodes[LONG] = new Opcode('L',Opcode::fnLONG);
    opcodes[BININT2] = new Opcode('M',Opcode::fnBININT2);
    opcodes[NONE] = new Opcode('N',Opcode::fnNONE);
    opcodes[PERSID] = new Opcode('P',Opcode::fnPERSID);
    opcodes[BINPERSID] = new Opcode('Q',Opcode::fnBINPERSID);
    opcodes[REDUCE] = new Opcode('R',Opcode::fnREDUCE);
    opcodes[STRING] = new Opcode('S',Opcode::fnSTRING);
    opcodes[BINSTRING] = new Opcode('T',Opcode::fnBINSTRING);
    opcodes[SHORT_BINSTRING] = new Opcode('U',Opcode::fnSHORT_BINSTRING);
    opcodes[UNICODE] = new Opcode('V',Opcode::fnUNICODE);
    opcodes[BINUNICODE] = new Opcode('X',Opcode::fnBINUNICODE);
    opcodes[APPEND] = new Opcode('a',Opcode::fnAPPEND);  
    opcodes[BUILD] = new Opcode('b',Opcode::fnBUILD);  
    opcodes[GLOBAL] = new Opcode('c',Opcode::fnGLOBAL);
    opcodes[DICT] = new Opcode('d',Opcode::fnDICT);
    opcodes[EMPTY_DICT] = new Opcode('}',Opcode::fnEMPTY_DICT);
    opcodes[APPENDS] = new Opcode('e',Opcode::fnAPPENDS);
    opcodes[GET] = new Opcode('g',Opcode::fnGET);    
    opcodes[BINGET] = new Opcode('h',Opcode::fnBINGET);
    opcodes[INST] = new Opcode('i',Opcode::fnINST); 
    opcodes[LONG_BINGET] = new Opcode('j',Opcode::fnLONG_BINGET);
    opcodes[LIST] = new Opcode('l',Opcode::fnLIST);     
    opcodes[EMPTY_LIST] = new Opcode(']',Opcode::fnEMPTY_LIST);
    opcodes[OBJ] = new Opcode('o',Opcode::fnOBJ);     
    opcodes[PUT] = new Opcode('p',Opcode::fnPUT);    
    opcodes[BINPUT] = new Opcode('q',Opcode::fnBINPUT);
    opcodes[LONG_BINPUT] = new Opcode('r',Opcode::fnLONG_BINPUT);
    opcodes[SETITEM] = new Opcode('s',Opcode::fnSETITEM);  
    opcodes[TUPLE] = new Opcode('t',Opcode::fnTUPLE);   
    opcodes[EMPTY_TUPLE] = new Opcode(')',Opcode::fnEMPTY_TUPLE);
    opcodes[SETITEMS] = new Opcode('u',Opcode::fnSETITEMS); 
    opcodes[BINFLOAT] = new Opcode('G',Opcode::fnBINFLOAT);
    opcodes[PROTO] = new Opcode('\x80',Opcode::fnPROTO);  
    opcodes[NEWOBJ] = new Opcode('\x81',Opcode::fnNEWOBJ);
    opcodes[EXT1] = new Opcode('\x82',Opcode::fnEXT1); 
    opcodes[EXT2] = new Opcode('\x83',Opcode::fnEXT2);
    opcodes[EXT4] = new Opcode('\x84',Opcode::fnEXT4);
    opcodes[TUPLE1] = new Opcode('\x85',Opcode::fnTUPLE1);
    opcodes[TUPLE2] = new Opcode('\x86',Opcode::fnTUPLE2);
    opcodes[TUPLE3] = new Opcode('\x87',Opcode::fnTUPLE3);
    opcodes[TRUE] = new Opcode('\x88',Opcode::fnTRUE);
    opcodes[FALSE] = new Opcode('\x89',Opcode::fnFALSE);
    opcodes[LONG1] = new Opcode('\x8a',Opcode::fnLONG1);
    opcodes[LONG4] = new Opcode('\x8b',Opcode::fnLONG4);
}

// push special markobject on stack
int Opcode::fnMARK(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
        std:string binput;
        cout << "MARK";
        it1++;
        int forward = 1;
        cout << "MARK";
        cout << endl;
        return forward;
}
// every pickle ends with STOP
int Opcode::fnSTOP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
        std:string binput;
        cout << "STOP";
        it1++;
        int forward = 1;
        cout << "STOP";
        cout << endl;
        return forward;
}
// discard topmost stack item
int Opcode::fnPOP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "POP";
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "POP_MARK";
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "DUP";
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "FLOAT";
	return 0;
}
int Opcode::fnINT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "INT";
	it1++;
	while (*it1 != '\n')
	{
		it1++;
	}
	return 0;
}
// push four-byte signed int
int Opcode::fnBININT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BININT";
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BININT1";
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LONG";
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BININT2";
	return 0;
}
// push None
int Opcode::fnNONE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "NONE";
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	std::string pid;
        cout << "PERSID_START";
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 1)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '\n')
             {
		cout << "GOTCHA";
		if (countNewline == 0)
		{
			((Opcode*)classPtr)->setPid(pid);
		}	
		countNewline++;
	     }
             else
             {
		if (countNewline == 0)
		{
			pid.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++; 
	}
	cout << "pid";
	cout << pid;
        cout << "PERSID_END";
	cout << endl;
	
	return forward;
}
int Opcode::fnBINPERSID(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BINPERSID";
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "REDUCE";
	return 0;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "STRING";
	return 0;
}
// push string; counted binary string argument
int Opcode::fnBINSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BINSTRING";
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	int intBinstring;
	std::string shortBinstring;
        cout << "SHORT_BINSTRING";
        it1++;
        int forward = 1;
	// Next byte contains length
	// Of the binstring to read
        if (it1 != str1.end())
        {
             int item;
             item = *it1;
             cout << "BINSTRING_LENGTH: ";
	     intBinstring = *it1;
	     cout << intBinstring;
             it1++;
             forward++;
        }
	int intCountDown;
	intCountDown = intBinstring;	
	while (it1 != str1.end() && intCountDown > 0)
	{
	    shortBinstring.append(sizeof(char),*it1);
	    it1++;
	    intCountDown--;
	    forward++;		
	}
        cout << "short_binstring ";
        cout << shortBinstring;
        cout << "SHORT_BINSTRING";
        cout << endl;
        return forward;
}
// push Unicode string; raw-unicode-escaped'd argument
int Opcode::fnUNICODE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "UNICODE";
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BINUNICODE";
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr) 
{
	cout << "APPEND";
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BUILD";
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	std::string module;
	std::string name;
        cout << "GLOBAL_START";
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 2)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '\n')
             {
		cout << "GOTCHA";
		if (countNewline == 0)
		{
			((Opcode*)classPtr)->setModule(module);
		}	
		else if (countNewline == 1)
		{
			((Opcode*)classPtr)->setName(name);
		}
		countNewline++;
	     }
             else
             {
		if (countNewline == 0)
		{
			module.append(sizeof(char),*it1);
		}
		else if (countNewline == 1)
		{
			name.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++;
	}
	cout << "module";
	cout << module;
	cout << "name";
	cout << name;
        cout << "GLOBAL_END";
	cout << endl;
	return forward;
}
// build a dict from stack items
int Opcode::fnDICT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "DICT";
	return 0;
}
// push empty dict
int Opcode::fnEMPTY_DICT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
        std:string binput;
        cout << "EMPTY_DICT_START";
        it1++;
        int forward = 1;
        cout << "EMPTY_DICT_END";
        cout << endl;
        return forward;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "APPENDS";
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "GET";
	return 0;
}
//   "    "    "    "   "   "  ;   "    " 1-byte arg
int Opcode::fnBINGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BINGET";
	return 0;
}
// build & push class instance
int Opcode::fnINST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr) 
{
	std::string module;
	std::string name;
        cout << "INST_START";
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 2)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '\n')
             {
		cout << "GOTCHA";
		if (countNewline == 0)
		{
			((Opcode*)classPtr)->setModule(module);
		}	
		else if (countNewline == 1)
		{
			((Opcode*)classPtr)->setName(name);
		}
		countNewline++;
	     }
             else
             {
		if (countNewline == 0)
		{
			module.append(sizeof(char),*it1);
		}
		else if (countNewline == 1)
		{
			name.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++;
	}
	cout << "module";
	cout << module;
	cout << "name";
	cout << name;
        cout << "INST_END";
	cout << endl;
	
	return forward;
}
// push item from memo on stack; index is 4-byte arg
int Opcode::fnLONG_BINGET(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LONG_BINGET";
	return 0;
}
// build list from topmost stack items
int Opcode::fnLIST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LIST";
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "EMPTY_LIST";
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr) 
{
	cout << "OBJ";
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)    
{
	cout << "PUT";
	return 0;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
        std:string binput;
        cout << "BINPUT_START";
	it1++;
	int forward = 1;
	// This is one byte long
	// As said above ... DUH
	int item;
	item = *it1;
	cout << "GOTCHA";
	binput.append(sizeof(char),*it1);
	cout << "binput";
	cout << binput;
        cout << "BINPUT_END";
	cout << endl;
	return forward;
}
//   "     "    "   "   " ;   "    " 4-byte arg
int Opcode::fnLONG_BINPUT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LONG_BINPUT";
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	// pop the stack twice
	// form the key and the value
	// open a dictionary
	cout << "SETITEM_START";
	cout << "SETITEM_END";
	cout << endl;
	return 0;
}
// build tuple from topmost stack items
int Opcode::fnTUPLE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "TUPLE";
	return 0;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "EMPTY_TUPLE";
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "SETITEMS";
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "BINFLOAT";
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	cout << "BINFLOATEND";
	return 0;
}
// identify pickle protocol
int Opcode::fnPROTO(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "PROTO";
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "NEWOBJ";
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr) 
{
	cout << "EXT1";
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "EXT2";
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "EXT4";
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "TUPLE1";
	return 0;
}
// build 2-tuple from two topmost stack items
int Opcode::fnTUPLE2(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "TUPLE2";
	return 0;
}
// build 3-tuple from three topmost stack items
int Opcode::fnTUPLE3(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "TUPLE3";
	return 0;
}
// push True
int Opcode::fnTRUE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "TRUE";
	return 0;
}
// push False
int Opcode::fnFALSE(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "FALSE";
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LONG1";
	return 0;
}
// push really big long
int Opcode::fnLONG4(ResultSet *rs,std::string str1,std::string::iterator &it1,void *classPtr)
{
	cout << "LONG4";
	return 0;
}
	
#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "ptH3984z"
#define DATABASE "nhp"

#define NUMOFFSET 100
#define COLNAME 200


int retrieve_zoid(ResultSet *rs, int type, int colidx, string colname) {
	sql::SQLString zoid;

	/* fetch the data : retrieve all the rows in the result set */
	while (rs->next()) {
		if (type == NUMOFFSET) {
		       zoid = rs -> getString(colidx);
		} else if (type == COLNAME) {
                       zoid = rs -> getString(colname);
		} // if-else
	} // while

	std::string zoid2;
	zoid2 = zoid;
	int result_zoid;
	istringstream(zoid) >> result_zoid;
	return result_zoid;

} // retrieve_zoid()


static void retrieve_state(ResultSet *rs, int type, int colidx, string colname) {
	sql::SQLString state;
	std::string filename = "state.txt";
	std::ofstream out(filename);

	/* fetch the data : retrieve all the rows in the result set */
	int rsResult;
	rsResult = rs->next();
	while (rsResult = rs->next()) {
		if (type == NUMOFFSET) {
	               cout << "NUMOFFSET";	
		       cout << colidx;
		       state = rs -> getString(colidx);
		} else if (type == COLNAME) {
		       cout << "COLNAME";
		       cout << colname;
		       state = rs -> getString(colname);
		} // if-else
		std::string state2;
		state2 = state;
		//cout << "STATE2";
		//cout << state2;
		out << state2;

	        Pickle *myPickler = new Pickle();
		std::string::iterator it;
		it = state2.begin();
		while (it != state2.end())
		{
		    cout << "READ NEXT";
		    cout << *it;
		    for (int i = 0; i < OPCODE_COUNT; i++)
		    {
		        Opcode *currentOpcode = myPickler->opcodes[i];
			if (currentOpcode->opcode == *it)
                        {
				/*
				cout << "OPCODE: ";
				cout << *it;
				cout << myPickler->opcodes[i];
				cout << currentOpcode->opcode;
				cout << "ENDOPCODE ";
				*/
				int result;
	        		result = (currentOpcode->opfunc)(rs,state2,it,currentOpcode);
			}
		    }
		    it++;
		}

	        //Opcode *popOpcode = myPickler->opcodes[POP];
		//std::string module;
		//std::string name;
	        cout << "HELLO WORLD";
		cout << std::endl;

	} // while
	out.close();

} // retrieve_state()

static void retrieve_data_and_print (ResultSet *rs, int type, int colidx, string colname) {

	/* retrieve the row count in the result set */
	cout << "\nRetrieved " << rs -> rowsCount() << " row(s)." << endl;

	cout << colname << endl;
	cout << "--------" << endl;

	/* fetch the data : retrieve all the rows in the result set */
	while (rs->next()) {
		if (type == NUMOFFSET) {
                       cout << rs -> getString(colidx) << endl;
		} else if (type == COLNAME) {
                       cout << rs -> getString(colname) << endl;
		} // if-else
	} // while

	cout << endl;

} // retrieve_data_and_print()

static void retrieve_dbmetadata_and_print (Connection *dbcon) {

	if (dbcon -> isClosed()) {
		throw runtime_error("DatabaseMetaData FAILURE - database connection closed");
	}

	cout << "\nDatabase Metadata" << endl;
	cout << "-----------------" << endl;

	cout << boolalpha;

	/* The following commented statement won't work with Connector/C++ 1.0.5 and later */
	//auto_ptr < DatabaseMetaData > dbcon_meta (dbcon -> getMetaData());

	DatabaseMetaData *dbcon_meta = dbcon -> getMetaData();

	cout << "Database Product Name: " << dbcon_meta -> getDatabaseProductName() << endl;
	cout << "Database Product Version: " << dbcon_meta -> getDatabaseProductVersion() << endl;
	cout << "Database User Name: " << dbcon_meta -> getUserName() << endl << endl;

	cout << "Driver name: " << dbcon_meta -> getDriverName() << endl;
	cout << "Driver version: " << dbcon_meta -> getDriverVersion() << endl << endl;

	cout << "Database in Read-Only Mode?: " << dbcon_meta -> isReadOnly() << endl;
	cout << "Supports Transactions?: " << dbcon_meta -> supportsTransactions() << endl;
	cout << "Supports DML Transactions only?: " << dbcon_meta -> supportsDataManipulationTransactionsOnly() << endl;
	cout << "Supports Batch Updates?: " << dbcon_meta -> supportsBatchUpdates() << endl;
	cout << "Supports Outer Joins?: " << dbcon_meta -> supportsOuterJoins() << endl;
	cout << "Supports Multiple Transactions?: " << dbcon_meta -> supportsMultipleTransactions() << endl;
	cout << "Supports Named Parameters?: " << dbcon_meta -> supportsNamedParameters() << endl;
	cout << "Supports Statement Pooling?: " << dbcon_meta -> supportsStatementPooling() << endl;
	cout << "Supports Stored Procedures?: " << dbcon_meta -> supportsStoredProcedures() << endl;
	cout << "Supports Union?: " << dbcon_meta -> supportsUnion() << endl << endl;

	cout << "Maximum Connections: " << dbcon_meta -> getMaxConnections() << endl;
	cout << "Maximum Columns per Table: " << dbcon_meta -> getMaxColumnsInTable() << endl;
	cout << "Maximum Columns per Index: " << dbcon_meta -> getMaxColumnsInIndex() << endl;
	cout << "Maximum Row Size per Table: " << dbcon_meta -> getMaxRowSize() << " bytes" << endl;

	cout << "\nDatabase schemas: " << endl;

	auto_ptr < ResultSet > rs ( dbcon_meta -> getSchemas());

	cout << "\nTotal number of schemas = " << rs -> rowsCount() << endl;
	cout << endl;

	int row = 1;

	while (rs -> next()) {
		cout << "\t" << row << ". " << rs -> getString("TABLE_SCHEM") << endl;
		++row;
	} // while

	cout << endl << endl;

} // retrieve_dbmetadata_and_print()

static void retrieve_rsmetadata_and_print (ResultSet *rs) {

	if (rs -> rowsCount() == 0) {
		throw runtime_error("ResultSetMetaData FAILURE - no records in the result set");
	}

	cout << "ResultSet Metadata" << endl;
	cout << "------------------" << endl;

	/* The following commented statement won't work with Connector/C++ 1.0.5 and later */
	//auto_ptr < ResultSetMetaData > res_meta ( rs -> getMetaData() );

	ResultSetMetaData *res_meta = rs -> getMetaData();

	int numcols = res_meta -> getColumnCount();
	cout << "\nNumber of columns in the result set = " << numcols << endl << endl;

	cout.width(20);
	cout << "Column Name/Label";
	cout.width(20);
	cout << "Column Type";
	cout.width(20);
	cout << "Column Size" << endl;

	for (int i = 0; i < numcols; ++i) {
		cout.width(20);
		cout << res_meta -> getColumnLabel (i+1);
		cout.width(20); 
		cout << res_meta -> getColumnTypeName (i+1);
		cout.width(20); 
		cout << res_meta -> getColumnDisplaySize (i+1) << endl << endl;
	}

	cout << "\nColumn \"" << res_meta -> getColumnLabel(1);
	cout << "\" belongs to the Table: \"" << res_meta -> getTableName(1);
	cout << "\" which belongs to the Schema: \"" << res_meta -> getSchemaName(1) << "\"" << endl << endl;

} // retrieve_rsmetadata_and_print()


int main(int argc, const char *argv[]) {

	Driver *driver;
	Connection *con;
	Statement *stmt;
	ResultSet *res;
	PreparedStatement *prep_stmt;
	Savepoint *savept;

	int updatecount = 0;
	int zoid;

	/* initiate url, user, password and database variables */
	string url(argc >= 2 ? argv[1] : DBHOST);
	const string user(argc >= 3 ? argv[2] : USER);
	const string password(argc >= 4 ? argv[3] : PASSWORD);
	const string database(argc >= 5 ? argv[4] : DATABASE);

	try {
		driver = get_driver_instance();
		
		/* create a database connection using the Driver */
		con = driver -> connect(url, user, password);

		/* alternate syntax using auto_ptr to create the db connection */
		//auto_ptr  con (driver -> connect(url, user, password));

		/* turn off the autocommit */
		con -> setAutoCommit(0);

		cout << "\nDatabase connection\'s autocommit mode = " << con -> getAutoCommit() << endl;

		/* select appropriate database schema */
		con -> setSchema(database);

		/* retrieve and display the database metadata */
		retrieve_dbmetadata_and_print (con);

		/* create a statement object */
		stmt = con -> createStatement();

		//cout << "Executing the Query: \"SELECT zoid FROM class_ids where class_id='greg-barber'\" .." << endl;
		cout << "Executing the Query: \"SELECT zoid FROM class_ids where class_name='BaseUnit' and class_id='verbage'\" .." << endl;

		/* run a query which returns exactly one result set */
		//res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_id='greg-barber'");
		res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_name='BaseUnit' and class_id='wordage'");

		cout << "Retrieving the result set .." << endl;

		/* retrieve the data from the result set and display on stdout */
		retrieve_data_and_print (res, NUMOFFSET, 1, string("zoid"));

		/* retrieve and display the result set metadata */
		retrieve_rsmetadata_and_print (res);

		/* re-use result set object */
		res = NULL;
		//res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_id='greg-barber'");
		res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_name='BaseUnit' and class_id='wordage'");


		/* retrieve the data from the result set and display on stdout */
		//retrieve_data_and_print (res, COLNAME, 1, string ("zoid"));
		zoid = retrieve_zoid(res, COLNAME, 1, string ("zoid"));

		printf("%i\n",zoid);
		cout << zoid;

		res = NULL;
		char newquery[200];
		sprintf(newquery,"Select state from object_state where zoid=%i;",zoid);
		res = stmt -> executeQuery (newquery);

		retrieve_state(res, COLNAME, 1, string ("state"));

		cout << "Cleaning up the resources .." << endl;

		/* Clean up */
		delete res;
		delete stmt;
		delete prep_stmt;
		con -> close();
		delete con;

	} catch (SQLException &e) {
		cout << "ERROR: SQLException in " << __FILE__;
		cout << " (" << __func__<< ") on line " << __LINE__ << endl;
		cout << "ERROR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << ")" << endl;

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			cout << "\nYour server does not seem to support Prepared Statements at all. ";
			cout << "Perhaps MYSQL < 4.1?" << endl;
		}

		return EXIT_FAILURE;
	} catch (std::runtime_error &e) {

		cout << "ERROR: runtime_error in " << __FILE__;
		cout << " (" << __func__ << ") on line " << __LINE__ << endl;
		cout << "ERROR: " << e.what() << endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
} // main()
