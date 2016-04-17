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
  BININT2,
  LLONG,
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

typedef int (*fn)(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);

using namespace std;

	class Opcode {
		protected:
		    std::string module;
		    std::string name;
		    std::string pid;
		public:
		    char opcode;
		    char desc[25];
		    fn opfunc;
		    Opcode(char opcodeChar,const char *desc,fn funct);
		    char *getDescription();
		    void setModule(std::string inModule);
		    void setName(std::string inName); 
		    void setPid(std::string inPid);
		    static int fnSTOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
	    static int fnMARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnPOP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnPOP_MARK(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnDUP(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnINT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBININT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBININT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnLONG(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBININT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnNONE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBINPERSID(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnREDUCE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnSHORT_BINSTRING(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnBINUNICODE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnAPPEND(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);  
            static int fnBUILD(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);  
            static int fnGLOBAL(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnDICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnEMPTY_DICT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnAPPENDS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);    
            static int fnBINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnINST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack); 
            static int fnLONG_BINGET(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnLIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);     
            static int fnEMPTY_LIST(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);     
            static int fnPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);    
            static int fnBINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnLONG_BINPUT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnSETITEM(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);  
            static int fnTUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);   
            static int fnEMPTY_TUPLE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnSETITEMS(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack); 
            static int fnBINFLOAT(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnPROTO(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);  
            static int fnNEWOBJ(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnEXT1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack); 
            static int fnEXT2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnEXT4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnTUPLE1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnTUPLE2(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnTUPLE3(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnTRUE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnFALSE(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnLONG1(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
            static int fnLONG4(ifstream &instream,std::string str1,std::string::iterator &it1,void *classPtr,Stack &theStack);
};

class Pickle {
    public:
        Pickle();
	Opcode *opcodes[OPCODE_COUNT];
};
