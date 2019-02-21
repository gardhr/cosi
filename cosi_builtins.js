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

/*
 Imports
*/
var imports = {}

/*
 Utilities
*/

function through(action)
{
 return (action instanceof Function) ?
  action : action ? 
   function(){ return action } :
   function(value){ return value }
}

function egress(exception)
{ 
 if(exception)
  throw exception
 if(!(this instanceof egress))
  egress(new egress()) 
}

function verify(object, exception)
{
 if(!object)
  egress(exception)
}

function fail(condition, exception)
{
 verify(!condition, exception) 
}

function caught(routine, handler)
{
 try
 {
  routine()
  return undefined
 }
 catch(error)
 {
  return through(handler)(error)
 }
}

function contain(routine, handler)
{
 var 
  exception = caught(routine, handler)
 if(exception)
  print("Error:", exception)
 return exception
}

function escape(routine, handler)
{
 try
 {
  routine()
  return false
 }
 catch(exception)
 {
  if(exception instanceof egress)
   return true
  through(handler)(exception)
  egress(exception) 
 }
}

function loop(control, action)
{
 var
  result, 
  count = control.length || control.end || 
   control.finish || control || 0,
  start = control.begin || control.start || 0
 escape(function(){
  for(var idx = start; idx < count; ++idx)
  {
   result = action(idx, control)
   if(result !== undefined)
    break
  }
 })
 return result
}

/*
 Common conversions
*/
function file_to_bytes(source)
{
 var 
  fp = NULL,
  length = 0,
  data = NULL,
  packed = source.file,
  file = packed || source,
  error = caught(function(){ 
   fp = fopen(file, 'rb')
   verify(fp)
   fseek(fp, 0, SEEK_END)
   length = ftell(fp)
   rewind(fp)
   data = malloc(length + 1)
   verify(data)
   verify(length == fread(data, 1, length, fp))
   set_byte(data, length, 0)
   if(packed)
   { 
    source.length = length
    source.bytes = data
    data = source
   }
  })
 if(error)
 {
  free(data)
  data = NULL
 }
 if(fp)
  fclose(fp)
 return data
}

function bytes_to_file(bytes, file, len)
{
 if(bytes == NULL)
  return false
 var out = file
 if(!(file > 0))
  out = fopen(file, 'wb+')
 if(!len)
  len = strlen(bytes)
 var pass = false
 if(out)
 {
  if(fwrite(bytes, 1, len, out) == len)
   pass = true
  fclose(out)
 }
 return pass
}

function file_to_text(file)
{
 var source = file_to_bytes({ file : file })
 if(source == NULL)
  return null
 var 
  bytes = source.bytes,
  result = bytes_to_text(bytes, source.length)
 free(bytes)
 return result
}

function text_to_file(text, file)
{
 var data = text_to_bytes(text)
 var pass = bytes_to_file(data, file, text.length)
 free(data)
 return pass
}

/*
 Conversions to Javascript objects
*/
function text_to_function(script, imports)
{
 var result = null
 caught(function(){
  var bundled = 'return function(){' + script + '}'
  var invoke = new Function('imports', bundled)
  result = invoke(imports)
 })
 return result
}

function text_to_task(script, imports)
{
 var loaded = text_to_function(script, imports);
 if(loaded)
  loaded()
 else
  return false
 return true
}

function text_to_module(script, imports)
{
 var loaded = text_to_function(script, imports);
 return loaded ? loaded() : null
}

function text_to_object(script, imports)
{
 return text_to_module('return ' + script, imports)
}

function file_to_function(script, imports)
{
 return text_to_function(file_to_text(file), imports)
}

function file_to_task(file, imports)
{
 return text_to_task(file_to_text(file), imports)
}

function file_to_module(file, imports)
{
 return text_to_module(file_to_text(file), imports)
}

function file_to_object(file)
{
 return text_to_object(file_to_text(file), imports)
}

/*
 Input and output
*/
function print_partial()
{
 var args = arguments
 var next = function(index)
 {
  if(index != 0)
   put(' ')
  var arg = args[index];
  if(arg === null)
   arg = '(null)'
  else if(arg === undefined)
   arg = '(undefined)'
  put(arg.toString())
 }
 loop(arguments, next)
}

function print()
{
 print_partial.apply(null, arguments)
 putchar(0xa)
}

function gets_bytes(stream)
{
 var sum = 0
 var size = 64
 var data = NULL
 var newline = 0xa
 if(!stream)
  stream = stdin
 for(;;)
 {
  var max = size
  size *= 2
  data = realloc(data, size + 1)
  if(data == NULL)
   return NULL
  var line = data + sum
  if(!fgets(line, max, stream))
   break
  var length = strlen(line)
  var last = length - 1 
  if(get_byte(line, last) == newline) 
   set_byte(line, last--, 0)
  sum += last + 1
  if(length != max)
   break
 }
 if(sum == 0)
 {
  free(data)
  return NULL 
 }
 return data  
}

function gets_text(stream)
{
 var bytes = gets_bytes(stream)
 var text = bytes ? bytes_to_text(bytes) : null
 free(bytes)
 return text
} 

function prompt()
{
 print_partial.apply(null, arguments)
 put(' ')
 return gets_text()
}

/*
 TODO: snip?
*/
function text_to_ascii(text)
{
 var chars = [] 
 var data = text_to_bytes(text)
 var push = function(index)
 { 
  chars.push(get_byte(data, index)) 
 }
 loop(strlen(data), push)
 free(data)
 return chars
}

function ascii_to_text(ascii)
{
 var bytes = malloc(ascii.length + 1)
 var place = function(counter)
 {
  set_byte(bytes, counter, ascii[counter])
 }
 set_byte(bytes, ascii.length, 0)
 loop(ascii, place)
 var text = bytes_to_text(bytes)
 free(bytes)
 return text
}
