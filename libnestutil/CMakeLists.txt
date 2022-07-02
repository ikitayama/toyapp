set ( nestutil_sources dummy.cpp numerics.h)

add_library( nestutil ${nestutil_sources} )

set_target_properties( nestutil
    PROPERTIES
    VERSION 3
    SOVERSION 3
    )

target_include_directories( nestutil PRIVATE
    ${PROJECT_BINARY_DIR}/libnestutil
    ${Boost_INCLUDE_DIRS}
    )

