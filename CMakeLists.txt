cmake_minimum_required(VERSION 3.27)
project(equac_segund C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(SOURCE_FILES equa_second
)
add_executable(equac_segund equa_second.c)
add_library(equa_second ${SOURCE_FILES})
target_link_libraries(equa_second)
