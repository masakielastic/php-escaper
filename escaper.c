/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_escaper.h"
#include "standard/html.h"

/* If you declare any globals in php_escaper.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(escaper)
*/

/* True global resources - no need for thread safety here */
static int le_escaper;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("escaper.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_escaper_globals, escaper_globals)
    STD_PHP_INI_ENTRY("escaper.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_escaper_globals, escaper_globals)
PHP_INI_END()
*/
/* }}} */

PHP_FUNCTION(escape_html)
{
	char *str = NULL;
	char *encoding = "UTF-8";
	int str_len = 0;
	int encoding_len = 5;
  size_t new_len;
	long flags = ENT_COMPAT | ENT_SUBSTITUTE;
  char *replaced;
	zend_bool double_encode = 1;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|s", &str, &str_len, &encoding, &encoding_len) == FAILURE) {
		return;
	}

	replaced = php_escape_html_entities_ex((unsigned char *) str, str_len, &new_len, 0, (int) flags, encoding, double_encode TSRMLS_CC);
	RETVAL_STRINGL(replaced, (int)new_len, 0);
}

/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_escaper_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_escaper_init_globals(zend_escaper_globals *escaper_globals)
{
	escaper_globals->global_value = 0;
	escaper_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(escaper)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(escaper)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(escaper)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(escaper)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(escaper)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "escaper support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ escaper_functions[]
 *
 * Every user visible function must have an entry in escaper_functions[].
 */
const zend_function_entry escaper_functions[] = {
	PHP_FE(escape_html,	NULL)
	PHP_FE_END	/* Must be the last line in escaper_functions[] */
};
/* }}} */

/* {{{ escaper_module_entry
 */
zend_module_entry escaper_module_entry = {
	STANDARD_MODULE_HEADER,
	"escaper",
	escaper_functions,
	PHP_MINIT(escaper),
	PHP_MSHUTDOWN(escaper),
	PHP_RINIT(escaper),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(escaper),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(escaper),
	PHP_ESCAPER_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ESCAPER
ZEND_GET_MODULE(escaper)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
