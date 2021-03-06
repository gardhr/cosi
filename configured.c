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

cosi_define(J, "sizeof_char", sizeof(char));
cosi_define(J, "sizeof_short", sizeof(short));
cosi_define(J, "sizeof_int", sizeof(int));
cosi_define(J, "sizeof_long", sizeof(long));
cosi_define(J, "sizeof_float", sizeof(float));
cosi_define(J, "sizeof_double", sizeof(double));
cosi_define(J, "sizeof_pointer", sizeof(void*));

cosi_extend(J, "include", cosi_cosi_include);
cosi_extend(J, "sizeof", cosi_sizeof);
cosi_extend(J, "clog", cosi_clog);
cosi_extend(J, "get_memory", cosi_get_memory);
cosi_extend(J, "set_memory", cosi_set_memory);
cosi_extend(J, "get_byte", cosi_get_byte);
cosi_extend(J, "set_byte", cosi_set_byte);
cosi_extend(J, "get_short", cosi_get_short);
cosi_extend(J, "set_short", cosi_set_short);
cosi_extend(J, "get_ushort", cosi_get_ushort);
cosi_extend(J, "set_ushort", cosi_set_ushort);
cosi_extend(J, "get_int", cosi_get_int);
cosi_extend(J, "set_int", cosi_set_int);
cosi_extend(J, "get_uint", cosi_get_uint);
cosi_extend(J, "set_uint", cosi_set_uint);
cosi_extend(J, "get_long", cosi_get_long);
cosi_extend(J, "set_long", cosi_set_long);
cosi_extend(J, "get_ulong", cosi_get_ulong);
cosi_extend(J, "set_ulong", cosi_set_ulong);
cosi_extend(J, "get_float", cosi_get_float);
cosi_extend(J, "set_float", cosi_set_float);
cosi_extend(J, "get_double", cosi_get_double);
cosi_extend(J, "set_double", cosi_set_double);
cosi_extend(J, "get_pointer", cosi_get_pointer);
cosi_extend(J, "set_pointer", cosi_set_pointer);
cosi_extend(J, "bytes_to_text", cosi_bytes_to_text);
cosi_extend(J, "text_to_bytes", cosi_text_to_bytes);
cosi_extend(J, "envp", cosi_envp);
cosi_extend(J, "argv", cosi_argv);
cosi_extend(J, "timestamp", cosi_timestamp);
cosi_extend(J, "path_exists", cosi_path_exists);

//stdio.h

cosi_extend(J, "clearerr", cosi_clearerr);
cosi_extend(J, "fopen", cosi_fopen);
cosi_extend(J, "freopen", cosi_freopen);
cosi_extend(J, "fseek", cosi_fseek);
cosi_extend(J, "ftell", cosi_ftell);
cosi_extend(J, "fgetpos", cosi_fgetpos);
cosi_extend(J, "fsetpos", cosi_fsetpos);
cosi_extend(J, "rewind", cosi_rewind);
cosi_extend(J, "fread", cosi_fread);
cosi_extend(J, "fwrite", cosi_fwrite);
cosi_extend(J, "fgetc", cosi_fgetc);
cosi_extend(J, "getc", cosi_getc);
cosi_extend(J, "ungetc", cosi_ungetc);
cosi_extend(J, "fputc", cosi_fputc);
cosi_extend(J, "putc", cosi_putc);
cosi_extend(J, "putchar", cosi_putchar);
cosi_extend(J, "getchar", cosi_getchar);
cosi_extend(J, "puts", cosi_puts);
cosi_extend(J, "fgets", cosi_fgets);
cosi_extend(J, "feof", cosi_feof);
cosi_extend(J, "ferror", cosi_ferror);
cosi_extend(J, "perror", cosi_perror);
cosi_extend(J, "fflush", cosi_fflush);
cosi_extend(J, "fclose", cosi_fclose);
cosi_extend(J, "remove", cosi_remove);
cosi_extend(J, "rename", cosi_rename);
cosi_extend(J, "setbuf", cosi_setbuf);
cosi_extend(J, "setvbuf", cosi_setvbuf);
cosi_extend(J, "tmpfile", cosi_tmpfile);

// stdlib.h

cosi_extend(J, "atof", cosi_atof);
cosi_extend(J, "atoi", cosi_atoi);
cosi_extend(J, "atol", cosi_atol);
cosi_extend(J, "strtod", cosi_strtod);
cosi_extend(J, "strtol", cosi_strtol);
cosi_extend(J, "strtoul", cosi_strtoul);
cosi_extend(J, "abort", cosi_abort);
cosi_extend(J, "exit", cosi_exit);
cosi_extend(J, "getenv", cosi_getenv);
cosi_extend(J, "system", cosi_system);
cosi_extend(J, "abs", cosi_abs);
cosi_extend(J, "labs", cosi_labs);
cosi_extend(J, "rand", cosi_rand);
cosi_extend(J, "srand", cosi_srand);
cosi_extend(J, "malloc", cosi_malloc);
cosi_extend(J, "realloc", cosi_realloc);
cosi_extend(J, "calloc", cosi_calloc);
cosi_extend(J, "free", cosi_free);
cosi_extend(J, "strlen", cosi_strlen);
cosi_extend(J, "strncpy", cosi_strncpy);
cosi_extend(J, "puts", cosi_puts);
cosi_extend(J, "fputs", cosi_fputs);

// ctype.h 

cosi_extend(J, "isalnum", cosi_isalnum);
cosi_extend(J, "isalpha", cosi_isalpha);
cosi_extend(J, "isblank", cosi_isblank);
cosi_extend(J, "iscntrl", cosi_iscntrl);
cosi_extend(J, "isdigit", cosi_isdigit);
cosi_extend(J, "isgraph", cosi_isgraph);
cosi_extend(J, "islower", cosi_islower);
cosi_extend(J, "isprint", cosi_isprint);
cosi_extend(J, "ispunct", cosi_ispunct);
cosi_extend(J, "isspace", cosi_isspace);
cosi_extend(J, "isupper", cosi_isupper);
cosi_extend(J, "isxdigit", cosi_isxdigit);
cosi_extend(J, "tolower", cosi_tolower);
cosi_extend(J, "toupper", cosi_toupper);

// math.h

cosi_define(J, "NAN", NAN);
cosi_define(J, "HUGE_VAL", HUGE_VAL);

cosi_extend(J, "sin", cosi_sin);
cosi_extend(J, "cos", cosi_cos);
cosi_extend(J, "tan", cosi_tan);
cosi_extend(J, "asin", cosi_asin);
cosi_extend(J, "acos", cosi_acos);
cosi_extend(J, "atan", cosi_atan);
cosi_extend(J, "atan2", cosi_atan2);
cosi_extend(J, "sinh", cosi_sinh);
cosi_extend(J, "cosh", cosi_cosh);
cosi_extend(J, "tanh", cosi_tanh);
cosi_extend(J, "exp", cosi_exp);
cosi_extend(J, "frexp", cosi_frexp);
cosi_extend(J, "ldexp", cosi_ldexp);
cosi_extend(J, "log", cosi_log);
cosi_extend(J, "log10", cosi_log10);
cosi_extend(J, "sqrt", cosi_sqrt);
cosi_extend(J, "pow", cosi_pow);
cosi_extend(J, "ceil", cosi_ceil);
cosi_extend(J, "floor", cosi_floor);
cosi_extend(J, "abs", cosi_abs);
cosi_extend(J, "fabs", cosi_fabs);
cosi_extend(J, "fmod", cosi_fmod);
cosi_extend(J, "modf", cosi_modf);

// errno.h

cosi_extend(J, "errno", cosi_errno);

// time.h

cosi_extend(J, "difftime", cosi_difftime);
cosi_extend(J, "time", cosi_time);
cosi_extend(J, "ctime", cosi_ctime);
cosi_extend(J, "clock", cosi_clock);
cosi_extend(J, "asctime", cosi_asctime);
cosi_extend(J, "strftime", cosi_strftime);
cosi_extend(J, "wcsftime", cosi_wcsftime);
cosi_extend(J, "gmtime", cosi_gmtime);
cosi_extend(J, "localtime", cosi_localtime);
cosi_extend(J, "mktime", cosi_mktime);
cosi_define(J, "CLOCKS_PER_SEC", CLOCKS_PER_SEC);

#ifndef cosi_no_posix

// dirent.h

cosi_extend(J, "getcwd", cosi_getcwd);
cosi_extend(J, "current_directory", cosi_current_directory);
cosi_extend(J, "chdir", cosi_chdir);

// unistd.h

cosi_extend(J, "opendir", cosi_opendir);
cosi_extend(J, "closedir", cosi_closedir);
cosi_extend(J, "rewinddir", cosi_rewinddir);
cosi_extend(J, "readdir", cosi_readdir);
cosi_extend(J, "dirent_name", cosi_dirent_name);
cosi_extend(J, "dirent_type", cosi_dirent_type);

cosi_define(J, "DT_UNKNOWN", DT_UNKNOWN);
cosi_define(J, "DT_CHR", DT_CHR);
cosi_define(J, "DT_BLK", DT_BLK);
cosi_define(J, "DT_LNK", DT_LNK);
cosi_define(J, "DT_WHT", DT_WHT);
cosi_define(J, "DT_FIFO", DT_FIFO);
cosi_define(J, "DT_DIR", DT_DIR);
cosi_define(J, "DT_REG", DT_REG);
cosi_define(J, "DT_SOCK", DT_SOCK);

// sys/stat.h

cosi_extend(J, "st_dev", cosi_st_dev);
cosi_extend(J, "st_ino", cosi_st_ino);
cosi_extend(J, "st_mode", cosi_st_mode);
cosi_extend(J, "S_ISREG", cosi_S_ISREG);
cosi_extend(J, "S_ISDIR", cosi_S_ISDIR);
cosi_extend(J, "S_ISCHR", cosi_S_ISCHR);
cosi_extend(J, "S_ISBLK", cosi_S_ISBLK);
cosi_extend(J, "S_ISFIFO", cosi_S_ISFIFO);
cosi_extend(J, "S_ISLNK", cosi_S_ISLNK);
cosi_extend(J, "S_ISSOCK", cosi_S_ISSOCK);
cosi_extend(J, "st_nlink", cosi_st_nlink);
cosi_extend(J, "st_uid", cosi_st_uid);
cosi_extend(J, "st_gid", cosi_st_gid);
cosi_extend(J, "st_rdev", cosi_st_rdev);
cosi_extend(J, "st_size", cosi_st_size);
cosi_extend(J, "st_blksize", cosi_st_blksize);
cosi_extend(J, "st_blocks", cosi_st_blocks);
cosi_extend(J, "st_atime", cosi_st_atime);
cosi_extend(J, "st_mtime", cosi_st_mtime);
cosi_extend(J, "st_ctime", cosi_st_ctime);

#endif

// global pointers

cosi_declare(J, "stdout", stdout);
cosi_declare(J, "stderr", stderr);
cosi_declare(J, "stdin", stdin);
cosi_declare(J, "NULL", NULL);

// global constants

cosi_define(J, "SEEK_SET", SEEK_SET);
cosi_define(J, "SEEK_CUR", SEEK_CUR);
cosi_define(J, "SEEK_END", SEEK_END);
cosi_define(J, "_IOFBF", _IOFBF);
cosi_define(J, "_IOLBF", _IOLBF);
cosi_define(J, "_IONBF", _IONBF);
cosi_define(J, "BUFSIZ", BUFSIZ);
cosi_define(J, "EOF", EOF);
cosi_define(J, "FOPEN_MAX", FOPEN_MAX);
cosi_define(J, "FILENAME_MAX", FILENAME_MAX);
// snip? // cosi_define(J, "L_tmpnam", L_tmpnam);
// snip? // cosi_define(J, "TMP_MAX", TMP_MAX);
cosi_define(J, "EXIT_FAILURE", EXIT_FAILURE);
cosi_define(J, "EXIT_SUCCESS", EXIT_SUCCESS);
cosi_define(J, "RAND_MAX", RAND_MAX);
cosi_define(J, "MB_CUR_MAX", MB_CUR_MAX);

// float.h

cosi_define(J, "FLT_RADIX", FLT_RADIX);
cosi_define(J, "FLT_MANT_DIG", FLT_MANT_DIG);
cosi_define(J, "DBL_MANT_DIG", DBL_MANT_DIG);
cosi_define(J, "LDBL_MANT_DIG", LDBL_MANT_DIG);
cosi_define(J, "FLT_DIG", FLT_DIG);
cosi_define(J, "DBL_DIG", DBL_DIG);
cosi_define(J, "LDBL_DIG", LDBL_DIG);
cosi_define(J, "FLT_EPSILON", FLT_EPSILON);
cosi_define(J, "DBL_EPSILON", DBL_EPSILON);
cosi_define(J, "LDBL_EPSILON", LDBL_EPSILON);
cosi_define(J, "FLT_MIN", FLT_MIN);
cosi_define(J, "DBL_MIN", DBL_MIN);
cosi_define(J, "LDBL_MIN", LDBL_MIN);
cosi_define(J, "FLT_MAX", FLT_MAX);
cosi_define(J, "DBL_MAX", DBL_MAX);
cosi_define(J, "LDBL_MAX", LDBL_MAX);
cosi_define(J, "FLT_MIN_EXP", FLT_MIN_EXP);
cosi_define(J, "DBL_MIN_EXP", DBL_MIN_EXP);
cosi_define(J, "LDBL_MIN_EXP", LDBL_MIN_EXP);
cosi_define(J, "FLT_MAX_EXP", FLT_MAX_EXP);
cosi_define(J, "DBL_MAX_EXP", DBL_MAX_EXP);
cosi_define(J, "LDBL_MAX_EXP", LDBL_MAX_EXP);
cosi_define(J, "FLT_MIN_10_EXP", FLT_MIN_10_EXP);
cosi_define(J, "DBL_MIN_10_EXP", DBL_MIN_10_EXP);
cosi_define(J, "LDBL_MIN_10_EXP", LDBL_MIN_10_EXP);
cosi_define(J, "FLT_MAX_10_EXP", FLT_MAX_10_EXP);
cosi_define(J, "DBL_MAX_10_EXP", DBL_MAX_10_EXP);
cosi_define(J, "LDBL_MAX_10_EXP", LDBL_MAX_10_EXP);
cosi_define(J, "FLT_ROUNDS", FLT_ROUNDS);

// limits.h

cosi_define(J, "CHAR_BIT", CHAR_BIT);
cosi_define(J, "SCHAR_MIN", SCHAR_MIN);
cosi_define(J, "SCHAR_MAX", SCHAR_MAX);
cosi_define(J, "UCHAR_MAX", UCHAR_MAX);
cosi_define(J, "CHAR_MIN", CHAR_MIN);
cosi_define(J, "CHAR_MAX", CHAR_MAX);
cosi_define(J, "MB_LEN_MAX", MB_LEN_MAX);
cosi_define(J, "SHRT_MIN", SHRT_MIN);
cosi_define(J, "SHRT_MAX", SHRT_MAX);
cosi_define(J, "USHRT_MAX", USHRT_MAX);
cosi_define(J, "INT_MIN", INT_MIN);
cosi_define(J, "INT_MAX", INT_MAX);
cosi_define(J, "UINT_MAX", UINT_MAX);
cosi_define(J, "LONG_MIN", LONG_MIN);
cosi_define(J, "LONG_MAX", LONG_MAX);
cosi_define(J, "ULONG_MAX", ULONG_MAX);
cosi_define(J, "LLONG_MIN", LLONG_MIN);
cosi_define(J, "LLONG_MAX", LLONG_MAX);
cosi_define(J, "ULLONG_MAX", ULLONG_MAX);

/*
 That was automatically
 generated...do not edit!
*/
