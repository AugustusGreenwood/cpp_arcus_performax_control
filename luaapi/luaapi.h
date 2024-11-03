#ifndef LUAAPI_H
#define LUAAPI_H

#include "device.h"
#include <lua.hpp>

void luaapi_runProgram(std::string program, Device *device);

#endif // LUA_API_H
