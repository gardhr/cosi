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

void
 cosi_put(js_State* state)
{
  int result = printf("%s", cosi_tostring(state, 1));
  js_pushnumber(state, result);
}

void
 cosi_fput(js_State* state)
{
  const char* text = cosi_tostring(state, 1);
  FILE* stream = cosi_topointer(state, 2);
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
  else if (!strcmp(what, "char"))
    result = sizeof(char);
  else if (!strcmp(what, "short"))
    result = sizeof(short);
  else if (!strcmp(what, "int"))
    result = sizeof(int);
  else if (!strcmp(what, "long"))
    result = sizeof(long);
  else if (!strcmp(what, "long long"))
    result = sizeof(long long);
  else if (!strcmp(what, "float"))
    result = sizeof(float);
  else if (!strcmp(what, "double"))
    result = sizeof(double);
  else if (!strcmp(what, "size_t"))
    result = sizeof(size_t);
  else if (!strcmp(what, "fpos_t"))
    result = sizeof(fpos_t);
  else if (!strcmp(what, "wchar_t"))
    result = sizeof(wchar_t);
  else if (!strcmp(what, "div_t"))
    result = sizeof(div_t);
  else if (!strcmp(what, "ldiv_t"))
    result = sizeof(ldiv_t);
  js_pushnumber(state, result);
}

void
 cosi_bytes_to_text_inplace(js_State* state)
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
  char saved = data[size];
  data[size] = 0;
  js_pushstring(state, data);
  data[size] = saved;
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
 cosi_get_byte(js_State* state)
{
  unsigned char* data = cosi_topointer(state, 1);
  size_t index = js_tonumber(state, 2);
  js_pushnumber(state, data[index]);
}

void
 cosi_set_byte(js_State* state)
{
  unsigned char* data = cosi_topointer(state, 1);
  size_t index = js_tonumber(state, 2);
  int value = cosi_tobyte(state, 3);
  data[index] = value;
  js_pushundefined(state);
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
    if (size == sizeof(unsigned char))
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
    else if (size == 0)
      ((void**)data)[index] = (void*)((size_t)value);
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
    if (size == sizeof(unsigned char))
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
    else if (size == 0)
      value = (size_t)(((void**)data)[index]);
  }
  js_pushnumber(state, value);
}

/*
 That was automatically
 generated...do not edit!
*/
