cmake_minimum_required(VERSION 3.21)
project( toyapp CXX )
set (toyapp_VERSION_MAJOR 1)
set (toyapp_VERSION_MINOR 0)

set ( toyapp_sources test-nest.cpp )
# tell CMake to generate config.h
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
add_executable( toyapp test-nest.cpp )
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set_target_properties( toyapp 
    PROPERTIES
    LINK_FLAGS "-Wl,--no-as-needed"
    )

add_subdirectory( sli )
add_subdirectory( nestkernel )
add_subdirectory( libnestutil )
add_subdirectory( thirdparty )

include_directories( sli nestkernel libnestutil thirdparty ) 
link_directories(sli nestkernel libnestutil thirdparty)
set( ALL_LIBS
  "-lnestkernel" 
  "-lnest")

set( ALL_INCLUDES sli nestkernel libnestutil thirdparty )
#target_link_libraries(toyapp nestutil nestkernel )
target_link_libraries(toyapp nestkernel )

target_include_directories( toyapp PRIVATE
    ${PROJECT_SOURCE_DIR}/thirdparty
    ${PROJECT_BINARY_DIR}/nest
    ${PROJECT_BINARY_DIR}/libnestutil
    ${PROJECT_SOURCE_DIR}/libnestutil
    ${PROJECT_SOURCE_DIR}/sli
    ${PROJECT_SOURCE_DIR}/nestkernel
    ${SLI_MODULE_INCLUDE_DIRS}
    )


