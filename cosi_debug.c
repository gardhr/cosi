/*
 Just a scratch pad for testing...

 For this feature to work be sure to 
 compile with cosi_debugging defined

 Whatever is put here will be made 
 accessible to the Javascript environment 
 via the similarly named debug() function

*/

#include "cosi.h"

void
 cosi_debug(js_State* state)
{
  size_t count = js_gettop(state);
  for (size_t idx = 0; idx < count; ++idx)
    puts(cosi_tostring(state, idx));
  js_pushundefined(state);
}
