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
Stack &PHPZope::retrieveCurrentStack()
{
	return this->currentStack;
}
int PHPZope::retrieveStackDepth() {
	Stack theStack = this->currentStack;
	int stackDepth = theStack.depth();
	return stackDepth;
}
int PHPZope::readPickle(char *src)
{
	// http://en.cppreference.com/w/cpp/string/byte/strcpy
	//this->filename = new char(std::strlen(src)+10);
    	strcpy(this->filename, src);
	return 0;
} 

int PHPZope::retrieve_state(ifstream &instream,string state2,Stack &buildStack)
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
	    if (*it == '|')
	    {
		return -1;
	    }
	    ptrStackItem = (StackItem*)malloc(sizeof(StackItem));
	    for (int i = 0; i < OPCODE_COUNT; i++)
	    {
	    	Opcode *currentOpcode = myPickler->opcodes[i];
	        if (currentOpcode->opcode == *it)
                {
		    char *someString;
		    ptrStackItem->opcode = currentOpcode->opcode;
	    	    buildStack.push(*ptrStackItem);
		    //:jkhhprintf("current: %c, %i",currentOpcode->opcode,num++);
	            result = (currentOpcode->opfunc)(instream,state2,it,currentOpcode,buildStack);
		    this->currentStack = buildStack;
		}
	    }
    	} while ( it != state2.end() && *it > 0 && result != 0);

    	return 0;
} // retrieve_state()

char* PHPZope::returnPickleFile()
{
	std::string state;
	int j;
	Stack theStack;
	int boolSTOP;

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
	    while (!infile.eof() )
            {
		getline(infile,state);
	        if ( -1 == this->retrieve_state(infile,state,theStack))
		{
		   boolSTOP =  0;
		}
	    }
	    infile.close();
	    char* theString;
	    theString = (char*)malloc(1800*sizeof(char));
	    char* ptr;
	    ptr = theString;
	    int i;
	    int stackDepth = theStack.depth();
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
    Stack theStack;

    array_init(return_value);
    add_index_long(return_value, 42, 123);
    add_next_index_string(return_value,"I should now be found at index 43", 1);
    add_next_index_string(return_value,"I'm at 44!", 1);
    mystr = estrdup("Forty Five");
    add_next_index_string(return_value,"pi",3.1415926535);
    PHPZope *phpzope;
    phpzope_object *obj = (phpzope_object *)zend_object_store_get_object(
        getThis() TSRMLS_CC);
    phpzope = obj->phpzope;
    if (phpzope != NULL) {
	phpzope->returnPickleFile();
	ALLOC_INIT_ZVAL(mysubarray);
	array_init(mysubarray);
	char somestring[100];
	sprintf(somestring,"stackDepth %i",phpzope->retrieveStackDepth());
	add_next_index_string(mysubarray,somestring,1);
	int stackDepth = phpzope->retrieveStackDepth();
	Stack theStack = phpzope->retrieveCurrentStack();
	Pickle *myPickler = new Pickle();
	while (stackDepth > 0 )
	{
	     int result;
	     int depth;
	     StackItem* stackItem = theStack.pop();
	     stackDepth--;
	     sprintf(somestring,"currentOpcode: %c",stackItem->opcode);
	     for (int i = 0; i < OPCODE_COUNT; i++)
	     {
	    	Opcode *currentOpcode = myPickler->opcodes[i];
	        if (currentOpcode->opcode == stackItem->opcode)
                {
		    depth = theStack.depth();
		    ALLOC_INIT_ZVAL(opcodesubarray);
		    array_init(opcodesubarray);
		    add_next_index_long(opcodesubarray,depth);
	            result = (currentOpcode->opr)(opcodesubarray,stackItem,depth);
		    sprintf(somestring,"opcode: %c, depth: %i",stackItem->opcode,depth);
		    add_assoc_zval(mysubarray,somestring,opcodesubarray); 
		}
	    }
	}
	add_assoc_zval(return_value,"subarray",mysubarray);
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