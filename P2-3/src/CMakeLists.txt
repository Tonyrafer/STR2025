# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

idf_build_get_property(MODE MODE)
if(MODE STREQUAL "parte3_1")
 FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/parte3_1/*.*)
elseif(MODE STREQUAL "parte3_2a")
 FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/parte3_2a/*.*)
 elseif(MODE STREQUAL "parte3_3a")
 FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/parte3_3a/*.*)
 elseif(MODE STREQUAL "parte3_3b")
 FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/parte3_3b/*.*)
else()
 message(FATAL_ERROR "Selecciona el modo parte2_1 o parte2_2 en Platformio.")
endif()
idf_component_register(SRCS ${app_sources})