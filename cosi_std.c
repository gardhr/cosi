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

/*
 This is automatically
 generated...do not edit!
*/

// assert.h

void
 cosi_assert(js_State* state)
{
  assert(js_tonumber(state, 1));
  js_pushundefined(state);
}

// math.h

void
 cosi_sin(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, sin(arg));
}

void
 cosi_cos(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, cos(arg));
}

void
 cosi_tan(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, tan(arg));
}

void
 cosi_sinh(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, sinh(arg));
}

void
 cosi_cosh(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, cosh(arg));
}

void
 cosi_tanh(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, tanh(arg));
}

void
 cosi_asin(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, asin(arg));
}

void
 cosi_acos(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, acos(arg));
}

void
 cosi_atan(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, atan(arg));
}

void
 cosi_atan2(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1),
  arg2 = js_tonumber(J, 2);
 js_pushnumber(J, atan2(arg1, arg2));
}

void
 cosi_exp(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, exp(arg));
}

void
 cosi_frexp(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1);
 int*
  arg2 = cosi_topointer(J, 2);
 double
  result = frexp(arg1, arg2); 
 js_pushnumber(J, result);
}

void
 cosi_ldexp(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1),
  arg2 = js_tonumber(J, 2);
 double
  result = ldexp(arg1, arg2); 
 js_pushnumber(J, result);
}

void
 cosi_log(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, log(arg));
}

void
 cosi_log10(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, log10(arg));
}

void
 cosi_sqrt(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, sqrt(arg));
}

void
 cosi_pow(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1),
  arg2 = js_tonumber(J, 2);
 js_pushnumber(J, pow(arg1, arg2));
}

void
 cosi_ceil(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, ceil(arg));
}

void
 cosi_floor(js_State* J)
{
 double  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, floor(arg));
}

void
 cosi_abs(js_State* J)
{
 int  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, abs(arg));
}

void
 cosi_fabs(js_State* J)
{
 float  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, fabs(arg));
}

void
 cosi_labs(js_State* J)
{
 long int  
  arg = js_tonumber(J, 1);
 js_pushnumber(J, labs(arg));
}

void
 cosi_fmod(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1),
  arg2 = js_tonumber(J, 2);
 js_pushnumber(J, fmod(arg1, arg2));
}

void
 cosi_modf(js_State* J)
{
 double  
  arg1 = js_tonumber(J, 1);
 double*
  arg2 = cosi_topointer(J, 2);
 double
  result = modf(arg1, arg2); 
 js_pushnumber(J, result);
}

// time.h

void
 cosi_difftime(js_State* J)
{
 time_t 
  end = js_tonumber(J, 1),
  begin = js_tonumber(J, 2);
 double
  result = difftime(end, begin);
 js_pushnumber(J, result);
}

void
 cosi_time(js_State* J)
{
 js_pushnumber(J, time(cosi_topointer(J, 1)));
}

void
 cosi_ctime(js_State* J)
{
 js_pushstring(J, ctime(cosi_topointer(J, 1)));
}

void
 cosi_clock(js_State* J)
{
 js_pushnumber(J, clock());
}

void
 cosi_asctime(js_State* J)
{
 struct tm*
  arg = cosi_topointer(J, 1);
 cosi_pushpointer(J, asctime(arg));
}

void
 cosi_strftime(js_State* J)
{
 char* 
  text = cosi_tostring(J, 1);
 size_t 
  size = js_tonumber(J, 2);
 char* 
  format = cosi_tostring(J, 3);
 struct tm*
  timestamp = cosi_topointer(J, 4); 
 size_t 
  value = strftime(text, size, format, timestamp);
 js_pushnumber(J, value);
}

void
 cosi_wcsftime(js_State* J)
{
 wchar_t* 
  text = cosi_topointer(J, 1);
 size_t 
  size = js_tonumber(J, 2);
 wchar_t* 
  format = cosi_topointer(J, 3);
 struct tm*
  timestamp = cosi_topointer(J, 4); 
 size_t 
  value = wcsftime(text, size, format, timestamp);
 js_pushnumber(J, value);
}

void
 cosi_gmtime(js_State* J)
{
 time_t*
  arg = cosi_topointer(J, 1); 
 struct tm*
  data = gmtime(arg); 
 cosi_pushpointer(J, data);
}

void
 cosi_localtime(js_State* J)
{
 time_t*
  arg = cosi_topointer(J, 1); 
 struct tm*
  data = localtime(arg); 
 cosi_pushpointer(J, data);
}

void
 cosi_mktime(js_State* J)
{
 struct tm*
  arg = cosi_topointer(J, 1); 
 time_t
  value = mktime(arg);
 js_pushnumber(J, value);
}

// stdio.h

void
 cosi_fopen(js_State* state)
{
  char const 
   * filename = cosi_tostring(state, 1),
   * mode = cosi_tostring(state, 2);
  FILE* 
   stream = fopen(filename, mode);
  cosi_pushpointer(state, stream);
}

void
 cosi_freopen(js_State* state)
{
  char
   * filename = cosi_tostring(state, 1),
   * mode = cosi_tostring(state, 2);
  FILE
   * stream = cosi_topointer(state, 3),
   * result = freopen(filename, mode, stream);
  cosi_pushpointer(state, result);
}

void
 cosi_fgetc(js_State* state)
{
  int ch = fgetc(cosi_topointer(state, 1));
  js_pushnumber(state, ch);
}

void
 cosi_getc(js_State* state)
{
  int ch = getc(cosi_topointer(state, 1));
  js_pushnumber(state, ch);
}

void
 cosi_ungetc(js_State* state)
{
  int ch = js_tonumber(state, 1);
  FILE* stream = cosi_topointer(state, 2);
  int result = ungetc(ch, stream);
  js_pushnumber(state, result);
}

void
 cosi_getchar(js_State* state)
{
  int result = getchar();
  js_pushnumber(state, result);
}

void
 cosi_fgets(js_State* state)
{
  char* data = cosi_topointer(state, 1);
  int count = js_tonumber(state, 2);
  FILE* stream = cosi_topointer(state, 3);
  char* result = fgets(data, count, stream);
  cosi_pushpointer(state, result);
}

void
 cosi_fputc(js_State* state)
{
  int ch = cosi_tobyte(state, 1),
      result = fputc(ch, cosi_topointer(state, 2));
  js_pushnumber(state, result);
}

void
 cosi_putc(js_State* state)
{
  int ch = cosi_tobyte(state, 1),
      result = putc(ch, cosi_topointer(state, 2));
  js_pushnumber(state, result);
}

void
 cosi_putchar(js_State* state)
{
  int result = putchar(cosi_tobyte(state, 1));
  js_pushnumber(state, result);
}

void
 cosi_fseek(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int offset = js_tonumber(state, 2), mode = js_tonumber(state, 3),
      result = fseek(stream, offset, mode);
  js_pushnumber(state, result);
}

void
 cosi_ftell(js_State* state)
{
  int result = ftell(cosi_topointer(state, 1));
  js_pushnumber(state, result);
}

void
 cosi_fgetpos(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = fgetpos(stream, cosi_topointer(state, 2));
  js_pushnumber(state, result);
}

void
 cosi_fsetpos(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = fsetpos(stream, cosi_topointer(state, 2));
  js_pushnumber(state, result);
}

void
 cosi_rewind(js_State* state)
{
  rewind(cosi_topointer(state, 1));
  js_pushundefined(state);
}

void
 cosi_fread(js_State* state)
{
  void* ptr = cosi_tostring(state, 1);
  size_t size = js_tonumber(state, 2), count = js_tonumber(state, 3);
  FILE* stream = cosi_topointer(state, 4);
  size_t result = fread(ptr, size, count, stream);
  js_pushnumber(state, result);
}

void
 cosi_fwrite(js_State* state)
{
  void const* ptr = cosi_tostring(state, 1);
  size_t size = js_tonumber(state, 2), count = js_tonumber(state, 3);
  FILE* stream = cosi_topointer(state, 4);
  size_t result = fwrite(ptr, size, count, stream);
  js_pushnumber(state, result);
}

void
 cosi_clearerr(js_State* state)
{
  clearerr(cosi_topointer(state, 1));
  js_pushundefined(state);
}

void
 cosi_fclose(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = fclose(stream);
  js_pushnumber(state, result);
}

void
 cosi_feof(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = feof(stream);
  js_pushnumber(state, result);
}

void
 cosi_ferror(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = ferror(stream);
  js_pushnumber(state, result);
}

void
 cosi_perror(js_State* state)
{
  char const* data = cosi_topointer(state, 1);
  perror(data);
  js_pushundefined(state);
}

void
 cosi_fflush(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  int result = fflush(stream);
  js_pushnumber(state, result);
}

void
 cosi_remove(js_State* state)
{
  int result = remove(cosi_tostring(state, 1));
  js_pushnumber(state, result);
}

void
 cosi_rename(js_State* state)
{
  char* old = cosi_tostring(state, 1);
  char* new = cosi_tostring(state, 2);
  int result = rename(old, new);
  js_pushnumber(state, result);
}

void
 cosi_setbuf(js_State* state)
{
  FILE* stream = cosi_topointer(state, 1);
  char* buffer = cosi_topointer(state, 2);
  setbuf(stream, buffer);
  js_pushundefined(state);
}

void
 cosi_setvbuf(js_State* state)
{
 FILE* stream = cosi_topointer(state, 1);
 char* buffer = cosi_topointer(state, 2);
 int mode = js_tonumber(state, 3);
 size_t size = js_tonumber(state, 4);
 int result = setvbuf(stream, buffer, mode, size);
 js_pushnumber(state, result);
}

void
 cosi_tmpfile(js_State* state)
{
 FILE* stream = tmpfile();
 cosi_pushpointer(state, stream);
}

// stdlib.h

void
 cosi_abort(js_State* state)
{
  abort();
// Just a formality...
  js_pushundefined(state);
}

void
 cosi_exit(js_State* state)
{
  int code = js_tonumber(state, 1);
  exit(code);
// Just a formality...
  js_pushundefined(state);
}

void
 cosi_getenv(js_State* state)
{
  char const* key = cosi_tostring(state, 1);
  char* result = getenv(key);
  cosi_pushpointer(state, result);
}

void
 cosi_system(js_State* state)
{
  char const* command = cosi_tostring(state, 1);
  int result = system(command);
  js_pushnumber(state, result);
}

void
 cosi_rand(js_State* state)
{
  int result = rand();
  js_pushnumber(state, result);
}

void
 cosi_srand(js_State* state)
{
  unsigned seed = js_tonumber(state, 1);
  srand(seed);
  js_pushundefined(state);
}

void
 cosi_malloc(js_State* state)
{
  size_t size = js_tonumber(state, 1);
  void* buffer = malloc(size);
  cosi_pushpointer(state, buffer);
}

void
 cosi_realloc(js_State* state)
{
  void* buffer = cosi_topointer(state, 1);
  size_t size = js_tonumber(state, 2);
  void* result = realloc(buffer, size);
  cosi_pushpointer(state, result);
}

void
 cosi_calloc(js_State* state)
{
  size_t count = js_tonumber(state, 1), size = js_tonumber(state, 2);
  void* buffer = calloc(count, size);
  cosi_pushpointer(state, buffer);
}

void
 cosi_free(js_State* state)
{
  free(cosi_topointer(state, 1));
  js_pushundefined(state);
}

void
 cosi_atof(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  double result = atof(value);
  js_pushnumber(state, result);
}

void
 cosi_atoi(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  int result = atoi(value);
  js_pushnumber(state, result);
}

void
 cosi_atol(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  long result = atol(value);
  js_pushnumber(state, result);
}

void
 cosi_strtod(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  char** end = cosi_topointer(state, 2);
  double result = strtod(value, end);
  js_pushnumber(state, result);
}

void
 cosi_strtol(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  char** end = cosi_topointer(state, 2);
  int base = js_tonumber(state, 3);
  long result = strtol(value, end, base);
  js_pushnumber(state, result);
}

void
 cosi_strtoul(js_State* state)
{
  char const* value = cosi_tostring(state, 1);
  char** end = cosi_topointer(state, 2);
  int base = js_tonumber(state, 3);
  unsigned result = strtoul(value, end, base);
  js_pushnumber(state, result);
}

// string.h

void
 cosi_strlen(js_State* state)
{
  int length = strlen(cosi_tostring(state, 1));
  js_pushnumber(state, length);
}

void
 cosi_strncpy(js_State* state)
{
  char* dst = cosi_topointer(state, 1);
  char const* src = cosi_tostring(state, 2);
  int length = js_tonumber(state, 3);
  char* result = strncpy(dst, src, length);
  cosi_pushpointer(state, result);
}

void
 cosi_puts(js_State* state)
{
  int result = puts(cosi_tostring(state, 1));
  js_pushnumber(state, result);
}

void
 cosi_fputs(js_State* state)
{
  const char* text = cosi_tostring(state, 1);
  FILE* stream = cosi_topointer(state, 2);
  js_pushnumber(state, fputs(text, stream));
}

void
 cosi_isalnum(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isalnum(ch));
}

void
 cosi_isalpha(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isalpha(ch));
}

void
 cosi_isblank(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isblank(ch));
}

void
 cosi_iscntrl(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, iscntrl(ch));
}

void
 cosi_isdigit(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isdigit(ch));
}

void
 cosi_isgraph(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isgraph(ch));
}

void
 cosi_islower(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, islower(ch));
}

void
 cosi_isprint(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isprint(ch));
}

void
 cosi_ispunct(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, ispunct(ch));
}

void
 cosi_isspace(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isspace(ch));
}

void
 cosi_isupper(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isupper(ch));
}

void
 cosi_isxdigit(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, isxdigit(ch));
}

void
 cosi_tolower(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, tolower(ch));
}

void
 cosi_toupper(js_State* J)
{
 int ch = js_tonumber(J, 1);
 cosi_pushnumber(J, toupper(ch));
}

void
 cosi_errno(js_State* J)
{
 if(js_isnumber(J, 1))
  errno = js_tonumber(J, 1);
 cosi_pushnumber(J, errno);
}

#ifndef cosi_no_posix

// dirent.h

void
 cosi_opendir(js_State* J)
{
 char* name = cosi_tostring(J, 1);
 cosi_pushpointer(J, opendir(name)); 
}

void
 cosi_readdir(js_State* J)
{
 void* handle = cosi_topointer(J, 1);
 cosi_pushpointer(J, readdir(handle)); 
}

void
 cosi_dirent_name(js_State* J)
{
 struct dirent* info = cosi_topointer(J, 1);
 js_pushstring(J, info->d_name); 
}

void
 cosi_dirent_type(js_State* J)
{
 struct dirent* info = cosi_topointer(J, 1);
 js_pushnumber(J, info->d_type); 
}

void
 cosi_closedir(js_State* J)
{
 void* handle = cosi_topointer(J, 1);
 cosi_pushnumber(J, closedir(handle)); 
}

void
 cosi_rewinddir(js_State* J)
{
 rewinddir(cosi_topointer(J, 1));
 js_pushundefined(J); 
}

// unistd.h

void
 cosi_chdir(js_State* J)
{
 char* path = cosi_tostring(J, 1);
 cosi_pushnumber(J, chdir(path)); 
}

void
 cosi_getcwd(js_State* J)
{
 char* buffer = cosi_topointer(J, 1);
 size_t max = js_tonumber(J, 2);
 cosi_pushpointer(J, getcwd(buffer, max)); 
}

void
 cosi_current_directory(js_State* J)
{
 char buffer[PATH_MAX + 1];
 js_pushstring(J, getcwd(buffer, sizeof(buffer))); 
}

#endif

/*
 That was automatically
 generated...do not edit!
*/
