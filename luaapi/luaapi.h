#ifndef LUAAPI_H
#define LUAAPI_H

#include "device.h"
#include <luajit-2.1/lua.hpp>

void luaapi_runProgram(std::string program, Device *device);

#endif // LUA_API_H
