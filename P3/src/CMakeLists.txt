# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

idf_build_get_property(MODE MODE)
if(MODE STREQUAL "parte1_1")
 FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/parte1_1/*.*)
else()
 message(FATAL_ERROR "Selecciona el modo parte2_1 o parte2_2 en Platformio.")
endif()
idf_component_register(SRCS ${app_sources})