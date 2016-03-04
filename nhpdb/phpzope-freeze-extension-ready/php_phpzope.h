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
