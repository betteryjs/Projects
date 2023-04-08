cmake_minimum_required(VERSION 3.0.0)
project(TestPoco)

#add_compile_options(-std=c++14)
#set(Poco_DIR /usr/local/lib/cmake/Poco)
##/usr/local/lib/cmake/Poco/PocoConfigVersion.cmake
##find_package(MySQL REQUIRED)
find_package(Poco  CONFIG REQUIRED Foundation)

message(STATUS "Poco_DIR = ${Poco_DIR}")
message(STATUS "Poco_INCLUDE_DIRS = ${Poco_INCLUDES}")
message(STATUS "Poco_LIBS = ${Poco_LIBRARIES}")

add_executable(TestPoco Logger.cpp)
target_link_libraries(TestPoco   ${Poco_LIBRARIES})