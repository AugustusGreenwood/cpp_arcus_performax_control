# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MechanicalLoader_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MechanicalLoader_autogen.dir/ParseCache.txt"
  "MechanicalLoader_autogen"
  "stage_control/CMakeFiles/stage_control_autogen.dir/AutogenUsed.txt"
  "stage_control/CMakeFiles/stage_control_autogen.dir/ParseCache.txt"
  "stage_control/stage_control_autogen"
  )
endif()
