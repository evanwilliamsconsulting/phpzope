#include "basics.h"

using namespace std;

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

typedef int (*fn)(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);

using namespace std;

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
		    static int fnSTOP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
	    static int fnMARK(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnPOP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnPOP_MARK(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnDUP(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnFLOAT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnINT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBININT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBININT1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnLONG(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBININT2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnNONE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnPERSID(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBINPERSID(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnREDUCE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBINSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnSHORT_BINSTRING(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnUNICODE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnBINUNICODE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnAPPEND(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);  
            static int fnBUILD(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);  
            static int fnGLOBAL(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnDICT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnEMPTY_DICT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnAPPENDS(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);    
            static int fnBINGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnINST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack); 
            static int fnLONG_BINGET(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnLIST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);     
            static int fnEMPTY_LIST(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnOBJ(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);     
            static int fnPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);    
            static int fnBINPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnLONG_BINPUT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnSETITEM(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);  
            static int fnTUPLE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);   
            static int fnEMPTY_TUPLE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnSETITEMS(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack); 
            static int fnBINFLOAT(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnPROTO(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);  
            static int fnNEWOBJ(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnEXT1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack); 
            static int fnEXT2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnEXT4(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnTUPLE1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnTUPLE2(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnTUPLE3(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnTRUE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnFALSE(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnLONG1(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
            static int fnLONG4(std::string str1,std::string::iterator &it1,void *classPtr,Stack *theStack);
};

class Pickle {
    public:
        Pickle();
	Opcode *opcodes[OPCODE_COUNT];
};
