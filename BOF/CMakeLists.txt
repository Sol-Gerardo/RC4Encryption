cmake_minimum_required(VERSION 3.29)
project(maldev)

set(CMAKE_CXX_STANDARD 20)

add_library(luser OBJECT BOF/luser.c)

target_link_libraries(luser PRIVATE advapi32 kernel32)