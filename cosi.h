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

#ifndef cosi_h_included
#define cosi_h_included

#include "cosi_internal.h"

typedef int 
 cosi_bool;
#define cosi_false 0
#define cosi_true 1
#define cosi_runtime_tag "cosi_runtime_tag"

typedef js_State* 
 cosi;

struct cosi_data_
{
 char
  ** argv,
  ** envp;
 const char* 
  debug;
 cosi_bool 
  success;
};

typedef struct cosi_data_* 
 cosi_data;

cosi_data
 cosi_unpack(cosi J);

const char*
 cosi_message(cosi J);

cosi_bool
 cosi_success(cosi J);

cosi
 cosi_destroy(cosi J);

cosi_bool
 cosi_extend(cosi J, const char* symbol, void (*code)(cosi));

cosi_bool
 cosi_define(cosi J, const char* symbol, double value);

cosi_bool
 cosi_declare(cosi J, const char* symbol, void* value);

cosi_bool
 cosi_run(cosi J, const char* script);

cosi_bool
 cosi_eval(cosi J, const char* script);

cosi_bool
 cosi_include(cosi J, const char* file);

void
 cosi_main(cosi J, char** argv, char** envp);

cosi
 cosi_create_from(js_Alloc alloc, void* context, int flags);

cosi
 cosi_create(void);

void
 cosi_set_global(cosi J);

cosi
 cosi_get_global(void);

#endif // cosi_h_included
