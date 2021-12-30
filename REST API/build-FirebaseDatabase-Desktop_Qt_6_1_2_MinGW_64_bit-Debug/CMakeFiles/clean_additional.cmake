# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FirebaseDatabase_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FirebaseDatabase_autogen.dir\\ParseCache.txt"
  "FirebaseDatabase_autogen"
  )
endif()
