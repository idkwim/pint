#include "lua_img.h"
#include "lua_ins.h"
#include "lua_sec.h"
#include "lua_rtn.h"
#include "lua_reg.h"
#include "lua_trace.h"
#include "lua_bbl.h"
#include "lua_sym.h"
#include "../enums/enum_img_type.h"
#include "../enums/enum_memory_type.h"
#include "../enums/enum_syscall_standard.h"
#include "../enums/enum_predicate_ia32.h"
#include "../enums/enum_ins_prop_ipf.h"
#include "../enums/enum_sec_type.h"
#include "../enums/enum_probe_mode.h"
#include "../enums/enum_reg.h"
#include "../enums/enum_reg.h"
#include "../enums/enum_regname.h"
#include "../enums/enum_undecoration.h"
#include "../enums/enum_ipoint.h"
#include "../enums/enum_call_order.h"
#include "../enums/enum_iarg_type.h"

#include "../gen_fn/lua_trace.h"
#include "lua_class.h"
#include "pin.H"

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}
int TRACE_to_lua(lua_State *L, TRACE trace) {
    TRACE *i = (TRACE *)lua_newuserdata(L, sizeof(TRACE));
    *i = trace;
    luaL_getmetatable(L, "pin.Trace");
    lua_setmetatable(L, -2);
  return 1;
}

TRACE *check_trace (lua_State *L, int pos) {
  void *ud = luaL_checkudata(L, pos, "pin.Trace");
  luaL_argcheck(L, ud != NULL, pos, "`Trace' expected");
  return (TRACE *)ud;
}

int luaopen_trace (lua_State *L) {
  luaL_newmetatable(L, "pin.Trace");

  lua_pushstring(L, "__index");
  lua_pushvalue(L, -2);  /* pushes the metatable */
  lua_settable(L, -3);  /* metatable.__index = metatable */
  luaL_openlib(L, NULL, trace_lib_m, 0);

  luaL_openlib(L, "Trace", trace_lib, 0);
  return 1;
}
int trace_original (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  BOOL r = TRACE_Original(*v1);
  lua_pushboolean(L, r);
  return 1;
}
int trace_bbl_tail (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  BBL_to_lua(L, TRACE_BblTail(*v1));
  return 1;
}
int trace_num_ins (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  UINT32 r = TRACE_NumIns(*v1);
  lua_pushnumber(L, r);
  return 1;
}
int trace_num_bbl (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  UINT32 r = TRACE_NumBbl(*v1);
  lua_pushnumber(L, r);
  return 1;
}
int trace_bbl_head (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  BBL_to_lua(L, TRACE_BblHead(*v1));
  return 1;
}
int trace_stub_size (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  USIZE r = TRACE_StubSize(*v1);
  lua_pushnumber(L, r);
  return 1;
}
int trace_rtn (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  RTN_to_lua(L, TRACE_Rtn(*v1));
  return 1;
}
int trace_address (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  ADDRINT r = TRACE_Address(*v1);
  lua_pushnumber(L, r);
  return 1;
}
int trace_has_fall_through (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  BOOL r = TRACE_HasFallThrough(*v1);
  lua_pushboolean(L, r);
  return 1;
}
int trace_size (lua_State *L) {
  TRACE* v1 = check_trace(L,1);
  USIZE r = TRACE_Size(*v1);
  lua_pushnumber(L, r);
  return 1;
}
