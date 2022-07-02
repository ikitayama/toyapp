set ( sli_sources dummy.cpp sliexceptions.h  )


add_library( sli_lib ${sli_sources} )

set_target_properties( sli_lib
    PROPERTIES
    VERSION 3 
    SOVERSION 3
    )

target_link_libraries( sli_lib nestutil )

target_include_directories( sli_lib PRIVATE
    ${PROJECT_SOURCE_DIR}/thirdparty
    ${PROJECT_SOURCE_DIR}/libnestutil
    ${PROJECT_BINARY_DIR}/libnestutil
    )
