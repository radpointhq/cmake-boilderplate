project(exe)

set(SRCS 
    src/main.cpp)

if (APPLE)
    set(ICON Resources/exe.icns)
    set_source_files_properties(${ICON} PROPERTIES 
        MACOSX_PACKAGE_LOCATION Resources)
elseif (APPLE)
    set(ICON
        "${PROJECT_SOURCE_DIR}/resources/exe.ico")
endif (APPLE)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE 
    ${SRCS}
    ${ICON}
    )

target_link_libraries(exe
    HELLO::lib
    )

#install part
INSTALL (TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
    COMPONENT applications)

if (APPLE)
    set_target_properties (${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_STRING "The info string"
        #MACOSX_BUNDLE_GUI_IDENTIFIER "com.hello.exe"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_LONG_VERSION_STRING "${PROJECT_NAME}-${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
        MACOSX_BUNDLE_BUNDLE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}"
        MACOSX_BUNDLE_COPYRIGHT "Copyright © 2017 Radpoint Sp. z o.o. All rights reserved."
        MACOSX_BUNDLE_ICON_FILE "exe"
        )


    INSTALL(CODE "
    set(BU_CHMOD_BUNDLE_ITEMS ON)
    include(BundleUtilities)
    fixup_bundle(\"\${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}.app\" \"\" \"${CMAKE_BINARY_DIR}/lib\")
    " COMPONENT applications)
    set (CPACK_BUNDLE_APPLE_CERT_APP "Marek Kwasecki Radpoint Dev Key")
endif (APPLE)
