/*
MIT License

Cosi (Javascript Native Runtime)

Copyright (c) 2019 Sebastian Garth

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "cosi.h"

/*
 This is automatically
 generated...do not edit!
*/
#include "native.c"
#include "internal.c"
#include "std.c"
/*
 That was automatically
 generated...do not edit!
*/

static cosi
 cosi_shadow(cosi J)
{
  return J ? J : cosi_get_global();
}

cosi_data
 cosi_unpack(cosi J)
{
  J = cosi_shadow(J);
  js_getglobal(J, cosi_runtime_tag);
  cosi_data result = cosi_topointer(J, -1);
  js_pop(J, 1);
  return result;
}

cosi_bool
 cosi_success(cosi J)
{
  return cosi_unpack(J)->success;
}

static void
 cosi_reset_error(cosi J, cosi_bool fail, const char* message)
{
  cosi_data data = cosi_unpack(J);
  data->success = !fail;
  data->debug = message ? message : "";
}

static void
 cosi_reset(cosi J)
{
  cosi_reset_error(J, cosi_false, NULL);
}

static void
 cosi_set_error(cosi J, const char* message)
{
  cosi_reset_error(J, cosi_true, message);
}

cosi
 cosi_destroy(cosi J)
{
  J = cosi_shadow(J);
  if (J == cosi_get_global())
    cosi_set_global(NULL);
  free(cosi_unpack(J));
  js_freestate(J);
  return NULL;
}

cosi_bool
 cosi_extend(cosi J, const char* symbol, void (*code)(cosi))
{
  J = cosi_shadow(J);
  js_newcfunction(J, code, symbol, 0);
  js_setglobal(J, symbol);
  return cosi_success(J);
}

cosi_bool
 cosi_define(cosi J, const char* symbol, double value)
{
  J = cosi_shadow(J);
  js_newnumber(J, value);
  js_setglobal(J, symbol);
  return cosi_success(J);
}

cosi_bool
 cosi_declare(cosi J, const char* symbol, void* value)
{
  return cosi_define(J, symbol, (size_t)value);
}

cosi_bool
 cosi_run(cosi J, const char* script)
{
  J = cosi_shadow(J);
  cosi_reset(J);
  js_dostring(J, script);
  return cosi_success(J);
}

cosi_bool
 cosi_eval(cosi J, const char* script)
{
 char
  format[] = "eval('%s')",
  wrapped[sizeof(format) + strlen(script) + 1];
  sprintf(wrapped, format, script);
  return cosi_run(J, wrapped);
}

cosi_bool
 cosi_include(cosi J, const char* file)
{
 char
  format[] = "eval(file_to_text('%s'))",
  wrapped[sizeof(format) + strlen(file) + 1];
  sprintf(wrapped, format, file);
  return cosi_run(J, wrapped);
}

void
 cosi_main(cosi J, char** argv, char** envp)
{
  cosi_data data = cosi_unpack(J);
  data->argv = argv;
  data->envp = envp;
}

static void
 cosi_panic(cosi J)
{
  cosi_set_error(J, "WARNING: cosi_panic invoked!");
}

static void
 cosi_report(cosi J, char const* message)
{
  cosi_set_error(J, message);
}

const char*
 cosi_message(cosi J)
{
  return cosi_unpack(J)->debug;
}

void
 cosi_argv(js_State* state)
{
  char** result = cosi_unpack(state)->argv;
  cosi_pushpointer(state, result);
}

void
 cosi_envp(js_State* state)
{
  char** result = cosi_unpack(state)->envp;
  cosi_pushpointer(state, result);
}

cosi
 cosi_create_from(js_Alloc alloc, void* context, int flags)
{
  cosi J = js_newstate(alloc, context, flags);
  cosi_data data = js_malloc(J, sizeof(*data));
  js_newnumber(J, (size_t)data);
  js_defglobal(J, cosi_runtime_tag, JS_DONTENUM);
  cosi_reset(J);
  cosi_main(J, NULL, NULL);
  js_atpanic(J, cosi_panic);
  js_setreport(J, cosi_report);

/*
 This is automatically
 generated...do not edit!
*/

#include "configured.c"

const char* 
 builtins = 
""
#include "builtins.txt"
"";

if(!cosi_run(J, builtins))
 fprintf(stderr, "ERROR: failed to load file 'cosi_builtins.txt'\n");

/*
 That was automatically
 generated...do not edit!
*/

  return J;
}

cosi
 cosi_create(void)
{
  return cosi_create_from(NULL, NULL, JS_STRICT);
}

static cosi
 cosi_access_global(cosi J, cosi_bool set)
{
  static cosi global = NULL;
  if (set)
    global = J;
  else if (global == NULL)
    global = cosi_create();
  return global;
}

void
 cosi_set_global(cosi J)
{
  cosi_access_global(J, cosi_true);
}

cosi
 cosi_get_global(void)
{
  return cosi_access_global(NULL, cosi_false);
}
