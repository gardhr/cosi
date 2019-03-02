[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![GitHub license](https://img.shields.io/badge/license-ISC-blue.svg)](https://opensource.org/licenses/ISC)

# Cosi (Javascript Native Runtime)

## C API

`cosi_data
 cosi_unpack(cosi J)`

const char*
 cosi_message(cosi J);

cosi_bool
 cosi_success(cosi J);

cosi
 cosi_destroy(cosi J);

cosi_bool
 cosi_extend(cosi J, const char* symbol, void (*code)(cosi));

cosi_bool
 cosi_define(cosi J, const char* symbol, double value);

cosi_bool
 cosi_declare(cosi J, const char* symbol, void* value);

cosi_bool
 cosi_run(cosi J, const char* script);

cosi_bool
 cosi_eval(cosi J, const char* script);

cosi_bool
 cosi_include(cosi J, const char* file);

void
 cosi_main(cosi J, char** argv, char** envp);

cosi
 cosi_create_from(js_Alloc alloc, void* context, int flags);

cosi
 cosi_create(void);

void
 cosi_set_global(cosi J);

cosi
 cosi_get_global(void);


## Javascript API

## License

This library is released under [a dual MIT/ISC license](https://raw.githubusercontent.com/gardhr/cosi/master/LICENSE). <img align="right" src="https://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">

`Powered by` [MuJS](https://mujs.com) <img align="right" src="https://mujs.com/images/mujs_logo_web.png">
