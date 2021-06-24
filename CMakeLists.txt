cmake_minimum_required(VERSION 3.12)

include(CMakePackageConfigHelpers)

SET(curr_version 1.0)

project(rkv2MT VERSION ${curr_version} 
				DESCRIPTION "A wrapper for libRKV2"
				LANGUAGES CXX)
				
add_subdirectory(extern/libRKV2)
include_directories(${CMAKE_SOURCE_DIR}/extern/libRKV2/include)
add_subdirectory(src)