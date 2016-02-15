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

typedef int (*fn)(int,int);

class Opcode {
        public:
	    char opcode;
	    fn opfunc;
            Opcode(char opcodeChar,fn funct);
	    static int fnMARK(int a,int b);
};

Opcode::Opcode(char opcodeChar,fn funct)
{
    this->opcode = opcodeChar;
    this->opfunc = funct;
}

class Pickle {

    public:
        Pickle();
	Opcode *theOpcode;
};

Pickle::Pickle()
{
    theOpcode = new Opcode('(',Opcode::fnMARK);
/*
    opcodes[MARK] = {'(', fnMARK};
    opcodes[STOP] = {'.',fnSTOP};
    opcodes[POP] = {'0',fnPOP};
    opcodes[POP_MARK] = {'1',fnPOP_MARK};
    opcodes[DUP] = {'2',fnDUP};
    opcodes[FLOAT] = {'F',fnFLOAT};
    opcodes[INT] = {'I',fnINT};
    opcodes[BININT] = {'J',fnBININT};
    opcodes[BININT1] = {'K',fnBININT1};
    opcodes[LONG] = {'L',fnLONG};
    opcodes[BININT2] = {'M',fnBININT2};
    opcodes[NONE] = {'N',fnNONE};
    opcodes[PERSID] = {'P',fnPERSID};
    opcodes[BINPERSID] = {'Q',fnBINPERSID};
    opcodes[REDUCE] = {'R',fnREDUCE};
    opcodes[STRING] = {'S',fnSTRING};
    opcodes[BINSTRING] = {'T',fnBINSTRING};
    opcodes[SHORT_BINSTRING] = {'U',fnSHORT_BINSTRING};
    opcodes[UNICODE] = {'V',fnUNICODE};
    opcodes[BINUNICODE] = {'X',fnBINUNICODE};
    opcodes[APPEND] = {'a',fnAPPEND};  
    opcodes[BUILD] = {'b',fnBUILD};  
    opcodes[GLOBAL] = {'c',fnGLOBAL};
    opcodes[DICT] = {'d',fnDICT};
    opcodes[EMPTY_DICT] = {'}',fnEMPTY_DICT};
    opcodes[APPENDS] = {'e',fnAPPENDS};
    opcodes[GET] = {'g',fnGET};    
    opcodes[BINGET] = {'h',fnBINGET};
    opcodes[INST] = {'i',fnINST}; 
    opcodes[LONG_BINGET] = {'j',fnLONG_BINGET};
    opcodes[LIST] = {'l',fnLIST};     
    opcodes[EMPTY_LIST] = {']',fnEMPTY_LIST};
    opcodes[OBJ] = {'o',fnOBJ};     
    opcodes[PUT] = {'p',fnPUT};    
    opcodes[BINPUT] = {'q',fnBINPUT};
    opcodes[LONG_BINPUT] = {'r',fnLONG_BINPUT};
    opcodes[SETITEM] = {'s',fnSETITEM};  
    opcodes[TUPLE] = {'t',fnTUPLE};   
    opcodes[EMPTY_TUPLE] = {')',fnEMPTY_TUPLE};
    opcodes[SETITEMS] = {'u',fnSETITEMS}; 
    opcodes[BINFLOAT] = {'G',fnBINFLOAT};
    opcodes[PROTO] = {'\x80',fnPROTO};  
    opcodes[NEWOBJ] = {'\x81',fnNEWOBJ};
    opcodes[EXT1] = {'\x82',fnEXT1}; 
    opcodes[EXT2] = {'\x83',fnEXT2};
    opcodes[EXT4] = {'\x84',fnEXT4};
    opcodes[TUPLE1] = {'\x85',fnTUPLE1};
    opcodes[TUPLE2] = {'\x86',fnTUPLE2};
    opcodes[TUPLE3] = {'\x87',fnTUPLE3};
    opcodes[TRUE] = {'\x88',fnTRUE};
    opcodes[FALSE] = {'\x89',fnFALSE};
    opcodes[LONG1] = {'\x8a',fnLONG1};
    opcodes[LONG4] = {'\x8b',fnLONG4};
*/
}

int Opcode::fnMARK(int a, int b)
{
	return 0;
}

/*
    // push special markobject on stack
    int fnMARK(int)
    {
    }
    // every pickle ends with STOP
    int fnSTOP(int)
    {
    }
    // discard topmost stack item
    int fnPOP(int)
    {
    }
    // discard stack top through topmost markobject
    int fnPOP_MARK(int)
    {
    }
    // duplicate top stack item
    int fnDUP(int)
    {
    }
    // push float object; decimal string argument
    int fnFLOAT(int)
    {
    }
    int fnINT(int)
    {
    }
    // push four-byte signed int
    int fnBININT(int)
    {
    }
    // push 1-byte unsigned int
    int fnBININT1(int)
    {
    }
    // push long; decimal string argument
    int fnLONG(int)
    {
    }
    // push 2-byte unsigned int
    int fnBININT2(int)
    {
    }
    // push None
    int fnNONE(int)
    {
    }
    // push persistent object; id is taken from string arg
    int fnPERSID(int)
    {
    }
    //  "       "         "  ;  "  "   "     "  stack
    int fnBINPERSID(int)
    {
    }
    // apply callable to argtuple, both on stack
    int fnREDUCE(int)
    {
    }
    // push string; NL-terminated string argument
    int fnSTRING(int)
    {
    }
    // push string; counted binary string argument
    int fnBINSTRING(int)
    {
    }
    //  "     "   ;    "      "       "      " < 256 bytes
    int fnSHORT_BINSTRING(int)
    {
    }
    // push Unicode string; raw-unicode-escaped'd argument
    int fnUNICODE(int)
    {
    }
    //   "     "       "  ; counted UTF-8 string argument
    int fnBINUNICODE(int)
    {
    }
    // append stack top to list below it
    int fnAPPEND(int)  
    {
    }
    // call __setstate__ or __dict__.update()
    int fnBUILD(int)  
    {
    }
    // push self.find_class(modname, name); 2 string args
    int fnGLOBAL(int)
    {
    }
    // build a dict from stack items
    int fnDICT(int)
    {
    }
    // push empty dict
    int fnEMPTY_DICT(int)
    {
    }
    // extend list on stack by topmost stack slice
    int fnAPPENDS(int)
    {
    }
    // push item from memo on stack; index is string arg
    int fnGET(int)    
    {
    }
    //   "    "    "    "   "   "  ;   "    " 1-byte arg
    int fnBINGET(int)
    {
    }
    // build & push class instance
    int fnINST(int) 
    {
    }
    // push item from memo on stack; index is 4-byte arg
    int fnLONG_BINGET(int)
    {
    }
    // build list from topmost stack items
    int fnLIST(int)     
    {
    }
    // push empty list
    int fnEMPTY_LIST(int)
    {
    }
    // build & push class instance
    int fnOBJ(int)     
    {
    }
    // store stack top in memo; index is string arg
    int fnPUT(int)    
    {
    }
    //   "     "    "   "   " ;   "    " 1-byte arg
    int fnBINPUT(int)
    {
    }
    //   "     "    "   "   " ;   "    " 4-byte arg
    int fnLONG_BINPUT(int)
    {
    }
    // add key+value pair to dict
    int fnSETITEM(int)  
    {
    }
    // build tuple from topmost stack items
    int fnTUPLE(int)   
    {
    }
    // push empty tuple
    int fnEMPTY_TUPLE(int)
    {
    }
    // modify dict by adding topmost key+value pairs
    int fnSETITEMS(int) 
    {
    }
    // push float; arg is 8-byte float encoding
    int fnBINFLOAT(int)
    {
    }
    // identify pickle protocol
    int fnPROTO(int)  
    {
    }
    // build object by applying cls.__new__ to argtuple
    int fnNEWOBJ(int)
    {
    }
    // push object from extension registry; 1-byte index
    int fnEXT1(int) 
    {
    }
    // ditto, but 2-byte index
    int fnEXT2(int)
    {
    }
    // ditto, but 4-byte index
    int fnEXT4(int)
    {
    }
    // build 1-tuple from stack top
    int fnTUPLE1(int)
    {
    }
    // build 2-tuple from two topmost stack items
    int fnTUPLE2(int)
    {
    }
    // build 3-tuple from three topmost stack items
    int fnTUPLE3(int)
    {
    }
    // push True
    int fnTRUE(int)
    {
    }
    // push False
    int fnFALSE(int)
    {
    }
    // push long from < 256 bytes
    int fnLONG1(int)
    {
    }
    // push really big long
    int fnLONG4(int)
    {
    }
*/
int main(int argc, char* argv[])
{
	Pickle *myPickler = new Pickle();
	Opcode *myOpcode = myPickler->theOpcode;
	cout << myOpcode->opcode;
	cout << "HELLO WORLD";
}
