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

var args = script_arguments(false)
if(args.length == 0)
{
 print("Cosi Native Runtime for Javascript")
 var cosi = bytes_to_text(get_memory(argv(), -1))
 print("Usage:", cosi, "script-name script-arg0 ...")
 print("Interactive mode: waiting for input...")
 var script = ""
 while(true)
 {
  try
  {  
   var line = read_line()
/*
 Accumulate 
*/
   script += line   
   var result = eval(script)
/*
 If we got this far we can go ahead and reset 
*/
   script = ""
   if(result !== undefined)
    print(result)
  }
  catch(error)
  {
   var message = error.toString()
   if(message.search(/end-of-file/))
    continue
   print("Error:", message)
   if(error.stackTrace)
    print(error.stackTrace)
  }
 }
}
else 
{
 var file = args[0]
 if(!file_to_task(file))
  if(!file_to_task(file + '.js'))
   throw Error('cannot load file ' + file)
}
