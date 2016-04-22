#include "pickle.h"


Opcode::Opcode(char opcodeChar,const char *desc,fn funct,op_print opr)
{
    this->opcode = opcodeChar;
    this->opfunc = funct;
    this->opr = opr;
    strcpy(this->desc,(const char *)desc);
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
char* Opcode::getDescription()
{
	return this->desc;
}
Pickle::Pickle()
{
    opcodes[GLOBAL1] = new Opcode('~',"GLOBAL1",Opcode::fnGLOBAL1,Opcode::oprGLOBAL1);
    opcodes[GLOBAL2] = new Opcode('!',"GLOBAL2",Opcode::fnGLOBAL2,Opcode::oprGLOBAL2);
    opcodes[STOP] = new Opcode('.',"STOP",Opcode::fnSTOP,Opcode::oprSTOP);
    opcodes[MARK] = new Opcode('(',"MARK",Opcode::fnMARK,Opcode::oprMARK);
    opcodes[POP] = new Opcode('0',"POP",Opcode::fnPOP,Opcode::oprPOP);
    opcodes[POP_MARK] = new Opcode('1',"POP_MARK",Opcode::fnPOP_MARK,Opcode::oprPOP_MARK);
    opcodes[DUP] = new Opcode('2',"DUP",Opcode::fnDUP,Opcode::oprDUP);
    opcodes[FLOAT] = new Opcode('F',"FLOAT",Opcode::fnFLOAT,Opcode::oprFLOAT);
    opcodes[INT] = new Opcode('I',"INT",Opcode::fnINT,Opcode::oprINT);
    opcodes[BININT] = new Opcode('J',"BININT",Opcode::fnBININT,Opcode::oprBININT);
    opcodes[BININT2] = new Opcode('M',"BININT2",Opcode::fnBININT2,Opcode::oprBININT2);
    opcodes[LLONG] = new Opcode('L',"LLONG",Opcode::fnLONG,Opcode::oprLONG);
    opcodes[NONE] = new Opcode('N',"NONE",Opcode::fnNONE,Opcode::oprNONE);
    opcodes[PERSID] = new Opcode('P',"PERSID",Opcode::fnPERSID,Opcode::oprPERSID);
    opcodes[BINPERSID] = new Opcode('Q',"BINPERSID",Opcode::fnBINPERSID,Opcode::oprBINPERSID);
    opcodes[REDUCE] = new Opcode('R',"REDUCE",Opcode::fnREDUCE,Opcode::oprREDUCE);
    opcodes[STRING] = new Opcode('S',"STRING",Opcode::fnSTRING,Opcode::oprSTRING);
    opcodes[BINSTRING] = new Opcode('T',"BINSTRING",Opcode::fnBINSTRING,Opcode::oprBINSTRING);
    opcodes[SHORT_BINSTRING] = new Opcode('U',"SHORT_BINSTRING",Opcode::fnSHORT_BINSTRING,Opcode::oprSHORT_BINSTRING);
    opcodes[UNICODE] = new Opcode('V',"UNICODE",Opcode::fnUNICODE,Opcode::oprUNICODE);
    opcodes[BINUNICODE] = new Opcode('X',"BINUNICODE",Opcode::fnBINUNICODE,Opcode::oprBINUNICODE);
    opcodes[APPEND] = new Opcode('a',"APPEND",Opcode::fnAPPEND,Opcode::oprAPPEND);  
    opcodes[BUILD] = new Opcode('b',"BUILD",Opcode::fnBUILD,Opcode::oprBUILD);  
    opcodes[GLOBAL] = new Opcode('c',"GLOBAL",Opcode::fnGLOBAL,Opcode::oprGLOBAL);
    opcodes[DICT] = new Opcode('d',"DICT",Opcode::fnDICT,Opcode::oprDICT);
    opcodes[EMPTY_DICT] = new Opcode('}',"EMPTY_DICT",Opcode::fnEMPTY_DICT,Opcode::oprEMPTY_DICT);
    opcodes[APPENDS] = new Opcode('e',"APPENDS",Opcode::fnAPPENDS,Opcode::oprAPPENDS);
    opcodes[GET] = new Opcode('g',"GET",Opcode::fnGET,Opcode::oprGET);    
    opcodes[BINGET] = new Opcode('h',"BINGET",Opcode::fnBINGET,Opcode::oprBINGET);
    opcodes[INST] = new Opcode('i',"INST",Opcode::fnINST,Opcode::oprINST); 
    opcodes[LONG_BINGET] = new Opcode('j',"LONG_BINGET",Opcode::fnLONG_BINGET,Opcode::oprLONG_BINGET);
    opcodes[LIST] = new Opcode('l',"LIST",Opcode::fnLIST,Opcode::oprLIST);     
    opcodes[EMPTY_LIST] = new Opcode(']',"EMPTY_LIST",Opcode::fnEMPTY_LIST,Opcode::oprEMPTY_LIST);
    opcodes[OBJ] = new Opcode('o',"OBJ",Opcode::fnOBJ,Opcode::oprOBJ);     
    opcodes[PUT] = new Opcode('p',"PUT",Opcode::fnPUT,Opcode::oprPUT);    
    opcodes[BINPUT] = new Opcode('q',"BINPUT",Opcode::fnBINPUT,Opcode::oprBINPUT);
    opcodes[LONG_BINPUT] = new Opcode('r',"LONG_BINPUT",Opcode::fnLONG_BINPUT,Opcode::oprLONG_BINPUT);
    opcodes[SETITEM] = new Opcode('s',"SETITEM",Opcode::fnSETITEM,Opcode::oprSETITEM);  
    opcodes[TUPLE] = new Opcode('t',"TUPLE",Opcode::fnTUPLE,Opcode::oprTUPLE);   
    opcodes[EMPTY_TUPLE] = new Opcode(')',"EMPTY_TUPLE",Opcode::fnEMPTY_TUPLE,Opcode::oprEMPTY_TUPLE);
    opcodes[SETITEMS] = new Opcode('u',"SETITEMS",Opcode::fnSETITEMS,Opcode::oprSETITEMS); 
    opcodes[BINFLOAT] = new Opcode('G',"BINFLOAT",Opcode::fnBINFLOAT,Opcode::oprBINFLOAT);
    opcodes[PROTO] = new Opcode('\x80',"PROTO",Opcode::fnPROTO,Opcode::oprPROTO);  
    opcodes[NEWOBJ] = new Opcode('\x81',"NEWOBJ",Opcode::fnNEWOBJ,Opcode::oprNEWOBJ);
    opcodes[EXT1] = new Opcode('\x82',"EXT1",Opcode::fnEXT1,Opcode::oprEXT1);
    opcodes[EXT2] = new Opcode('\x83',"EXT2",Opcode::fnEXT2,Opcode::oprEXT2);
    opcodes[EXT4] = new Opcode('\x84',"EXT4",Opcode::fnEXT4,Opcode::oprEXT4);
    opcodes[TUPLE1] = new Opcode('\x85',"TUPLE1",Opcode::fnTUPLE1,Opcode::oprTUPLE1);
    opcodes[TUPLE2] = new Opcode('\x86',"TUPLE2",Opcode::fnTUPLE2,Opcode::oprTUPLE2);
    opcodes[TUPLE3] = new Opcode('\x87',"TUPLE3",Opcode::fnTUPLE3,Opcode::oprTUPLE3);
    opcodes[TRUE] = new Opcode('\x88',"TRUE",Opcode::fnTRUE,Opcode::oprTRUE);
    opcodes[FALSE] = new Opcode('\x89',"FALSE",Opcode::fnFALSE,Opcode::oprFALSE);
    opcodes[LONG1] = new Opcode('\x8a',"LONG1",Opcode::fnLONG1,Opcode::oprLONG1);
    opcodes[LONG4] = new Opcode('\x8b',"LONG4",Opcode::fnLONG4,Opcode::oprLONG4);
}
// These are Dummy Opcodes
int Opcode::fnGLOBAL1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
}
int Opcode::fnGLOBAL2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
}
// push special markobject on stack
int Opcode::fnMARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	int forward;
	forward = 0;
	std::string strMARK;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	putItem->allocateSpaceOnStack();
	theStack.push(*putItem);
	*/
	
	return forward;
}
// every pickle ends with STOP
int Opcode::fnSTOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
        std:string binput;
        //cout << "STOP";
        it1++;
        int forward = 1;
        //cout << endl;
        return forward;
}
// discard topmost stack item
int Opcode::fnPOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "POP";
        //cout << endl;
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "POP_MARK";
        //cout << endl;
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "DUP";
        //cout << endl;
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "FLOAT";
	return 0;
}
int Opcode::fnINT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
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
int Opcode::fnBININT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BININT";
        //cout << endl;
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BININT1";
        //cout << endl;
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LONG";
        //cout << endl;
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BININT2";
        //cout << endl;
	return 0;
}
// push None
int Opcode::fnNONE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "NONE";
        //cout << endl;
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
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
int Opcode::fnBINPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BINPERSID";
	//cout << endl;
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	int forward;
	forward = 0;
	std::string strREDUCE;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack.push(*putItem);
	*/
	
	return forward;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	StackItem *stringItem;
	std::string strString;
	int countApostrophe = 0;
	int forward = 1;
	char *ptr;
	char *buf;
	int len;
	buf = (char*)emalloc(sizeof(char)*200);
	ptr = buf;
	len = 0;
	while (it1 != str1.end() && *it1 != '\177')
        {
	     *ptr++ = *it1;
	     len++;
	     it1++;
	     forward++;
	}
	it1--;
	stringItem = theStack.pop();
	stringItem->someString=(char*)emalloc(sizeof(char)*(len+1));
	strcpy(stringItem->someString,buf);
	efree(buf);
	theStack.push(*stringItem);
	return forward;
}
// push string; counted binary string argument
int Opcode::fnBINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BINSTRING";
	//cout << endl;
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
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
int Opcode::fnUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "UNICODE";
	//cout << endl;
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BINUNICODE";
	//cout << endl;
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack) 
{
	//cout << "APPEND";
	//cout << endl;
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BUILD";
	//cout << endl;
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	StackItem *moduleItem,*nameItem;
	std::string state;
	std::string module;
	std::string name;
	int countNewline = 0;
	int forward = 1;
	it1++;
	moduleItem = (StackItem*)emalloc(sizeof(StackItem));
	char *ptr;
	char *buf;
	buf = (char*)malloc(sizeof(char)*200);
	ptr = buf;
	int len;
	len = 0;
	while (it1 < str1.end() && *it1 != '\000')
        {
	     int item;
	     *ptr++ = *it1;
	     it1++;
	     forward++;
	     len++;
	}
	*ptr = '\0';
	// Push new Class onto the Stack
	moduleItem->someString=(char*)emalloc(sizeof(char)*(len+1));
	strcpy(moduleItem->someString,buf);
	free(buf);
	moduleItem->opcode = '!';
	theStack.push(*moduleItem);
	getline(instream,state);
	std::string::iterator it;
	int j = 0;
	it = state.begin();
	nameItem = (StackItem*)emalloc(sizeof(StackItem));
	buf = (char*)malloc(sizeof(char)*200);
	ptr = buf;
	len = 0;
	while (it < state.end())
        {
	     *ptr++ = *it;
	     it++;
	     forward++;
	     len++;
	}
	nameItem->someString=(char*)emalloc(sizeof(char)*(len+1));
	strcpy(nameItem->someString,buf);
	free(buf);
	nameItem->opcode = '~';
	theStack.push(*nameItem);
    	return 0;
}
// build a dict from stack Stack
int Opcode::fnDICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	int forward;
	forward = 0;
	std::string strDICT;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack.push(*putItem);
	*/
	
	return forward;
}
// push empty dict
int Opcode::fnEMPTY_DICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
        std:string binput;
        it1++;
        int forward = 1;
        //cout << "EMPTY_DICT";
        //cout << endl;
        return forward;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "APPENDS";
	//cout << endl;
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	std::string strPut;
	char theInt[10];
	int countNewline = 0;
	int forward = 0;
	while (it1 < str1.end())
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
	putItem= theStack.pop();
	putItem->someInt = atoi(theInt);
	theStack.push(*putItem);
	
	return forward;
}
//   "    "    "    "   "   "  ;   "    " 1-byte arg
int Opcode::fnBINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "BINGET";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnINST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack) 
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
int Opcode::fnLONG_BINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LONG_BINGET";
	//cout << endl;
	return 0;
}
// build list from topmost stack Stack
int Opcode::fnLIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LIST";
	//cout << endl;
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "EMPTY_LIST";
	//cout << endl;
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack) 
{
	//cout << "OBJ";
	//cout << endl;
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)    
{
	std::string strPut;
	char theInt[10];
	int countNewline = 0;
	int forward = 0;
	while (it1 < str1.end())
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
	putItem= theStack.pop();
	putItem->someInt = atoi(theInt);
	theStack.push(*putItem);
	
	return forward;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
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
int Opcode::fnLONG_BINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LONG_BINPUT";
	//cout << endl;
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	int forward;
	forward = 0;
	std::string strSETITEM;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack.push(*putItem);
	*/
	
	return forward;
}
// build tuple from topmost stack Stack
int Opcode::fnTUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	int forward;
	forward = 0;
	std::string strTUPLE;
	it1++;
	forward++;
	/*
	putItem= theStack->pop();
	theStack.push(*putItem);
	*/
	
	return forward;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "EMPTY_TUPLE";
	//cout << endl;
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "SETITEMS";
	//cout << endl;
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
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
int Opcode::fnPROTO(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "PROTO";
	//cout << endl;
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "NEWOBJ";
	//cout << endl;
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack) 
{
	//cout << "EXT1";
	//cout << endl;
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "EXT2";
	//cout << endl;
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "EXT4";
	//cout << endl;
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "TUPLE1";
	//cout << endl;
	return 0;
}
// build 2-tuple from two topmost stack Stack
int Opcode::fnTUPLE2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "TUPLE2";
	//cout << endl;
	return 0;
}
// build 3-tuple from three topmost stack Stack
int Opcode::fnTUPLE3(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "TUPLE3";
	//cout << endl;
	return 0;
}
// push True
int Opcode::fnTRUE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "TRUE";
	//cout << endl;
	return 0;
}
// push False
int Opcode::fnFALSE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "FALSE";
	//cout << endl;
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LONG1";
	//cout << endl;
	return 0;
}
// push really big long
int Opcode::fnLONG4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack)
{
	//cout << "LONG4";
	//cout << endl;
	return 0;
}
// These are the print functions for the dummy opcodes, part of GLOBAL
int Opcode::oprGLOBAL1(zval* subarray,StackItem* stackitem, int depth) {
	char somestring[100];
	sprintf(somestring,"name: %s",stackitem->someString);
	add_next_index_string(subarray,somestring,1);
}
int Opcode::oprGLOBAL2(zval* subarray,StackItem* stackitem, int depth) {
	char somestring[100];
	sprintf(somestring,"module: %s",stackitem->someString);
	add_next_index_string(subarray,somestring,1);
}
int Opcode::oprSTOP(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprMARK(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprPOP(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprPOP_MARK(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprDUP(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprFLOAT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprINT(zval* subarray,StackItem* stackitem, int depth) {
	add_next_index_long(subarray,stackitem->someInt);
}
int Opcode::oprBININT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprBININT1(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprLONG(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprBININT2(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprNONE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprPERSID(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprBINPERSID(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprREDUCE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprSTRING(zval* subarray,StackItem* stackitem, int depth) {
	char somestring[100];
	sprintf(somestring,"module: %s",stackitem->someString);
	add_next_index_string(subarray,somestring,1);
}
int Opcode::oprBINSTRING(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprSHORT_BINSTRING(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprUNICODE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprBINUNICODE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprAPPEND(zval* subarray,StackItem* stackitem, int depth) {  
}
int Opcode::oprBUILD(zval* subarray,StackItem* stackitem, int depth) {  
}
int Opcode::oprGLOBAL(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprDICT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprEMPTY_DICT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprAPPENDS(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprGET(zval* subarray,StackItem* stackitem, int depth) {    
}
int Opcode::oprBINGET(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprINST(zval* subarray,StackItem* stackitem, int depth) { 
}
int Opcode::oprLONG_BINGET(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprLIST(zval* subarray,StackItem* stackitem, int depth) {     
}
int Opcode::oprEMPTY_LIST(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprOBJ(zval* subarray,StackItem* stackitem, int depth) {     
}
int Opcode::oprPUT(zval* subarray,StackItem* stackitem, int depth) {    
	add_next_index_long(subarray,stackitem->someInt);
}
int Opcode::oprBINPUT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprLONG_BINPUT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprSETITEM(zval* subarray,StackItem* stackitem, int depth) {  
}
int Opcode::oprTUPLE(zval* subarray,StackItem* stackitem, int depth) {   
}
int Opcode::oprEMPTY_TUPLE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprSETITEMS(zval* subarray,StackItem* stackitem, int depth) { 
}
int Opcode::oprBINFLOAT(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprPROTO(zval* subarray,StackItem* stackitem, int depth) {  
}
int Opcode::oprNEWOBJ(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprEXT1(zval* subarray,StackItem* stackitem, int depth) { 
}
int Opcode::oprEXT2(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprEXT4(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprTUPLE1(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprTUPLE2(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprTUPLE3(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprTRUE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprFALSE(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprLONG1(zval* subarray,StackItem* stackitem, int depth) {
}
int Opcode::oprLONG4(zval* subarray,StackItem* stackitem, int depth) {
}
