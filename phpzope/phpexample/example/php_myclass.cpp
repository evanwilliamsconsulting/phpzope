#include "php_myclass.h"

zend_class_entry *myclass_ce;
zend_object_handlers myclass_object_handlers;

// I'm still a newb, but I think this is the function that handles memory management when
// the PHP class is deleted (goes out of scope, script ends, whatever)
void myclass_free_storage(void *object TSRMLS_DC) 
{
    myclass_object *obj = (myclass_object*)object;
    delete obj->myclass;

    zend_hash_destroy(obj->std.properties);
    FREE_HASHTABLE(obj->std.properties);

    efree(obj);
}

// And likewise I believe this handles, as the name implies, mem management
// when your Myclass is instantiated.
zend_object_value myclass_create_handler(zend_class_entry *type TSRMLS_DC) 
{
    zval *tmp;
    zend_object_value retval;

    // make room in memory for a new PHP Myclass object:
    myclass_object *obj = (myclass_object*)emalloc(sizeof(myclass_object));
    // fill that memory with 0s
    memset(obj, 0, sizeof(myclass_object));
    obj->std.ce = type;

    // some magic stuff (no idea)
    ALLOC_HASHTABLE(obj->std.properties);
    zend_hash_init(obj->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
    zend_hash_copy(obj->std.properties, &type->default_properties, (copy_ctor_func_t)zval_add_ref, (void*)&tmp, sizeof(zval*));

    // make it so you can get an instance of this object in later code
    retval.handle = zend_objects_store_put(obj, NULL, myclass_free_storage, NULL TSRMLS_CC);
    retval.handlers = &myclass_object_handlers;

    return retval;
}

// First, we define some argument info for methods that take arguments (if we have any)
// This one means, obviously, one argument:
ZEND_BEGIN_ARG_INFO_EX(php_myclass_one_arg, 0, 0, 1)
ZEND_END_ARG_INFO()

// This one two args, etc.
ZEND_BEGIN_ARG_INFO_EX(php_myclass_two_args, 0, 0, 2)
ZEND_END_ARG_INFO()

// Here's where you tell PHP what methods your Myclass PHP class has.

zend_function_entry php_myclass_functions[] = {
    // A special property at the end of this line for the constructor:
    PHP_ME(Myclass,__construct,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)

    // Normal methods look like this:
    PHP_ME(Myclass,methodNameNoArgs,NULL,ZEND_ACC_PUBLIC)
    PHP_ME(Myclass,methodName1Arg,php_myclass_one_arg,ZEND_ACC_PUBLIC) 
    PHP_ME(Myclass,methodName2Args,php_myclass_two_args,ZEND_ACC_PUBLIC) 

    // Three magic NULL values, no idea why they have to go here.
    { NULL, NULL, NULL }
};
