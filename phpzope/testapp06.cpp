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

typedef int (*fn)(ResultSet *rs);

class Opcode {
        public:
	    char opcode;
	    fn opfunc;
            Opcode(char opcodeChar,fn funct);
            static int fnSTOP(ResultSet *rs);
	    static int fnMARK(ResultSet *rs);
            static int fnPOP(ResultSet *rs);
            static int fnPOP_MARK(ResultSet *rs);
            static int fnDUP(ResultSet *rs);
            static int fnFLOAT(ResultSet *rs);
            static int fnINT(ResultSet *rs);
            static int fnBININT(ResultSet *rs);
            static int fnBININT1(ResultSet *rs);
            static int fnLONG(ResultSet *rs);
            static int fnBININT2(ResultSet *rs);
            static int fnNONE(ResultSet *rs);
            static int fnPERSID(ResultSet *rs);
            static int fnBINPERSID(ResultSet *rs);
            static int fnREDUCE(ResultSet *rs);
            static int fnSTRING(ResultSet *rs);
            static int fnBINSTRING(ResultSet *rs);
            static int fnSHORT_BINSTRING(ResultSet *rs);
            static int fnUNICODE(ResultSet *rs);
            static int fnBINUNICODE(ResultSet *rs);
            static int fnAPPEND(ResultSet *rs);  
            static int fnBUILD(ResultSet *rs);  
            static int fnGLOBAL(ResultSet *rs);
            static int fnDICT(ResultSet *rs);
            static int fnEMPTY_DICT(ResultSet *rs);
            static int fnAPPENDS(ResultSet *rs);
            static int fnGET(ResultSet *rs);    
            static int fnBINGET(ResultSet *rs);
            static int fnINST(ResultSet *rs); 
            static int fnLONG_BINGET(ResultSet *rs);
            static int fnLIST(ResultSet *rs);     
            static int fnEMPTY_LIST(ResultSet *rs);
            static int fnOBJ(ResultSet *rs);     
            static int fnPUT(ResultSet *rs);    
            static int fnBINPUT(ResultSet *rs);
            static int fnLONG_BINPUT(ResultSet *rs);
            static int fnSETITEM(ResultSet *rs);  
            static int fnTUPLE(ResultSet *rs);   
            static int fnEMPTY_TUPLE(ResultSet *rs);
            static int fnSETITEMS(ResultSet *rs); 
            static int fnBINFLOAT(ResultSet *rs);
            static int fnPROTO(ResultSet *rs);  
            static int fnNEWOBJ(ResultSet *rs);
            static int fnEXT1(ResultSet *rs); 
            static int fnEXT2(ResultSet *rs);
            static int fnEXT4(ResultSet *rs);
            static int fnTUPLE1(ResultSet *rs);
            static int fnTUPLE2(ResultSet *rs);
            static int fnTUPLE3(ResultSet *rs);
            static int fnTRUE(ResultSet *rs);
            static int fnFALSE(ResultSet *rs);
            static int fnLONG1(ResultSet *rs);
            static int fnLONG4(ResultSet *rs);
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
int Opcode::fnMARK(ResultSet *rs)
{
	return 0;
}
// every pickle ends with STOP
int Opcode::fnSTOP(ResultSet *rs)
{
	return 0;
}
// discard topmost stack item
int Opcode::fnPOP(ResultSet *rs)
{
	cout << "POP";
	return 0;
}
// discard stack top through topmost markobject
int Opcode::fnPOP_MARK(ResultSet *rs)
{
	return 0;
}
// duplicate top stack item
int Opcode::fnDUP(ResultSet *rs)
{
	return 0;
}
// push float object; decimal string argument
int Opcode::fnFLOAT(ResultSet *rs)
{
	return 0;
}
int Opcode::fnINT(ResultSet *rs)
{
	return 0;
}
// push four-byte signed int
int Opcode::fnBININT(ResultSet *rs)
{
	return 0;
}
// push 1-byte unsigned int
int Opcode::fnBININT1(ResultSet *rs)
{
	return 0;
}
// push long; decimal string argument
int Opcode::fnLONG(ResultSet *rs)
{
	return 0;
}
// push 2-byte unsigned int
int Opcode::fnBININT2(ResultSet *rs)
{
	return 0;
}
// push None
int Opcode::fnNONE(ResultSet *rs)
{
	return 0;
}
// push persistent object; id is taken from string arg
int Opcode::fnPERSID(ResultSet *rs)
{
	return 0;
}
int Opcode::fnBINPERSID(ResultSet *rs)
{
	return 0;
}
// apply callable to argtuple, both on stack
int Opcode::fnREDUCE(ResultSet *rs)
{
	return 0;
}
// push string; NL-terminated string argument
int Opcode::fnSTRING(ResultSet *rs)
{
	return 0;
}
// push string; counted binary string argument
int Opcode::fnBINSTRING(ResultSet *rs)
{
	return 0;
}
//  "     "   ;    "      "       "      " < 256 bytes
int Opcode::fnSHORT_BINSTRING(ResultSet *rs)
{
	return 0;
}
// push Unicode string; raw-unicode-escaped'd argument
int Opcode::fnUNICODE(ResultSet *rs)
{
	return 0;
}
//   "     "       "  ; counted UTF-8 string argument
int Opcode::fnBINUNICODE(ResultSet *rs)
{
	return 0;
}
// append stack top to list below it
int Opcode::fnAPPEND(ResultSet *rs)  
{
	return 0;
}
// call __setstate__ or __dict__.update()
int Opcode::fnBUILD(ResultSet *rs)  
{
	return 0;
}
// push self.find_class(modname, name); 2 string args
int Opcode::fnGLOBAL(ResultSet *rs)
{
	sql::SQLString state;
		std::string state2;
	cout << "GLOBAL";
		state = rs -> getString("state");
		state2 = state;
		cout << state2;

		state = rs -> getString("state");
		state2 = state;
		cout << state2;

		state = rs -> getString("state");
		state2 = state;
		cout << state2;
	cout << "ENDGLOBAL";
	cout << endl;
	return 0;
}
// build a dict from stack items
int Opcode::fnDICT(ResultSet *rs)
{
	return 0;
}
// push empty dict
int Opcode::fnEMPTY_DICT(ResultSet *rs)
{
	return 0;
}
// extend list on stack by topmost stack slice
int Opcode::fnAPPENDS(ResultSet *rs)
{
	return 0;
}
// push item from memo on stack; index is string arg
int Opcode::fnGET(ResultSet *rs)    
{
	return 0;
}
//   "    "    "    "   "   "  ;   "    " 1-byte arg
int Opcode::fnBINGET(ResultSet *rs)
{
	return 0;
}
// build & push class instance
int Opcode::fnINST(ResultSet *rs) 
{
	return 0;
}
// push item from memo on stack; index is 4-byte arg
int Opcode::fnLONG_BINGET(ResultSet *rs)
{
	return 0;
}
// build list from topmost stack items
int Opcode::fnLIST(ResultSet *rs)     
{
	return 0;
}
// push empty list
int Opcode::fnEMPTY_LIST(ResultSet *rs)
{
	return 0;
}
// build & push class instance
int Opcode::fnOBJ(ResultSet *rs)     
{
	return 0;
}
// store stack top in memo; index is string arg
int Opcode::fnPUT(ResultSet *rs)    
{
	return 0;
}
//   "     "    "   "   " ;   "    " 1-byte arg
int Opcode::fnBINPUT(ResultSet *rs)
{
	return 0;
}
//   "     "    "   "   " ;   "    " 4-byte arg
int Opcode::fnLONG_BINPUT(ResultSet *rs)
{
	return 0;
}
// add key+value pair to dict
int Opcode::fnSETITEM(ResultSet *rs)  
{
	return 0;
}
// build tuple from topmost stack items
int Opcode::fnTUPLE(ResultSet *rs)   
{
	return 0;
}
// push empty tuple
int Opcode::fnEMPTY_TUPLE(ResultSet *rs)
{
	return 0;
}
// modify dict by adding topmost key+value pairs
int Opcode::fnSETITEMS(ResultSet *rs) 
{
	return 0;
}
// push float; arg is 8-byte float encoding
int Opcode::fnBINFLOAT(ResultSet *rs)
{
	return 0;
}
// identify pickle protocol
int Opcode::fnPROTO(ResultSet *rs)  
{
	return 0;
}
// build object by applying cls.__new__ to argtuple
int Opcode::fnNEWOBJ(ResultSet *rs)
{
	return 0;
}
// push object from extension registry; 1-byte index
int Opcode::fnEXT1(ResultSet *rs) 
{
	return 0;
}
// ditto, but 2-byte index
int Opcode::fnEXT2(ResultSet *rs)
{
	return 0;
}
// ditto, but 4-byte index
int Opcode::fnEXT4(ResultSet *rs)
{
	return 0;
}
// build 1-tuple from stack top
int Opcode::fnTUPLE1(ResultSet *rs)
{
	return 0;
}
// build 2-tuple from two topmost stack items
int Opcode::fnTUPLE2(ResultSet *rs)
{
	return 0;
}
// build 3-tuple from three topmost stack items
int Opcode::fnTUPLE3(ResultSet *rs)
{
	return 0;
}
// push True
int Opcode::fnTRUE(ResultSet *rs)
{
	return 0;
}
// push False
int Opcode::fnFALSE(ResultSet *rs)
{
	return 0;
}
// push long from < 256 bytes
int Opcode::fnLONG1(ResultSet *rs)
{
	return 0;
}
// push really big long
int Opcode::fnLONG4(ResultSet *rs)
{
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
	while (rs->next()) {
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
		out << state2;
		//out << "STATE";

	        Pickle *myPickler = new Pickle();
		for (auto c: state2)
		{
		    cout << c;
		    for (int i = 0; i < OPCODE_COUNT; i++)
		    {
		        Opcode *currentOpcode = myPickler->opcodes[i];
			if (currentOpcode->opcode == c)
                        {
				cout << "OPCODE: ";
				cout << myPickler->opcodes[i];
				cout << endl;
	        		(currentOpcode->opfunc)(rs);
			}
		    }
		}

	        //Opcode *popOpcode = myPickler->opcodes[POP];
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

		cout << "Executing the Query: \"SELECT zoid FROM class_ids where class_id='greg-barber'\" .." << endl;

		/* run a query which returns exactly one result set */
		res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_id='greg-barber'");

		cout << "Retrieving the result set .." << endl;

		/* retrieve the data from the result set and display on stdout */
		retrieve_data_and_print (res, NUMOFFSET, 1, string("zoid"));

		/* retrieve and display the result set metadata */
		retrieve_rsmetadata_and_print (res);

		/* re-use result set object */
		res = NULL;
		res = stmt -> executeQuery ("SELECT zoid FROM class_ids where class_id='greg-barber'");

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
