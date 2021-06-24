file(GLOB CPP_SOURCES "*.cpp")

add_executable(rkv2MT ${CPP_SOURCES})
target_compile_features(rkv2MT PUBLIC cxx_std_17)
set_target_properties(rkv2MT PROPERTIES CXX_EXTENSIONS OFF
										  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
target_link_libraries(rkv2MT RKV2 -static)