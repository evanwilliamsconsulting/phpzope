#include <iostream>
using namespace std;

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

typedef int (*fn)(int);

class Opcode {
        public:
	    char opcode;
	    fn opfunc;
            Opcode(char opcodeChar,fn funct);
            static int fnSTOP(int a);
	    static int fnMARK(int a);
            static int fnPOP(int a);
            static int fnPOP_MARK(int a);
            static int fnDUP(int a);
            static int fnFLOAT(int a);
            static int fnINT(int a);
            static int fnBININT(int a);
            static int fnBININT1(int a);
            static int fnLONG(int a);
            static int fnBININT2(int a);
            static int fnNONE(int a);
            static int fnPERSID(int a);
            static int fnBINPERSID(int a);
            static int fnREDUCE(int a);
            static int fnSTRING(int a);
            static int fnBINSTRING(int a);
            static int fnSHORT_BINSTRING(int a);
            static int fnUNICODE(int a);
            static int fnBINUNICODE(int a);
            static int fnAPPEND(int a);  
            static int fnBUILD(int a);  
            static int fnGLOBAL(int a);
            static int fnDICT(int a);
            static int fnEMPTY_DICT(int a);
            static int fnAPPENDS(int a);
            static int fnGET(int a);    
            static int fnBINGET(int a);
            static int fnINST(int a); 
            static int fnLONG_BINGET(int a);
            static int fnLIST(int a);     
            static int fnEMPTY_LIST(int a);
            static int fnOBJ(int a);     
            static int fnPUT(int a);    
            static int fnBINPUT(int a);
            static int fnLONG_BINPUT(int a);
            static int fnSETITEM(int a);  
            static int fnTUPLE(int a);   
            static int fnEMPTY_TUPLE(int a);
            static int fnSETITEMS(int a); 
            static int fnBINFLOAT(int a);
            static int fnPROTO(int a);  
            static int fnNEWOBJ(int a);
            static int fnEXT1(int a); 
            static int fnEXT2(int a);
            static int fnEXT4(int a);
            static int fnTUPLE1(int a);
            static int fnTUPLE2(int a);
            static int fnTUPLE3(int a);
            static int fnTRUE(int a);
            static int fnFALSE(int a);
            static int fnLONG1(int a);
            static int fnLONG4(int a);
};

Opcode::Opcode(char opcodeChar,fn funct)
{
    this->opcode = opcodeChar;
    this->opfunc = funct;
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
int Opcode::fnMARK(int a)
{
	return 0;
}
// every pickle ends with STOP
int Opcode::fnSTOP(int a)
{
	return 0;
}
// discard topmost stack item
int Opcode::fnPOP(int a)
{
	cout << "POP";
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(int a)
{
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(int a)
{
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(int a)
{
	return 0;
}
int Opcode::fnINT(int a)
{
	return 0;
}
// push four-byte signed int
int Opcode::fnBININT(int a)
{
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(int a)
{
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(int a)
{
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(int a)
{
	return 0;
}
// push None
int Opcode::fnNONE(int a)
{
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(int a)
{
	return 0;
}
int Opcode::fnBINPERSID(int a)
{
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(int a)
{
	return 0;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(int a)
{
	return 0;
}
// push string; counted binary string argument
int Opcode::fnBINSTRING(int a)
{
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(int a)
{
	return 0;
}
// push Unicode string; raw-unicode-escaped'd argument
int Opcode::fnUNICODE(int a)
{
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(int a)
{
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(int a)  
{
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(int a)  
{
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(int a)
{
	return 0;
}
// build a dict from stack items
int Opcode::fnDICT(int a)
{
	return 0;
}
// push empty dict
int Opcode::fnEMPTY_DICT(int a)
{
	return 0;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(int a)
{
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(int a)    
{
	return 0;
}
//   "    "    "    "   "   "  ;   "    " 1-byte arg
int Opcode::fnBINGET(int a)
{
	return 0;
}
// build & push class instance
int Opcode::fnINST(int a) 
{
	return 0;
}
// push item from memo on stack; index is 4-byte arg
int Opcode::fnLONG_BINGET(int a)
{
	return 0;
}
// build list from topmost stack items
int Opcode::fnLIST(int a)     
{
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(int a)
{
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(int a)     
{
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(int a)    
{
	return 0;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(int a)
{
	return 0;
}
//   "     "    "   "   " ;   "    " 4-byte arg
int Opcode::fnLONG_BINPUT(int a)
{
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(int a)  
{
	return 0;
}
// build tuple from topmost stack items
int Opcode::fnTUPLE(int a)   
{
	return 0;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(int a)
{
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(int a) 
{
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(int a)
{
	return 0;
}
// identify pickle protocol
int Opcode::fnPROTO(int a)  
{
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(int a)
{
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(int a) 
{
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(int a)
{
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(int a)
{
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(int a)
{
	return 0;
}
// build 2-tuple from two topmost stack items
int Opcode::fnTUPLE2(int a)
{
	return 0;
}
// build 3-tuple from three topmost stack items
int Opcode::fnTUPLE3(int a)
{
	return 0;
}
// push True
int Opcode::fnTRUE(int a)
{
	return 0;
}
// push False
int Opcode::fnFALSE(int a)
{
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(int a)
{
	return 0;
}
// push really big long
int Opcode::fnLONG4(int a)
{
	return 0;
}
int main(int argc, char* argv[])
{
	Pickle *myPickler = new Pickle();
	Opcode *popOpcode = myPickler->opcodes[POP];
	(popOpcode->opfunc)(1);
	cout << "HELLO WORLD";
}
