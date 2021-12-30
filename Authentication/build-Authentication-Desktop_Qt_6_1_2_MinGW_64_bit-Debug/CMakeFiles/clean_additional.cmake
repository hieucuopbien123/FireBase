# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Authentication_autogen"
  "CMakeFiles\\Authentication_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Authentication_autogen.dir\\ParseCache.txt"
  )
endif()
