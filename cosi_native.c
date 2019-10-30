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

void
 cosi_cosi_include(js_State* state)
{
 char* script = cosi_tostring(state, 1);
 int result = cosi_include(state, script);
 js_pushboolean(state, result);
}

void
 cosi_clog(js_State* state)
{
 FILE* stream = cosi_topointer(state, 1);
 const char* text = cosi_tostring(state, 2);
 int result = fprintf(stream, "%s", text);
 js_pushnumber(state, result);
}

void
 cosi_sizeof(js_State* state)
{
 char* what = cosi_tostring(state, 1);
 int result = 0;
 if (strstr(what, "*") != NULL)
  result = sizeof(void*);
 else if (strstr(what, "long"))
  result = sizeof(long);
 else if (strstr(what, "char"))
  result = sizeof(char);
 else if (strstr(what, "short"))
  result = sizeof(short);
 else if (strstr(what, "int"))
  result = sizeof(int);
// TODO: remove for C++ compatability?
 else if (!strcmp(what, "long long"))
  result = sizeof(long long);
 else if (strstr(what, "float"))
  result = sizeof(float);
 else if (strstr(what, "double"))
  result = sizeof(double);
 else if (strstr(what, "size_t"))
  result = sizeof(size_t);
 else if (strstr(what, "fpos_t"))
  result = sizeof(fpos_t);
 else if (strstr(what, "wchar_t"))
  result = sizeof(wchar_t);
 else if (strstr(what, "div_t"))
  result = sizeof(div_t);
 else if (strstr(what, "ldiv_t"))
  result = sizeof(ldiv_t);
 js_pushnumber(state, result);
}

void
 cosi_bytes_to_text(js_State* state)
{
 char* data = cosi_topointer(state, 1);
 if(data == NULL)
 {
  js_pushnull(state);
  return;
 } 
 size_t size = js_tonumber(state, 2);
 if (size == 0)
  size = strlen(data);
 char* copy = malloc(size + 1);
 strncpy(copy, data, size);
 copy[size] = 0;
 js_pushstring(state, copy);
 free(copy);
}

void
 cosi_text_to_bytes(js_State* state)
{
 char const* src = cosi_tostring(state, 1);
 int size = strlen(src);
 char* dst = malloc(size + 1);
 char* result = strcpy(dst, src);
 cosi_pushpointer(state, result);
}

void
 cosi_set_byte(js_State* state)
{
 char* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 int value = cosi_tobyte(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_set_short(js_State* state)
{
 short* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_set_int(js_State* state)
{
 int* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_set_long(js_State* state)
{
 long* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_set_float(js_State* state)
{
 float* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_set_double(js_State* state)
{
 double* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 data[index] = value;
 js_pushundefined(state);
}

void
 cosi_get_byte(js_State* state)
{
 char* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_get_short(js_State* state)
{
 short* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_get_int(js_State* state)
{
 int* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_get_long(js_State* state)
{
 long* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_get_float(js_State* state)
{
 float* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_get_double(js_State* state)
{
 double* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 js_pushnumber(state, data[index]);
}

void
 cosi_set_memory(js_State* state)
{
 void* data = cosi_topointer(state, 1);
 size_t index = js_tonumber(state, 2);
 double value = js_tonumber(state, 3);
 double real = js_tonumber(state, 4);
/*
 TODO: use a lookup table?
*/
  if (real == 1 / sizeof(float))
    ((float*)data)[index] = value;
  else if (real == 1 / sizeof(double))
    ((double*)data)[index] = value;
  else {
    int size = real;
    if (size == 0)
      ((void**)data)[index] = (void*)((size_t)value); 
    else if (size == sizeof(unsigned char))
      ((unsigned char*)data)[index] = value;
    else if (size == -sizeof(char))
      ((char*)data)[index] = value;
    else if (size == sizeof(unsigned))
      ((unsigned*)data)[index] = value;
    else if (size == -sizeof(int))
      ((int*)data)[index] = value;
    else if (size == sizeof(unsigned short))
      ((unsigned short*)data)[index] = value;
    else if (size == -sizeof(short))
      ((short*)data)[index] = value;
    else if (size == sizeof(unsigned long))
      ((unsigned long*)data)[index] = value;
    else if (size == -sizeof(long))
      ((long*)data)[index] = value;
    else if (size == sizeof(unsigned long long))
      ((unsigned long long*)data)[index] = value;
    else if (size == -sizeof(long long))
      ((long long*)data)[index] = value;
  }
  js_pushundefined(state);
}

void
cosi_get_memory(js_State* state)
{
  double value = 0;
  void* data = cosi_topointer(state, 1);
  size_t index = js_tonumber(state, 2);
  double real = js_tonumber(state, 3);
/*
 TODO: use a lookup table?
*/
  if (real == 1 / sizeof(float))
    value = ((float*)data)[index];
  else if (real == 1 / sizeof(double))
    value = ((double*)data)[index];
  else {
    int size = real;
    if (size == 0)
      value = (size_t)(((void**)data)[index]);
    else if (size == sizeof(unsigned char))
      value = ((unsigned char*)data)[index];
    else if (size == -sizeof(char))
      value = ((char*)data)[index];
    else if (size == sizeof(unsigned))
      value = ((unsigned*)data)[index];
    else if (size == -sizeof(int))
      value = ((int*)data)[index];
    else if (size == sizeof(unsigned short))
      value = ((unsigned short*)data)[index];
    else if (size == -sizeof(short))
      value = ((short*)data)[index];
    else if (size == sizeof(unsigned long))
      value = ((unsigned long*)data)[index];
    else if (size == -sizeof(long))
      value = ((long*)data)[index];
    else if (size == sizeof(unsigned long long))
      value = ((unsigned long long*)data)[index];
    else if (size == -sizeof(long long))
      value = ((long long*)data)[index];
  }
  js_pushnumber(state, value);
}

void
 cosi_timestamp(js_State* state)
{
 time_t info = time(NULL);
 char* text = ctime(&info);
 unsigned 
  len = strlen(text), 
  end = len ? len - 1 : 0;
 if(text[end] == '\n')
  text[end] = 0; 
 js_pushstring(state, text);
}
