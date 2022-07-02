set ( nestkernel_sources test.cpp exceptions.h event.cpp event.h target.h spike_data.h nest_types.h nest_time.h node.h node.cpp)

add_library( nestkernel ${nestkernel_sources} )
set_target_properties( nestkernel
    PROPERTIES
    VERSION 2
    SOVERSION 3
    )
target_link_libraries( nestkernel
    nestutil sli_lib
    )
target_include_directories( nestkernel PRIVATE
    ${PROJECT_SOURCE_DIR}/sli
    ${RPOJECT_SOURCE_DIR}/thirdparty
    ../thirdparty
    ${PROJECT_SOURCE_DIR}/nestkernel
    ${PROJECT_SOURCE_DIR}/libnestutil
    ${PROJECT_BINARY_DIR}/libnestutil
    )

install( TARGETS nestkernel
    LIBRARY DESTINATION /tmp
)
