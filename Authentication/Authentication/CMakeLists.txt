cmake_minimum_required(VERSION 3.14)

project(Authentication LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OPENSSL_ROOT_DIR "C:\\Qt\\Tools\\OpenSSL\\Win_x64")
include(FindOpenSSL)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

add_executable(Authentication
  main.cpp
  athhandler.h
  athhandler.cpp
)
target_link_libraries(Authentication Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Authentication Qt6::Network)
target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES})
