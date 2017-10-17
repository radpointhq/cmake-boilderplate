project(lib)

set(SRCS 
    src/lib.cpp
    )

add_library(${PROJECT_NAME} SHARED ${SRCS})
add_library(HELLO::lib ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PRIVATE ${PROJECT_SOURCE_DIR}/src
    )

#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#install(TARGETS ${PROJECT_NAME}
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#install(FILES include/lib/lib.h DESTINATION include/lib)

