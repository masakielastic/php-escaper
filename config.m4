dnl $Id$
dnl config.m4 for extension escaper

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(escaper, for escaper support,
Make sure that the comment is aligned:
[  --with-escaper             Include escaper support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(escaper, whether to enable escaper support,
dnl Make sure that the comment is aligned:
dnl [  --enable-escaper           Enable escaper support])

if test "$PHP_ESCAPER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-escaper -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/escaper.h"  # you most likely want to change this
  dnl if test -r $PHP_ESCAPER/$SEARCH_FOR; then # path given as parameter
  dnl   ESCAPER_DIR=$PHP_ESCAPER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for escaper files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       ESCAPER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$ESCAPER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the escaper distribution])
  dnl fi

  dnl # --with-escaper -> add include path
  dnl PHP_ADD_INCLUDE($ESCAPER_DIR/include)

  dnl # --with-escaper -> check for lib and symbol presence
  dnl LIBNAME=escaper # you may want to change this
  dnl LIBSYMBOL=escaper # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ESCAPER_DIR/lib, ESCAPER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_ESCAPERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong escaper lib version or lib not found])
  dnl ],[
  dnl   -L$ESCAPER_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(ESCAPER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(escaper, escaper.c, $ext_shared)
fi
