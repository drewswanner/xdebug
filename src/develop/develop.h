/*
   +----------------------------------------------------------------------+
   | Xdebug                                                               |
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2020 Derick Rethans                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 1.01 of the Xdebug license,   |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | https://xdebug.org/license.php                                       |
   | If you did not receive a copy of the Xdebug license and are unable   |
   | to obtain it through the world-wide-web, please send a note to       |
   | derick@xdebug.org so we can mail you a copy immediately.             |
   +----------------------------------------------------------------------+
   | Authors: Derick Rethans <derick@xdebug.org>                          |
   +----------------------------------------------------------------------+
 */

#ifndef __XDEBUG_DEVELOP_H__
#define __XDEBUG_DEVELOP_H__

typedef struct _xdebug_develop_globals_t {
	/* used for function monitoring */
	zend_bool     do_monitor_functions;
	xdebug_hash  *functions_to_monitor;
	xdebug_llist *monitored_functions_found; /* List of functions found */

	/* superglobals */
	zend_bool     dumped;
	xdebug_llist  server;
	xdebug_llist  get;
	xdebug_llist  post;
	xdebug_llist  cookie;
	xdebug_llist  files;
	xdebug_llist  env;
	xdebug_llist  request;
	xdebug_llist  session;

	/* used for collection errors */
	zend_bool     do_collect_errors;
	xdebug_llist *collected_errors;

	/* scream */
	zend_bool  in_at;
} xdebug_develop_globals_t;

typedef struct _xdebug_develop_settings_t {

	zend_long     max_stack_frames;
	zend_bool     collect_includes;
	zend_bool     collect_vars;
	zend_bool     show_ex_trace;
	zend_bool     show_error_trace;
	zend_bool     show_local_vars;
	zend_bool     force_display_errors;
	zend_long     force_error_reporting;
	zend_long     halt_level;

	zend_long     overload_var_dump;
	zend_long     cli_color;

	/* superglobals */
	zend_bool     dump_globals;
	zend_bool     dump_once;
	zend_bool     dump_undefined;

	/* scream */
	zend_bool  do_scream;
} xdebug_develop_settings_t;

void xdebug_init_develop_globals(xdebug_develop_globals_t *xg);
void xdebug_deinit_develop_globals(xdebug_develop_globals_t *xg);

void xdebug_develop_minit();
void xdebug_develop_mshutdown();
void xdebug_develop_rinit();
void xdebug_develop_post_deactivate();

void xdebug_develop_throw_exception_hook(zval *exception, zval *file, zval *line, zval *code, char *code_str, zval *message);
int xdebug_get_overload_var_dump(void);
void xdebug_monitor_handler(function_stack_entry *fse);

#endif
