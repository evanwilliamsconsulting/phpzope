#include "stackitem.h"
#include "pickle.h"


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
int Opcode::fnMARK(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
        //cout << "MARK";
        int forward = 1;
        //cout << endl;
        return forward;
}
// every pickle ends with STOP
int Opcode::fnSTOP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
        //cout << "STOP";
        it1++;
        int forward = 1;
        //cout << endl;
        return forward;
}
// discard topmost stack item
int Opcode::fnPOP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "POP";
        //cout << endl;
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "POP_MARK";
        //cout << endl;
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "DUP";
        //cout << endl;
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "FLOAT";
	return 0;
}
int Opcode::fnINT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	std::string strInt;
	it1++;
	while (*it1 != '|')
	{
		strInt.append(sizeof(char),*it1);
		it1++;
	}
	//cout << "INT";
	//cout << strInt;
        //cout << endl;
	return 0;
}
// push four-byte signed int
int Opcode::fnBININT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT";
        //cout << endl;
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT1";
        //cout << endl;
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG";
        //cout << endl;
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT2";
        //cout << endl;
	return 0;
}
// push None
int Opcode::fnNONE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "NONE";
        //cout << endl;
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	std::string pid;
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 1)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '|')
             {
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
        //cout << "PERSID";
	//cout << endl;
	
	return forward;
}
int Opcode::fnBINPERSID(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINPERSID";
	//cout << endl;
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "REDUCE";
	//cout << endl;
	return 0;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	std::string strString;
	int countApostrophe = 0;
	int forward = 1;
	while (it1 != str1.end() && countApostrophe < 2)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '\'')
             {
		countApostrophe++;
	     }
             else
             {
	         strString.append(sizeof(char),*it1);
             }
	     it1++;
	     forward++;
	}
        //cout << "STRING: string:";
	//cout << strString;
	//cout << endl;
	return forward;
}
// push string; counted binary string argument
int Opcode::fnBINSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINSTRING";
	//cout << endl;
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int intBinstring;
	std::string shortBinstring;
        it1++;
        int forward = 1;
	// Next byte contains length
	// Of the binstring to read
        if (it1 != str1.end())
        {
             int item;
             item = *it1;
	     intBinstring = *it1;
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
	//cout << "SHORT_BINSTRING: ";
	//cout << shortBinstring;
        //cout << endl;
        return forward;
}
// push Unicode string; raw-unicode-escaped'd argument
int Opcode::fnUNICODE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "UNICODE";
	//cout << endl;
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINUNICODE";
	//cout << endl;
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "APPEND";
	//cout << endl;
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BUILD";
	//cout << endl;
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	std::string module;
	std::string name;
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 2)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '|')
             {
		if (countNewline == 0)
		{
			((Opcode*)classPtr)->setModule(module);
		}	
		else if (countNewline == 1)
		{
			((Opcode*)classPtr)->setName(name);
			it1--;
		}
		countNewline++;
	     }
             else
             {
		if (countNewline == 0)
		{
			//module.append(sizeof(char),*it1);
		}
		else if (countNewline == 1)
		{
			//name.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++;
	}
	// Push new Class onto the Stack
	string classname;
	classname.append(module);
	classname.append(".");
	classname.append(name);
	StackItem newitem;
	//cout << "Class Name: ";
	//cout << classname;
        //cout << "GLOBAL: name:";
	//cout << name;
	//cout << " module:";
	//cout << module;
	//cout << endl;
	return forward;
}
// build a dict from stack Stack
int Opcode::fnDICT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "DICT";
	//cout << endl;
	return 0;
}
// push empty dict
int Opcode::fnEMPTY_DICT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
        it1++;
        int forward = 1;
        //cout << "EMPTY_DICT";
        //cout << endl;
        return forward;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "APPENDS";
	//cout << endl;
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	std::string strGet;
	int countNewline = 0;
	int forward = 1;
	it1++;
	while (it1 != str1.end() && countNewline < 1)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '|')
             {
		countNewline++;
		break;
	     }
             else
             {
		if (countNewline == 0)
		{
			strGet.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++;
	}
        //cout << "GET: ";
	//cout << strGet;
	//cout << endl;
	
	return forward;
}
//   "    "    "    "   "   "  ;   "    " 1-byte arg
int Opcode::fnBINGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINGET";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnINST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	std::string module;
	std::string name;
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end() && countNewline < 2)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '|')
             {
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
        //cout << "INST";
	//cout << endl;
	
	return forward;
}
// push item from memo on stack; index is 4-byte arg
int Opcode::fnLONG_BINGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG_BINGET";
	//cout << endl;
	return 0;
}
// build list from topmost stack Stack
int Opcode::fnLIST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LIST";
	//cout << endl;
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EMPTY_LIST";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "OBJ";
	//cout << endl;
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)    
{
	std::string strPut;
	int countNewline = 0;
	int forward = 1;
	it1++;
	while (it1 != str1.end() && countNewline < 1)
        {
	     int item;
	     item = *it1;
	     if (*it1 == '|')
             {
		countNewline++;
		break;
	     }
             else
             {
		if (countNewline == 0)
		{
			//strPut.append(sizeof(char),*it1);
		}
             }
	     it1++;
	     forward++;
	}
        //cout << "PUT: ";
	//cout << strPut;
	//cout << endl;
	
	return forward;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
	it1++;
	int forward = 1;
	// This is one byte long
	// As said above ... DUH
	int item;
	item = *it1;
	binput.append(sizeof(char),*it1);
        //cout << "BINPUT: ";
	//cout << binput;
	//cout << endl;
	return forward;
}
//   "     "    "   "   " ;   "    " 4-byte arg
int Opcode::fnLONG_BINPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG_BINPUT";
	//cout << endl;
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	// pop the stack twice
	// form the key and the value
	// open a dictionary
	//cout << "SETITEM";
	//cout << endl;
	return 0;
}
// build tuple from topmost stack Stack
int Opcode::fnTUPLE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE";
	//cout << endl;
	return 0;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EMPTY_TUPLE";
	//cout << endl;
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "SETITEMS";
	//cout << endl;
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINFLOAT";
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	//cout << endl;
	return 0;
}
// identify pickle protocol
int Opcode::fnPROTO(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "PROTO";
	//cout << endl;
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "NEWOBJ";
	//cout << endl;
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "EXT1";
	//cout << endl;
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EXT2";
	//cout << endl;
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EXT4";
	//cout << endl;
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE1";
	//cout << endl;
	return 0;
}
// build 2-tuple from two topmost stack Stack
int Opcode::fnTUPLE2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE2";
	//cout << endl;
	return 0;
}
// build 3-tuple from three topmost stack Stack
int Opcode::fnTUPLE3(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE3";
	//cout << endl;
	return 0;
}
// push True
int Opcode::fnTRUE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TRUE";
	//cout << endl;
	return 0;
}
// push False
int Opcode::fnFALSE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "FALSE";
	//cout << endl;
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG1";
	//cout << endl;
	return 0;
}
// push really big long
int Opcode::fnLONG4(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG4";
	//cout << endl;
	return 0;
}
