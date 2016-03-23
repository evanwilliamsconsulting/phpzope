/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <fstream>
#include <regex>

#ifndef PHPZOPE_H
#define PHPZOPE_H

#define PHPZOPE_EXTNAME  "phpzope"
#define PHPZOPE_EXTVER   "0.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
}

extern zend_module_entry phpzope_module_entry;
#define phpext_phpzope_ptr &phpzope_module_entry;

#endif /* PHPZOPE_H */

using namespace std;
//  File Name : pycodes.hpp    Purpose : Python Opcodes
// Pickle opcodes.  See ZODB pickle.py for extensive docs.  The listing
// here is in kind-of alphabetical order of 1-character pickle code.
// pickletools groups them by purpose.

//  Basic PHPZOPE Class
class PHPZope {
public:
    PHPZope();
    ~PHPZope();
    int returnValue();
    int readPickle(char *strFile);
    char* returnPickleFile();
    int retrieve_state(string state2,Stack &theStack);
    char* returnModuleName();
    char* returnKlassName();
private:
    char* filename;
};

zend_object_handlers phpzope_object_handlers;

struct phpzope_object {
    zend_object std;
    class PHPZope *phpzope;
};
zend_class_entry *phpzope_ce;
