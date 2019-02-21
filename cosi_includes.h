/*
MIT License

Cosi (Javascript Native Runtime)

Copyright (c) 2017 Sebastian Garth

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

#ifndef cosi_includes_h_included
#define cosi_includes_h_included

#include "assert.h"
#include "complex.h"
#include "ctype.h"
#include "errno.h"
#include "fenv.h"
#include "float.h"
#include "inttypes.h"
#include "limits.h"
#include "locale.h"
#include "math.h"
#include "setjmp.h"
#include "signal.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stddef.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tgmath.h"
#include "time.h"
#include "uchar.h"
#include "wchar.h"
#include "mujs/mujs.h"

#ifdef cosi_debugging
void
 cosi_debug(js_State* state);
#endif

#endif // cosi_includes_h_included
