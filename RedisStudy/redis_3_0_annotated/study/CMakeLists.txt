
project(Test)


add_executable(test test1.c ../src/sds.c ../src/zmalloc.c)
add_executable(scan scan.cpp)