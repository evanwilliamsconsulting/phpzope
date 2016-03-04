#include "php_phpzope.h"
//  Basic PHPZOPE Class
class PHPZope {
public:
    PHPZope();
    int returnValue();
private:
    char *filename;
};


PHPZope::PHPZope() {
}

int PHPZope::returnValue() {
	return 8;
}


zend_object_handlers phpzope_object_handlers;

struct phpzope_object {
    zend_object std;
    class PHPZope *phpzope;
};
zend_class_entry *phpzope_ce;
void phpzope_free_storage(void *object TSRMLS_DC)
{
    phpzope_object *obj = (phpzope_object *)object;
    delete &(obj->phpzope); 

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

    retval.handle = zend_objects_store_put(obj, NULL,
        phpzope_free_storage, NULL TSRMLS_CC);
    retval.handlers = &phpzope_object_handlers;

    return retval;
}


PHP_METHOD(PHPZope, __construct)
{
    const char *filename="test.txt";
    PHPZope *phpzope = new PHPZope();
    zval *object = getThis();

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &filename) == FAILURE) {
        RETURN_NULL();
    }

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
        RETURN_INT(phpzope->returnValue());
    }
    RETURN_NULL();
}

zend_function_entry phpzope_methods[] = {
        PHP_ME(PHPZope,  __construct,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(PHPZope,  returnValue,           NULL, ZEND_ACC_PUBLIC)
	{NULL, NULL, NULL}
};

PHP_MINIT_FUNCTION(phpzope_object)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "PHPZope", phpzope_object);
    phpzope_ce = zend_register_internal_class(&ce TSRMLS_CC);
    phpzope_ce->create_object = phpzope_create_handler;
    memcpy(&phpzope_object_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    phpzope_object_handlers.clone_obj = NULL;
    return SUCCESS;
}

zend_module_entry vehicles_module_entry = {
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

#ifdef COMPILE_DL_VEHICLES
extern "C" {
ZEND_GET_MODULE(phpzope)
}
#endif
