#ifndef PHP_MYCLASS_H
#define PHP_MYCLASS_H

extern "C" {
#include "php.h"
}

// Include your C++ class definition
#include "Myclass.h"

// Here is the struct which will represent the PHP version of your Myclass.
// It simply includes a pointer to a Myclass and a zend_object for PHP to 
struct myclass_object {
    zend_object std;
    Hello *myclass;
};

// Here is whatever your PHP class is going to be called in the userspace (the PHP code)
#define PHP_MYCLASS_CLASSNAME "Myclass"
extern zend_class_entry *myclass_ce;
extern zend_object_handlers myclass_object_handlers;
zend_object_value myclass_create_handler(zend_class_entry *type TSRMLS_DC);

// Later, this will be the array full of your Myclass's method declarations
extern function_entry php_myclass_functions[];

#endif /* PHP_MYCLASS_H */
