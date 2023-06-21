cmake_minimum_required (VERSION 3.20)
project(follyTest)

set(CMAKE_CXX_STANDARD 11)




include_directories(${CMAKE_SOURCE_DIR}/include)

include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)

conan_basic_setup()

add_executable(ocrimg ocrimg.cpp)
add_executable(ocrlatex ocrlatex.cpp)





target_link_libraries(ocrimg ${CONAN_LIBS})
target_link_libraries(ocrlatex ${CONAN_LIBS})


