#include "stackitem.h"
#include "pickle.h"


Opcode::Opcode(char opcodeChar,const char *desc,fn funct)
{
    this->opcode = opcodeChar;
    this->opfunc = funct;
    this->desc = (char*)malloc(sizeof(char)*strlen(desc)+1);
    sprintf(this->desc,"%s",desc);
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
    opcodes[STOP] = new Opcode('.',"STOP",Opcode::fnSTOP);
    opcodes[MARK] = new Opcode('(',"MARK",Opcode::fnMARK);
    opcodes[POP] = new Opcode('0',"POP",Opcode::fnPOP);
    opcodes[POP_MARK] = new Opcode('1',"POP_MARK",Opcode::fnPOP_MARK);
    opcodes[DUP] = new Opcode('2',"DUP",Opcode::fnDUP);
    opcodes[FLOAT] = new Opcode('F',"FLOAT",Opcode::fnFLOAT);
    opcodes[INT] = new Opcode('I',"INT",Opcode::fnINT);
    opcodes[BININT] = new Opcode('J',"BININT",Opcode::fnBININT);
    opcodes[BININT2] = new Opcode('M',"BININT2",Opcode::fnBININT2);
    opcodes[LLONG] = new Opcode('L',"LLONG",Opcode::fnLONG);
    opcodes[NONE] = new Opcode('N',"NONE",Opcode::fnNONE);
    opcodes[PERSID] = new Opcode('P',"PERSID",Opcode::fnPERSID);
    opcodes[BINPERSID] = new Opcode('Q',"BINPERSID",Opcode::fnBINPERSID);
    opcodes[REDUCE] = new Opcode('R',"REDUCE",Opcode::fnREDUCE);
    opcodes[STRING] = new Opcode('S',"STRING",Opcode::fnSTRING);
    opcodes[BINSTRING] = new Opcode('T',"BINSTRING",Opcode::fnBINSTRING);
    opcodes[SHORT_BINSTRING] = new Opcode('U',"SHORT_BINSTRING",Opcode::fnSHORT_BINSTRING);
    opcodes[UNICODE] = new Opcode('V',"UNICODE",Opcode::fnUNICODE);
    opcodes[BINUNICODE] = new Opcode('X',"BINUNICODE",Opcode::fnBINUNICODE);
    opcodes[APPEND] = new Opcode('a',"APPEND",Opcode::fnAPPEND);  
    opcodes[BUILD] = new Opcode('b',"BUILD",Opcode::fnBUILD);  
    opcodes[GLOBAL] = new Opcode('c',"GLOBAL",Opcode::fnGLOBAL);
    opcodes[DICT] = new Opcode('d',"DICT",Opcode::fnDICT);
    opcodes[EMPTY_DICT] = new Opcode('}',"EMPTY_DICT",Opcode::fnEMPTY_DICT);
    opcodes[APPENDS] = new Opcode('e',"APPENDS",Opcode::fnAPPENDS);
    opcodes[GET] = new Opcode('g',"GET",Opcode::fnGET);    
    opcodes[BINGET] = new Opcode('h',"BINGET",Opcode::fnBINGET);
    opcodes[INST] = new Opcode('i',"INST",Opcode::fnINST); 
    opcodes[LONG_BINGET] = new Opcode('j',"LONG_BINGET",Opcode::fnLONG_BINGET);
    opcodes[LIST] = new Opcode('l',"LIST",Opcode::fnLIST);     
    opcodes[EMPTY_LIST] = new Opcode(']',"EMPTY_LIST",Opcode::fnEMPTY_LIST);
    opcodes[OBJ] = new Opcode('o',"OBJ",Opcode::fnOBJ);     
    opcodes[PUT] = new Opcode('p',"PUT",Opcode::fnPUT);    
    opcodes[BINPUT] = new Opcode('q',"BINPUT",Opcode::fnBINPUT);
    opcodes[LONG_BINPUT] = new Opcode('r',"LONG_BINPUT",Opcode::fnLONG_BINPUT);
    opcodes[SETITEM] = new Opcode('s',"SETITEM",Opcode::fnSETITEM);  
    opcodes[TUPLE] = new Opcode('t',"TUPLE",Opcode::fnTUPLE);   
    opcodes[EMPTY_TUPLE] = new Opcode(')',"EMPTY_TUPLE",Opcode::fnEMPTY_TUPLE);
    opcodes[SETITEMS] = new Opcode('u',"SETITEMS",Opcode::fnSETITEMS); 
    opcodes[BINFLOAT] = new Opcode('G',"BINFLOAT",Opcode::fnBINFLOAT);
    opcodes[PROTO] = new Opcode('\x80',"PROTO",Opcode::fnPROTO);  
    opcodes[NEWOBJ] = new Opcode('\x81',"NEWOBJ",Opcode::fnNEWOBJ);
    opcodes[EXT1] = new Opcode('\x82',"EXT1",Opcode::fnEXT1);
    opcodes[EXT2] = new Opcode('\x83',"EXT2",Opcode::fnEXT2);
    opcodes[EXT4] = new Opcode('\x84',"EXT4",Opcode::fnEXT4);
    opcodes[TUPLE1] = new Opcode('\x85',"TUPLE1",Opcode::fnTUPLE1);
    opcodes[TUPLE2] = new Opcode('\x86',"TUPLE2",Opcode::fnTUPLE2);
    opcodes[TUPLE3] = new Opcode('\x87',"TUPLE3",Opcode::fnTUPLE3);
    opcodes[TRUE] = new Opcode('\x88',"TRUE",Opcode::fnTRUE);
    opcodes[FALSE] = new Opcode('\x89',"FALSE",Opcode::fnFALSE);
    opcodes[LONG1] = new Opcode('\x8a',"LONG1",Opcode::fnLONG1);
    opcodes[LONG4] = new Opcode('\x8b',"LONG4",Opcode::fnLONG4);
}

// push special markobject on stack
int Opcode::fnMARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int forward;
	forward = 0;
	printf("Process MARK\n");
	std::string strMARK;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	putItem->allocateSpaceOnStack();
	theStack->push(*putItem);
	*/
	printf("MARK\n");
	
	return forward;
}
// every pickle ends with STOP
int Opcode::fnSTOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
        //cout << "STOP";
        it1++;
        int forward = 1;
        //cout << endl;
        return forward;
}
// discard topmost stack item
int Opcode::fnPOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "POP";
        //cout << endl;
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "POP_MARK";
        //cout << endl;
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "DUP";
        //cout << endl;
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "FLOAT";
	return 0;
}
int Opcode::fnINT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnBININT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT";
        //cout << endl;
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT1";
        //cout << endl;
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG";
        //cout << endl;
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BININT2";
        //cout << endl;
	return 0;
}
// push None
int Opcode::fnNONE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "NONE";
        //cout << endl;
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnBINPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINPERSID";
	//cout << endl;
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int forward;
	forward = 0;
	printf("Process REDUCE\n");
	std::string strREDUCE;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack->push(*putItem);
	*/
	printf("REDUCE\n");
	
	return forward;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnBINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINSTRING";
	//cout << endl;
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "UNICODE";
	//cout << endl;
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINUNICODE";
	//cout << endl;
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "APPEND";
	//cout << endl;
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BUILD";
	//cout << endl;
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	printf("Process GLOBAL\n");
	std::string state;
	std::string module;
	std::string name;
	int countNewline = 0;
	it1++;
	int forward = 1;
	while (it1 != str1.end())
        {
	     int item;
	     item = *it1;
	     module.append(sizeof(char),*it1);
	     it1++;
	     forward++;
	}
	// Push new Class onto the Stack
	StackItem *moduleItem,*nameItem;
	moduleItem = theStack->pop();
	strcpy(moduleItem->someString,module.c_str());
	printf("%s\n",moduleItem->someString);
	theStack->push(*moduleItem);
	getline(instream,state);
	std::string::iterator it;
	int j = 0;
	it = state.begin();
	nameItem = (StackItem*)malloc(sizeof(StackItem));
	while (it != state.end())
        {
	     int item;
	     item = *it;
	     name.append(sizeof(char),*it);
	     it++;
	     j++;
	     forward++;
	}
	strcpy(nameItem->someString,name.c_str());
	printf("%s\n",nameItem->someString);
	theStack->push(*nameItem);

    	return 0;
}
// build a dict from stack Stack
int Opcode::fnDICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int forward;
	forward = 0;
	printf("Process DICT\n");
	std::string strDICT;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack->push(*putItem);
	*/
	printf("DICT\n");
	
	return forward;
}
// push empty dict
int Opcode::fnEMPTY_DICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
        std:string binput;
        it1++;
        int forward = 1;
        //cout << "EMPTY_DICT";
        //cout << endl;
        return forward;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "APPENDS";
	//cout << endl;
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnBINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "BINGET";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnINST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
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
int Opcode::fnLONG_BINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG_BINGET";
	//cout << endl;
	return 0;
}
// build list from topmost stack Stack
int Opcode::fnLIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LIST";
	//cout << endl;
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EMPTY_LIST";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "OBJ";
	//cout << endl;
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)    
{
	printf("Process PUT\n");
	std::string strPut;
	char theInt[10];
	int countNewline = 0;
	int forward = 1;
	it1++;
	while (it1 != str1.end() && countNewline < 1)
        {
	     int item;
	     item = *it1;
	     strPut.append(sizeof(char),*it1);
	     it1++;
	     forward++;
	}
	sprintf(theInt,"%s",strPut.c_str());
	// Push new Class onto the Stack
	StackItem *putItem;
	putItem= theStack->pop();
	putItem->someInt = atoi(theInt);
	theStack->push(*putItem);
	printf("PUT: %s\n",strPut.c_str());
	
	return forward;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnLONG_BINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG_BINPUT";
	//cout << endl;
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int forward;
	forward = 0;
	printf("Process SETITEM\n");
	std::string strSETITEM;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack->push(*putItem);
	*/
	printf("SETITEM\n");
	
	return forward;
}
// build tuple from topmost stack Stack
int Opcode::fnTUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	int forward;
	forward = 0;
	printf("Process TUPLE\n");
	std::string strTUPLE;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack->push(*putItem);
	*/
	printf("TUPLE\n");
	
	return forward;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EMPTY_TUPLE";
	//cout << endl;
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "SETITEMS";
	//cout << endl;
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
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
int Opcode::fnPROTO(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "PROTO";
	//cout << endl;
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "NEWOBJ";
	//cout << endl;
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack) 
{
	//cout << "EXT1";
	//cout << endl;
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EXT2";
	//cout << endl;
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "EXT4";
	//cout << endl;
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE1";
	//cout << endl;
	return 0;
}
// build 2-tuple from two topmost stack Stack
int Opcode::fnTUPLE2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE2";
	//cout << endl;
	return 0;
}
// build 3-tuple from three topmost stack Stack
int Opcode::fnTUPLE3(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TUPLE3";
	//cout << endl;
	return 0;
}
// push True
int Opcode::fnTRUE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "TRUE";
	//cout << endl;
	return 0;
}
// push False
int Opcode::fnFALSE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "FALSE";
	//cout << endl;
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG1";
	//cout << endl;
	return 0;
}
// push really big long
int Opcode::fnLONG4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack)
{
	//cout << "LONG4";
	//cout << endl;
	return 0;
}
