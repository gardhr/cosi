[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![GitHub license](https://img.shields.io/badge/license-ISC-blue.svg)](https://opensource.org/licenses/ISC)

This software is released under [a dual MIT/ISC license](https://raw.githubusercontent.com/gardhr/cosi/master/LICENSE).

# Cosi (Javascript Native Runtime)

Cosi is an extremely cross-platform C library and interpreter with no dependancies. Powered by the [MuJS](https://mujs.com) Javascript (ES5) engine, Cosi provides an interface to most of the ISO C standard API. Not to mention all the familiar favorites like NULL, stdin/stdout, INT_MAX, etc. Plus...C pointers right from Javascript!

## Installation

Cosi requires no installation. For simple projects just #include "cosi.c" and compile. (Note, if compiling multiple modules separately, you will need to #include "cosi.h" instead and also #define cosi_standard_linkage in order to prevent linker errors.)

## Command Line Interpreter

Cosi comes with a very simple VM for running scripts.   

`git clone https://github.com/gardhr/cosi`

`cd cosi`

`gcc -o cvm -lm cvm.c`

`./cvm examples/mechanical.js` 

## Status

The current version of Cosi is 1.0 and is stable for release. No breaking changes will be allowed in the future. 

## Caveats

Proper use of Cosi requires at the very least a fairly basic understanding of the C programming language.
The library performs little to no preprocessing of arguments passed to the C API functions and so naturally if used incorrectly problems such as abnormal program termination can easily arise. Bottom line, C API functions should be used with extreme care. Consider wrapping raw C calls inside of "safer" Javascript versions of those functions.

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

Declares a new global Javascript "blob" (C pointer) variable.



`cosi_bool cosi_run(cosi J, const char* script)`

Runs some Javascript code.



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

NOTE: Pass NULL as the cosi handle to any of the above functions in order to use the global cosi instance (one will be created if none exists).


## Javascript API


`function text_to_bytes(text)`

Returns a pointer to a buffer containing the contents of a String. Memory management of the buffer is the responsibility of the caller (use the free() function). 



`function bytes_to_text(bytes, len)`

Returns a String containing the contents of a buffer. If "len" is zero then strlen(buffer) is used. 



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



`function include(file)`

Imports a file directly into the current global space.



`function sizeof(typename)`

Returns the size of some native C type. If typename contains an asterisk ("\*") then the size of a pointer is returned.



`function clog(stream, pointer)`

Prints a raw C string or String object to a C file stream. No other types are allowed for this low-level function.



`function get_byte(pointer, index)`

Returns the byte at "index" of a raw C buffer.



`function set_byte(pointer, index, value)`

Sets the byte at "index" of a raw C buffer to "value". 



`function get_memory(pointer, index, width)`

Returns the element at "index" of a raw C buffer. The "width" parameter determines how the pointer is dereferenced and MUST be the size of some native C type (int, double, void*, etc).



`function set_memory(pointer, index, value, width)`

Sets the element at "index" of a raw C buffer to "value". The "width" parameter determines how the pointer is dereferenced and MUST be the size of some native C type.



`function argv()`

Returns a raw pointer to the command-line arguments. Returns NULL if argv has not set by the calling C environment. (See cosi_main from the Cosi C API). 



`function script_arguments(skip)`

Converts argv() to an array of Strings. If "skip" is undefined OR true then the first element of the C array is not copied (skipping the script name in argv). Fails if argv has not set by the calling C environment (see cosi_main from the Cosi C API). 



`function script_path()`

Returns the path of the current script, if available. Fails if argv() has not set by the calling C environment (see cosi_main from the Cosi C API).  



`function envp()`

Returns a raw pointer to the environment strings. Fails if envp has not set by the calling C environment (see cosi_main from the Cosi C API).  



`function script_environment()`

Returns an array of the environment strings. Returns null if argv has not set by the calling C environment. (See cosi_main from the Cosi C API). 



`function print(args)`

Prints the arguments, inserting a space between each one.



`function display(args)`

Same as above but prints a newline character after all arguments have been processed.



`function read_line(stream)`

Returns a String containing a line typed by the user (or null if the input was empty). If unspecified, the default input stream is "stdin".



`function prompt(args)`

Prints all of the arguments and then waits for user input from "stdin". Returns a String containing the line typed by the user (or null if the input was empty).



`function utf_strlen(text)`

Returns the utf-8 length of a String or raw C pointer.



`function current_directory()`

Returns the current working directory.



`function process_directory(directory, callback)`

Traverses a directory recursively. The second parameter can either be a single function to be applied to each file OR an object containing one or more of the following functions: process, enter, leave. The first is applied to all files and the last two are applied to the directory itself. 



`function dirent_name(dirent)`

Returns the name of a file obtained from the 'readdir' function.



`function dirent_type(dirent)`

Returns a bitmask of the file obtained from the 'readdir' function.


## Implemented C Functions and Constants

// global pointers

NULL

stdout

stderr

stdin

// global constants

SEEK_SET

SEEK_CUR

SEEK_END

_IOFBF

_IOLBF

_IONBF

BUFSIZ

EOF

FOPEN_MAX

FILENAME_MAX

EXIT_FAILURE

EXIT_SUCCESS

RAND_MAX

MB_CUR_MAX

//stdio.h

clearerr

fopen

freopen

fseek

ftell

fgetpos

fsetpos

rewind

fread

fwrite

fgetc

getc

ungetc

fputc

putc

putchar

getchar

puts

fgets

feof

ferror

perror

fflush

fclose

remove

rename

setbuf

setvbuf

tmpfile

// stdlib.h

atof

atoi

atol

strtod

strtol

strtoul

abort

exit

getenv

system

abs

labs

rand

srand

malloc

realloc

calloc

free

strlen

strncpy

puts

fputs

// ctype.h 

isalnum

isalpha

isblank

iscntrl

isdigit

isgraph

islower

isprint

ispunct

isspace

isupper

isxdigit

tolower

toupper

// math.h

NAN

HUGE_VAL

sin

cos

tan

asin

acos

atan

atan2

sinh

cosh

tanh

exp

frexp

ldexp

log

log10

sqrt

pow

ceil

floor

abs

fabs

fmod

modf

// errno.h

errno // Note: implemented as a function

// time.h

difftime

time

clock

asctime

strftime

wcsftime

gmtime

localtime

mktime

CLOCKS_PER_SEC

// float.h

FLT_RADIX

FLT_MANT_DIG

DBL_MANT_DIG

LDBL_MANT_DIG

FLT_DIG

DBL_DIG

LDBL_DIG

FLT_EPSILON

DBL_EPSILON

LDBL_EPSILON

FLT_MIN

DBL_MIN

LDBL_MIN

FLT_MAX

DBL_MAX

LDBL_MAX

FLT_MIN_EXP

DBL_MIN_EXP

LDBL_MIN_EXP

FLT_MAX_EXP

DBL_MAX_EXP

LDBL_MAX_EXP

FLT_MIN_10_EXP

DBL_MIN_10_EXP

LDBL_MIN_10_EXP

FLT_MAX_10_EXP

DBL_MAX_10_EXP

LDBL_MAX_10_EXP

FLT_ROUNDS

// limits.h

CHAR_BIT

SCHAR_MIN

SCHAR_MAX

UCHAR_MAX

CHAR_MIN

CHAR_MAX

MB_LEN_MAX

SHRT_MIN

SHRT_MAX

USHRT_MAX

INT_MIN

INT_MAX

UINT_MAX

LONG_MIN

LONG_MAX

ULONG_MAX

LLONG_MIN

LLONG_MAX

ULLONG_MAX

// dirent.h

getcwd

chdir

// unistd.h

opendir

closedir

rewinddir

readdir

DT_UNKNOWN

DT_CHR

DT_BLK

DT_LNK

DT_WHT

DT_FIFO

DT_DIR

DT_REG

DT_SOCK
