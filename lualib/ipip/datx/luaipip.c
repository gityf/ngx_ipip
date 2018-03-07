#include <lua.h>
#include <lauxlib.h>
#include "ipip.h"

static int l_find(lua_State *L) {
  const char *ip= luaL_checkstring(L, 1);
  char result[500] = {0};
  if (ip == NULL) {
    return 0;
  }
  find(ip, result);
  lua_pushstring(L, result);
  return 1;
}

static int l_init(lua_State *L) {
  const char *dat= luaL_checkstring(L, 1);
  if (dat == NULL) {
    return 0;
  }
  init(dat); 
  return 1;
}

static const struct luaL_Reg funcs[] = {
  {"ipip_find", l_find},
  {"ipip_init", l_init},
  {NULL, NULL}
};

int luaopen_libluaipip(lua_State *L) {
  luaL_register(L, "libluaipip", funcs);
  return 1;
}
