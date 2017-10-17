cmake_minimum_required (VERSION 3.9 FATAL_ERROR)
project (HELLO LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14) # C++14...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")
set (PKG_GENERATOR ON)

add_subdirectory(lib)
add_subdirectory(exe)

if (APPLE)
    if (PKG_GENERATOR)
        set (CPACK_COMPONENTS_ALL applications)
        set (CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "ExeApp Application")
        set (CPACK_COMPONENT_APPLICATIONS_DESCRIPTION "Fun app ")
        set (CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")

        set(CPACK_GENERATOR productbuild)
    endif (PKG_GENERATOR)
    if (DMG_GENERATOR)
        set(CPACK_GENERATOR dragndrop)
    endif (DMG_GENERATOR)
endif (APPLE)

include (CPack)
