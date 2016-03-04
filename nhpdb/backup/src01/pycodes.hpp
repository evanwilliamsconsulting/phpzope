/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <regex>
#include <fstream>

using namespace std;
//  File Name : pycodes.hpp    Purpose : Python Opcodes
// Pickle opcodes.  See ZODB pickle.py for extensive docs.  The listing
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

typedef int (*fn)(std::string str1,std::string::iterator &it1,void *classPtr);

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
            static int fnSTOP(std::string str1,std::string::iterator &it1,void *classPtr);
	    static int fnMARK(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPOP(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPOP_MARK(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnDUP(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnFLOAT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnINT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT1(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBININT2(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnNONE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPERSID(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINPERSID(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnREDUCE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSTRING(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINSTRING(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSHORT_BINSTRING(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnUNICODE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnBINUNICODE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnAPPEND(std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnBUILD(std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnGLOBAL(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnDICT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEMPTY_DICT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnAPPENDS(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnGET(std::string str1,std::string::iterator &it1,void *classPtr);    
            static int fnBINGET(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnINST(std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnLONG_BINGET(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLIST(std::string str1,std::string::iterator &it1,void *classPtr);     
            static int fnEMPTY_LIST(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnOBJ(std::string str1,std::string::iterator &it1,void *classPtr);     
            static int fnPUT(std::string str1,std::string::iterator &it1,void *classPtr);    
            static int fnBINPUT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG_BINPUT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSETITEM(std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnTUPLE(std::string str1,std::string::iterator &it1,void *classPtr);   
            static int fnEMPTY_TUPLE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnSETITEMS(std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnBINFLOAT(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnPROTO(std::string str1,std::string::iterator &it1,void *classPtr);  
            static int fnNEWOBJ(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEXT1(std::string str1,std::string::iterator &it1,void *classPtr); 
            static int fnEXT2(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnEXT4(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE1(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE2(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTUPLE3(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnTRUE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnFALSE(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG1(std::string str1,std::string::iterator &it1,void *classPtr);
            static int fnLONG4(std::string str1,std::string::iterator &it1,void *classPtr);
};

class Pickle {

    public:
        Pickle();
	Opcode *opcodes[OPCODE_COUNT];
};
