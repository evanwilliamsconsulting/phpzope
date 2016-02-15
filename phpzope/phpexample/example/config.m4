PHP_ARG_ENABLE(myclass,
    [Whether to enable the "myclass" extension],
    [  --enable-myclass Enable "myclass" extension support])

if test $PHP_MYCLASS != "no"; then
    PHP_REQUIRE_CXX()
    PHP_SUBST(MYCLASS_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, MYCLASS_SHARED_LIBADD)
    PHP_NEW_EXTENSION(myclass, php_myclass.cpp, $ext_shared)
fi
