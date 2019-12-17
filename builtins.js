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
 Imports
*/

var imports = {}

/*
 Utilities
*/

function char(text, index)
{ 
 return text.charCodeAt(index | 0)
}

function text(code)
{ 
 return String.fromCharCode(code)
}

function text_to_array(text)
{
 var arr = []
 for(var tdx = 0, len = text.length; tdx < len; ++tdx)
  arr.push(char(text, tdx))  
 return arr
}

function array_to_text(array)
{ 
 var txt = ""
 for(var tdx = 0, len = array.length; tdx < len; ++tdx)
  txt += text(array[tdx])  
 return txt
}

function escape(exception)
{ 
 if(exception)
  throw exception
 if(!(this instanceof escape))
  escape(new escape()) 
}

function verify(object, exception)
{
 if(!object)
  escape(exception)
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
 catch(exception)
 {
  if(handler)
   handler(exception)
  return exception
 }
}

function contain(routine, handler)
{
 var 
  exception = caught(routine, handler)
 if(exception)
 {
  print("Error:", exception)
  var est = exception.stackTrace
  if(est)
   print(est)
 }
 return exception
}

function escaped(routine, handler)
{
 try
 {
  routine()
  return false
 }
 catch(exception)
 {
  if(exception instanceof escape)
   return true
  if(handler)
   handler(exception)
  escape(exception) 
 }
}

function loop(control, action)
{
 if(!control)
  return
 if(control === true)
  control = Infinity
 var
  result,
  count = control.length || 
   control.end || control.finish || 
   control,
  start = control.begin 
   || control.start || 0
 escaped(function(){
  for(var idx = start; idx < count; ++idx)
  {
   result = action(idx, control)
   if(result !== undefined)
    break
  }
 })
 return result
}

/* https://stackoverflow.com/questions/5515869/string-length-in-bytes-in-javascript
*/

function utf_strlen(text)
{
 if(text > 0)
  text = bytes_to_text(text)
 var length = text.length
 var extras = text.match(/%[89ABab]/g);
 if(extras)
  length += extras.length
 return length
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
  data = packed ? null : NULL
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
  len = utf_strlen(bytes)
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
 if(source == null)
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
 var pass = bytes_to_file(data, file, utf_strlen(data))
 free(data)
 return pass
}

/*
 Conversions to Javascript objects
*/
function text_to_function(script, imports)
{
 if(!script)
  return null
 var hash = char("#"), 
  bang = char("!"),
  idx = 0, 
  len = script.length
 while(idx < len && isspace(char(script, idx)))
  ++idx
 if(len - idx >= 2)
 {
  if
  (
   char(script, idx) == hash && 
   char(script, idx + 1) == bang
  )
   script = "//" + script
 }
 var result = null
 contain(function(){
  var bundled = 
   'return function(){' + 
   ' var module = { exports : null };' +
   ' var exports = (function(){' +
   script + 
   '})(); return exports ? exports : module.exports }'
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

/* FIXME */
/*
function object_to_text(object)
{
 var flg = false, dsc = "{"
 for(var key in object)
 {
  if(flg)
   dsc += ","
  else
   flg = true
  dsc += "\n"  
  var mem = object[key]
  if(typeof(mem) === "string")
   mem = "'" + mem + "'"
  dsc += " " + key + " : " + mem
 }
 dsc += "\n}"
 return dsc
}

function object_to_file(object, file)
{
 return text_to_file(object_to_text(object), file)
}
*/

/*
 Input and output
*/

function log_display(stream)
{
 var args = arguments
 var first = 1
 for(var index = first; index < args.length; ++index)
 {
  if(index > first)
   clog(stream, ' ')
  var arg = args[index];
  if(arg === null)
   arg = '(null)'
  else if(arg === undefined)
   arg = '(undefined)'
  clog(stream, arg.toString())
 }
}

function log_print()
{
 log_display.apply(null, arguments)
 putchar(0xa)
}

function display()
{
 [].unshift.call(arguments, stdout)
 log_display.apply(null, arguments)
}

function print()
{
 [].unshift.call(arguments, stdout)
 log_print.apply(null, arguments)
}

function read_line(stream)
{
 if(!stream)
  stream = stdin
 var newline = 0xa,
  res = "",
  max = 32, 
  siz = max + 1, 
  buf = read_line.buf
 if(!buf)
  buf = read_line.buf = malloc(siz)
 while(true)
 {
  if(!fgets(buf, siz, stream))
   return res.length == 0 ? null : res
  var len = strlen(buf), lst = len ? len - 1 : 0 
  if(get_byte(buf, lst) == newline)
   set_byte(buf, len = lst, 0)
  res += bytes_to_text(buf)
  if(len != max)
   return res
 }
}

function prompt()
{
 display.apply(null, arguments)
 clog(stdout, ' ')
 return read_line()
}

function script_arguments(skip_first)
{
 var args = argv()
 if(args == NULL)
  return null
 var tab = []
 if(get_memory(args) == NULL)
  return tab
 var align = sizeof('void*')
 if(skip_first !== false)
  args += align
 for(;;)
 {
  var ptr = get_memory(args)
  if(ptr == NULL)
   break
  tab.push(bytes_to_text(ptr))
  args += align
 }
 return tab
}

function script_environment()
{
 var args = envp()
 var tab = []
 if(args == NULL)
  return null
 var align = sizeof('void*')
 for(;;)
 {
  var ptr = get_memory(args)
  if(ptr == NULL)
   break
  tab.push(bytes_to_text(ptr))
  args += align
 }
 return tab
}

function script_path()
{
 var args = argv()
 if(!args)
  return null
 return bytes_to_text(get_memory(args))
}

function process_directory(directory, callback)
{
 var enter = callback.enter
 var process = callback.process || callback
 var leave = callback.leave
 var saved = current_directory()
 var handle = opendir(directory)
 if(handle != NULL)
 {
  if(enter)
   enter(directory)
  chdir(directory)
  while(true)
  {
   var info = readdir(handle)
   if(info == NULL)
    break
   var path = dirent_name(info)
   if(path == "." || path == "..")
    continue
   var type = dirent_type(info)
   if(type & DT_DIR)
    process_directory(path, callback)
   else
    process(path, type) 
  } 
  if(leave)
   leave(directory)
  closedir(handle)
 }
 chdir(saved)
}
