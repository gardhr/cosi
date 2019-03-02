[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![GitHub license](https://img.shields.io/badge/license-ISC-blue.svg)](https://opensource.org/licenses/ISC)

This library is released under [a dual MIT/ISC license](https://raw.githubusercontent.com/gardhr/cosi/master/LICENSE).

# Cosi (Javascript Native Runtime)

## C API

`cosi cosi_create_from(js_Alloc alloc, void* context, int flags)`

Create a new Cosi instance using a MuJS-compliant allocator and allocator "context" (for most applications these can both be NULL). The flags parameter currently only supports the JS_STRICT flag.

`cosi cosi_create(void)`
 
Creates a new (strict-mode) Cosi instance using the default allocator. 

`cosi cosi_destroy(cosi J)`

Deletes a Cosi instance.

`cosi_bool cosi_extend(cosi J, const char* symbol, void (*code)(cosi))`

Maps a MuJS-compliant custom handler to a new global Javascript function.  

`cosi_bool cosi_define(cosi J, const char* symbol, double value)`

Defines a new global Javascript (Number) variable.

`cosi_bool cosi_declare(cosi J, const char* symbol, void* value)`

Defines a new global Javascript "blob" (C pointer) variable.

`cosi_bool cosi_run(cosi J, const char* script)`

Runs some Javascript code.

`cosi_bool cosi_eval(cosi J, const char* script)`

Evokes the Javascript eval() function "in line".

`cosi_bool cosi_include(cosi J, const char* file)`

Expands the code from "file" directly into the current global space.

`void cosi_main(cosi J, char** argv, char** envp)`

Gives scripts access to argv and envp.

`void cosi_set_global(cosi J)`

Set the global Cosi object. 

`cosi cosi_get_global(void)`

Get the global Cosi object. 
 
`const char* cosi_message(cosi J)`

Returns the error message generated by the last Cosi operation (if any).

`cosi_bool cosi_success(cosi J)`

Returns the result of the last Cosi operation.

## Javascript API

`function file_to_bytes(file)`

Returns a pointer to a buffer containing the contents of a file. Memory management of the buffer is the responsibility of the caller (use the free() function). 

`function file_to_text(file)`

Returns a String containing the contents of a file.

`function bytes_to_file(bytes, file, len)`

Writes the contents of a buffer to a file. If "len" is zero then strlen(buffer) is used. 

`function text_to_file(text, file)`

Writes the contents of a String to a file. 

`function text_to_function(script, imports)`

Returns a Function object that encapsulates a script and its imports.

`function file_to_function(file, imports)`

Same as above but using the contents of a file instead of a String. 

`function text_to_task(script, imports)`

Runs a script with the given imports. Returns false on error.

`function file_to_task(file, imports)`

Same as above but using the contents of a file instead of a String. 

`function text_to_module(script, imports)`

Returns a reference to a loaded script.

`function file_to_module(file, imports)`

Same as above but using the contents of a file instead of a String. 

`function text_to_object(script, imports)`

Returns a reference to a loaded object. Script should be in the form of "{ foo: "bar", baz: 1024 }".

`function file_to_object(file, imports)`

Same as above but using the contents of a file instead of a String. 

`function print_partial(args)`

Prints the arguments, inserting a space between each one.

`function print(args)`

Same as above but prints a newline character after all arguments have been processed.

`function gets_bytes(stream)`

Returns a pointer to a buffer containing a line typed by the user (or NULL if the input is empty). Memory management of the buffer is the responsibility of the caller (use the free() function). If unspecified, the default input stream is "stdin".

`function gets_text(stream)`

Returns a String containing a line typed by the user (or NULL if the input is empty). If unspecified, the default input stream is "stdin".

`function prompt(args)`

Prints all of the args and then waits for user input from "stdin". Returns a String containing the line typed by the user (or NULL if the input is empty).

`function to_text_array(array, skip)`

Converts a C array of string pointers to an array of Strings. If "skip" is true then the first element of the C array is not copied (useful when used with argv() for example).

`function script_path()`

Returns the path of the current script, if available. Fails if argv() has not set by the calling C environmet (see cosi_main from the Cosi C API).  

`function text_to_ascii(text)`

Helper function to convert a String to an Array of Numbers.

`function ascii_to_text(ascii)`

Helper function to convert an Array of Numbers to String.

<br/>
<br/>

`Powered by` [MuJS](https://mujs.com) <img align="bottom" src="https://mujs.com/images/mujs_logo_web.png">
