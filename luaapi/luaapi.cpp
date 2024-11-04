#include "luaapi.h"
#include <iostream>

// This file feels better than my Qt gui, but I still feel like theres improvments
// somewhere
//
// Is it inefficient to pass device like this? The casting and transfering from lua seems
// like it might be expensive
int luaapi_getPulsePosition(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int position = device->getPulsePosition();
	lua_pushinteger(L, position);
	return 1;
}
int luaapi_getHighSpeed(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = device->getHighSpeed();
	lua_pushinteger(L, speed);
	return 1;
}
int luaapi_getEncoderPosition(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int position = device->getEncoderPosition();
	lua_pushinteger(L, position);
	return 1;
}
int luaapi_getMotorStatus(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int status = device->getMotorStatus();
	lua_pushinteger(L, status);
	return 1;
}
int luaapi_getCurrentPulseSpeed(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = device->getCurrentPulseSpeed();
	lua_pushinteger(L, speed);
	return 1;
}
int luaapi_getAccelerationTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int acceleration = device->getAccelerationTime();
	lua_pushinteger(L, acceleration);
	return 1;
}
int luaapi_getDecelerationTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int deceleration = device->getDecelerationTime();
	lua_pushinteger(L, deceleration);
	return 1;
}
int luaapi_getIdleCurrent(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int current = device->getIdleCurrent();
	lua_pushinteger(L, current);
	return 1;
}
int luaapi_getIdleTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int time = device->getIdleTime();
	lua_pushinteger(L, time);
	return 1;
}
int luaapi_getMicrosteps(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int microsteps = device->getMicrosteps();
	lua_pushinteger(L, microsteps);
	return 1;
}
int luaapi_getRunCurrent(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int current = device->getRunCurrent();
	lua_pushinteger(L, current);
	return 1;
}
int luaapi_getLowSpeed(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = device->getLowSpeed();
	lua_pushinteger(L, speed);
	return 1;
}
int luaapi_setEncoderPosition(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int position = luaL_checkinteger(L, 2);
	device->setEncoderPosition(position);
	return 0;
}
int luaapi_setIncrementalMovement(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->setIncrementalMovement();
	return 0;
}
int luaapi_setAbsoluteMovement(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->setAbsoluteMovement();
	return 0;
}
int luaapi_setPulsePosition(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setPulsePosition(speed);
	return 0;
}
int luaapi_setAccelerationTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setAccelerationTime(speed);
	return 0;
}
int luaapi_setDecelerationTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setDecelerationTime(speed);
	return 0;
}
int luaapi_setIdleCurrent(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setIdleCurrent(speed);
	return 0;
}
int luaapi_setIdleTime(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setIdleTime(speed);
	return 0;
}
int luaapi_setMicrosteps(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setMicrosteps(speed);
	return 0;
}
int luaapi_setRunCurrent(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setRunCurrent(speed);
	return 0;
}
int luaapi_setLowSpeed(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setLowSpeed(speed);
	return 0;
}
int luaapi_setHighSpeed(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int speed = luaL_checkinteger(L, 2);
	device->setHighSpeed(speed);
	return 0;
}
int luaapi_turnMotorOn(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->turnMotorOn();
	return 0;
}
int luaapi_turnMotorOff(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->turnMotorOff();
	return 0;
}
int luaapi_stop(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->stop();
	return 0;
}
int luaapi_moveTo(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	int position = luaL_checkinteger(L, 2);
	device->moveTo(position);
	lua_pushinteger(L, position);
	return 1;
}
int luaapi_moveUp(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->moveUp();
	return 0;
}
int luaapi_moveDown(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->moveDown();
	return 0;
}
int luaapi_checkDriverRead(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	bool status = device->checkDriverRead();
	lua_pushboolean(L, status);
	return 1;
}
int luaapi_checkDriverWrite(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	bool status = device->checkDriverWrite();
	lua_pushboolean(L, status);
	return 1;
}
int luaapi_writeDriverParameters(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->writeDriverParameters();
	return 0;
}
int luaapi_readDriverParameters(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->readDriverParameters();
	return 0;
}
int luaapi_waitForMotorIdle(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->waitForMotorIdle();
	return 0;
}

int luaapi_trying(lua_State *L) {
	Device *device = *static_cast<Device **>(luaL_checkudata(L, 1, "DeviceMetaTable"));
	device->waitForMotorIdle([&]() {
		lua_pushvalue(L, 2);
		if (0 != lua_pcall(L, 0, 0, 0)) {
			std::cout << "Failed to call the callback!\n %s\n"
					  << lua_tostring(L, -1) << std::endl;
		}
	});
	return 0;
}

static const luaL_Reg device_lib[] = {
	{"getPulsePosition", luaapi_getPulsePosition},
	{"getHighSpeed", luaapi_getHighSpeed},
	{"getEncoderPosition", luaapi_getEncoderPosition},
	{"getMotorStatus", luaapi_getMotorStatus},
	{"getCurrentPulseSpeed", luaapi_getCurrentPulseSpeed},
	{"getAccelerationTime", luaapi_getAccelerationTime},
	{"getDecelerationTime", luaapi_getDecelerationTime},
	{"getIdleCurrent", luaapi_getIdleCurrent},
	{"getIdleTime", luaapi_getIdleTime},
	{"getMicrosteps", luaapi_getMicrosteps},
	{"getRunCurrent", luaapi_getRunCurrent},
	{"getLowSpeed", luaapi_getLowSpeed},
	{"setEncoderPosition", luaapi_setEncoderPosition},
	{"setIncrementalMovement", luaapi_setIncrementalMovement},
	{"setAbsoluteMovement", luaapi_setAbsoluteMovement},
	{"setPulsePosition", luaapi_setPulsePosition},
	{"setAccelerationTime", luaapi_setAccelerationTime},
	{"setDecelerationTime", luaapi_setDecelerationTime},
	{"setIdleCurrent", luaapi_setIdleCurrent},
	{"setIdleTime", luaapi_setIdleTime},
	{"setMicrosteps", luaapi_setMicrosteps},
	{"setRunCurrent", luaapi_setRunCurrent},
	{"setLowSpeed", luaapi_setLowSpeed},
	{"setHighSpeed", luaapi_setHighSpeed},
	{"turnMotorOn", luaapi_turnMotorOn},
	{"turnMotorOff", luaapi_turnMotorOff},
	{"stop", luaapi_stop},
	{"moveTo", luaapi_moveTo},
	{"moveUp", luaapi_moveUp},
	{"moveDown", luaapi_moveDown},
	{"checkDriverRead", luaapi_checkDriverRead},
	{"checkDriverWrite", luaapi_checkDriverWrite},
	{"writeDriverParameters", luaapi_writeDriverParameters},
	{"readDriverParameters", luaapi_readDriverParameters},
	{"waitForMotorIdle", luaapi_waitForMotorIdle},
	{"trying", luaapi_trying},
	{NULL, NULL}

};

void registerDevice(lua_State *L, Device *device) {
	luaL_newmetatable(L, "DeviceMetaTable");

	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");

	luaL_setfuncs(L, device_lib, 0);

	lua_pop(L, 1);

	Device **udata = static_cast<Device **>(lua_newuserdata(L, sizeof(Device *)));
	*udata = device;

	luaL_getmetatable(L, "DeviceMetaTable");

	lua_setmetatable(L, -2);

	lua_setglobal(L, "device");
}

void luaapi_runProgram(std::string program, Device *device) {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	registerDevice(L, device);

	if (luaL_loadstring(L, program.c_str()) == LUA_OK) {
		if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
			std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
			lua_pop(L, 1);
		}
	}

	lua_close(L);
}
