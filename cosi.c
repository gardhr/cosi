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

#include "cosi.h"

#ifdef cosi_automagic
#include "cosi_core.c"
#endif

int 
 main(int argc, char** argv, char** envp)
{
 size_t 
  offset = 1;
 if (argc == 1)
  argv[offset = 0] = "main.js";
 cosi_main(NULL, &argv[offset], envp);
#ifdef cosi_extension
 if(!cosi_include(NULL, "cosi_extension.js"))
  fprintf(stderr, "WARNING: failed to load 'cosi_extension.js'");
#endif
 char 
  * file = argv[offset],
  format[] = 
   "if(!file_to_task('%s'))\n"
   " throw Error('cannot load file %s')",
  script[sizeof(format) + strlen(file) * 2 + 1];
 sprintf(script, format, file, file);
 if (!cosi_run(NULL, script))
  puts(cosi_message(NULL));
 return cosi_success(NULL) ? 0 : 1;
}
