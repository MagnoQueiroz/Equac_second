cmake_minimum_required(VERSION 3.28)

project(equac_segund VERSION 0.95 DESCRIPTION "script to generate quadratic equations" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES equa_second)

add_executable(equac_segund equa_second.c)
add_library(equa_second ${SOURCE_FILES})
#name project m= linked to library math
#nome do project para linkar ao executável que é o equac_segund. Pois caso seja colocado o arquivo ele linkara ao arquivo ao invés do projeto... e o "m" para linkar á biblioteca math.h
target_link_libraries(equac_segund m)
