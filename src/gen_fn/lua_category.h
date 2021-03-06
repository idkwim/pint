
#ifndef __PINT_LUA_CATEGORY_WRAPPER__
#define __PINT_LUA_CATEGORY_WRAPPER__

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

#include "pin.H"
#include "lua_img.h"
#include "lua_ins.h"
#include "lua_sec.h"
#include "lua_rtn.h"
#include "lua_reg.h"
#include "lua_trace.h"
#include "lua_bbl.h"
#include "lua_sym.h"


int luaopen_category (lua_State *L);
int category_string_short (lua_State *L) ; 
const struct luaL_reg category_lib [] = {
  	{"string_short",category_string_short},

  {NULL, NULL}
};

#endif
