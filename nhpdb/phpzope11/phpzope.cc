#include "pickle.h"
#include "phpzope.h"


//  Basic PHPZOPE Class
PHPZope::PHPZope() {
}

PHPZope::~PHPZope() {
}

int PHPZope::returnValue() {
	return 8;
}
stack<StackItem>& PHPZope::retrieveCurrentStack()
{
	return this->currentStack;
}
int PHPZope::retrieveStackDepth() {
	stack<StackItem> theStack = this->currentStack;
	int stackDepth = theStack.size();
	return stackDepth;
}
int PHPZope::readPickle(char *src)
{
	// http://en.cppreference.com/w/cpp/string/byte/strcpy
	//this->filename = new char(std::strlen(src)+10);
    	strcpy(this->filename, src);
	return 0;
} 

int PHPZope::retrieve_state(ifstream& infile,string& state2,stack<StackItem>& theStack,int& lastMark)
        {
	std::string filename = "state.txt";
	StackItem *ptrStackItem;
	int result;

	/* fetch the data : retrieve all the rows in the result set */

	Pickle *myPickler = new Pickle();
	std::string::iterator it;
	it = state2.begin();
	int num = 0;
	do
	{
	    for (int i = 0; i < OPCODE_COUNT; i++)
	    {
	    	Opcode *currentOpcode = myPickler->opcodes[i];
	        if (currentOpcode->opcode == *it)
                {
		    //printf("opcode: %c\n",*it);
		    char *someString;
	            ptrStackItem = (StackItem*)emalloc(sizeof(StackItem));
		    ptrStackItem->opcode = currentOpcode->opcode;
		    ptrStackItem->theMark = 0;
		    ptrStackItem->lastMark = lastMark;
	    	    theStack.push(*ptrStackItem);
		    //printf("push\n");
	            result = (currentOpcode->opfunc)(infile,state2,it,currentOpcode,*ptrStackItem,theStack);
		    ptrStackItem = &theStack.top();
		    lastMark = ptrStackItem->lastMark;	
		}
	    }
    	} while ( it < state2.end() && *it > 0 && result != 0);

	printf("\n");
    	return 0;
} // retrieve_state()

char* PHPZope::returnPickleFile(stack<StackItem>& theStack)
{
	std::string state;
	int j;
	int boolSTOP;
	int lastMark = 0;

	ifstream infile;

        //__asm__("int3");
	infile.open(this->filename);
	boolSTOP = -1;
        if ( infile.fail() )
        {
	   strcpy(this->filename,strerror(errno));
	}
	else
	{
	    while (!infile.eof())
            {
		getline(infile,state);
	        this->retrieve_state(infile,state,theStack,lastMark);
	    }
	    infile.close();
	    int i;
        }
	return this->filename;
}

void phpzope_free_storage(void *object TSRMLS_DC)
{
    phpzope_object *obj = (phpzope_object *)object;
    //delete &(obj->phpzope); 

    zend_hash_destroy(obj->std.properties);
    FREE_HASHTABLE(obj->std.properties);

    efree(obj);
}

zend_object_value phpzope_create_handler(zend_class_entry *type TSRMLS_DC)
{
    zval *tmp;
    zend_object_value retval;

    phpzope_object *obj = (phpzope_object *)emalloc(sizeof(phpzope_object));
    memset(obj, 0, sizeof(phpzope_object));
    obj->std.ce = type;

    ALLOC_HASHTABLE(obj->std.properties);
    zend_hash_init(obj->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
/*
    zend_hash_copy(obj->std.properties, &type->default_properties,
        (copy_ctor_func_t)zval_add_ref, (void *)&tmp, sizeof(zval *));
*/

    retval.handle = zend_objects_store_put(obj, NULL, phpzope_free_storage, NULL TSRMLS_CC);
    retval.handlers = &phpzope_object_handlers;

    return retval;
}


PHP_METHOD(PHPZope, __construct)
{
    const char *filename="test.txt";
    PHPZope *phpzope = NULL;
    zval *object = getThis();

    phpzope = new PHPZope();
    phpzope_object *obj = (phpzope_object *)zend_object_store_get_object(object TSRMLS_CC);
    obj->phpzope = phpzope;

}
PHP_METHOD(PHPZope, returnValue)
{
    PHPZope *phpzope;
    phpzope_object *obj = (phpzope_object *)zend_object_store_get_object(
        getThis() TSRMLS_CC);
    phpzope = obj->phpzope;
    if (phpzope != NULL) {
        RETURN_LONG(phpzope->returnValue());
    }
    RETURN_NULL();
}
PHP_METHOD(PHPZope, readPickle)
{
    PHPZope *phpzope;
    char *ptr,*ptr2;
    char name[100];
    int name_len;
    phpzope_object *obj = (phpzope_object *)zend_object_store_get_object(
        getThis() TSRMLS_CC);
    phpzope = obj->phpzope;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &ptr, &name_len) == FAILURE) {
        RETURN_NULL();
    }
    ptr2 = name;
    for (int i=0;i<name_len;i++)
    {
	*ptr2++ = *ptr++;
    }
    *ptr2 = '\0';
    ptr2 = name;
    if (phpzope != NULL) {
        phpzope->readPickle(ptr2);
    }
    RETURN_NULL();
}
PHP_METHOD(PHPZope, returnPickleFile)
{
    char *mystr;
    zval *mysubarray,*opcodesubarray;
    StackItem *ptrStackItem;

    array_init(return_value);
    /*
    add_index_long(return_value, 42, 123);
    add_next_index_string(return_value,"I should now be found at index 43", 1);
    add_next_index_string(return_value,"I'm at 44!", 1);
    mystr = estrdup("Forty Five");
    add_next_index_string(return_value,"pi",3.1415926535);
    */
    PHPZope *phpzope;
    phpzope_object *obj = (phpzope_object *)zend_object_store_get_object(
        getThis() TSRMLS_CC);
    phpzope = obj->phpzope;
    if (phpzope != NULL) {
	//ptrStackItem = (StackItem*)emalloc(sizeof(StackItem));
	//ptrStackItem->opcode = '!';
	stack<StackItem> theStack = phpzope->retrieveCurrentStack();
	//theStack.push(*ptrStackItem);
	phpzope->returnPickleFile(theStack);
	//ALLOC_INIT_ZVAL(mysubarray);
	//array_init(mysubarray);
	char somestring[100];
	int depth = theStack.size();
	sprintf(somestring,"stackDepth %i",depth);
	//add_next_index_string(mysubarray,somestring,1);
	add_next_index_string(return_value,somestring,1);
	
	int stackDepth = depth;
	Pickle *myPickler = new Pickle();
	while (stackDepth > 0 )
	{
	     int result;
	     StackItem stackItem = theStack.top();
	     sprintf(somestring,"currentOpcode: %c",stackItem.opcode);
	     for (int i = 0; i < OPCODE_COUNT; i++)
	     {
	    	Opcode *currentOpcode = myPickler->opcodes[i];
	        if (currentOpcode->opcode == stackItem.opcode)
                {
		    depth = theStack.size();
		    ALLOC_INIT_ZVAL(opcodesubarray);
		    array_init(opcodesubarray);
		    add_next_index_long(opcodesubarray,depth);
	            result = (currentOpcode->opr)(opcodesubarray,&stackItem,depth);
		    sprintf(somestring,"opcode: %c, depth: %i, lastMark %i",stackItem.opcode,depth,stackItem.lastMark);
		    //add_assoc_zval(mysubarray,somestring,opcodesubarray); 
		    add_assoc_zval(return_value,somestring,opcodesubarray); 
		}
	    }
	    stackDepth--;
	    theStack.pop();
	}
	
	//add_assoc_zval(return_value,"subarray",mysubarray);
	//add_assoc_zval(return_value,"subarray",mysubarray);
    }
    //RETURN_NULL();
} 

zend_function_entry phpzope_methods[] = {
        PHP_ME(PHPZope,  __construct,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(PHPZope,  returnValue,           NULL, ZEND_ACC_PUBLIC)
        PHP_ME(PHPZope,  readPickle,           NULL, ZEND_ACC_PUBLIC)
        PHP_ME(PHPZope,  returnPickleFile,           NULL, ZEND_ACC_PUBLIC)
	{NULL, NULL, NULL}
};

PHP_MINIT_FUNCTION(phpzope)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "PHPZope", phpzope_methods);
    phpzope_ce = zend_register_internal_class(&ce TSRMLS_CC);
    phpzope_ce->create_object = phpzope_create_handler;
    memcpy(&phpzope_object_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    phpzope_object_handlers.clone_obj = NULL;
    return SUCCESS;
}

zend_module_entry phpzope_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHPZOPE_EXTNAME,
    NULL,        /* Functions */
    PHP_MINIT(phpzope),        /* MINIT */
    NULL,        /* MSHUTDOWN */
    NULL,        /* RINIT */
    NULL,        /* RSHUTDOWN */
    NULL,        /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHPZOPE_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_PHPZOPE
extern "C" {
ZEND_GET_MODULE(phpzope)
}
#endif
