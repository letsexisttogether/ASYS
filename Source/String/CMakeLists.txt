set(ASYSCLN ASYS_String)

add_library(${ASYSCLN} INTERFACE)

add_library(ASYS::String ALIAS ${ASYSCLN})

set_target_properties(${ASYSCLN} PROPERTIES
    EXPORT_NAME String
)

target_compile_features(${ASYSCLN}
    INTERFACE cxx_std_23
)

file(CREATE_LINK
    ${PROJECT_SOURCE_DIR}/Source/String
    ${ASYS_BUILD_INCLUDE_DIR}/ASYS/String
    SYMBOLIC
)

target_include_directories(${ASYSCLN} INTERFACE
    $<BUILD_INTERFACE:${ASYS_BUILD_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ${ASYSCLN}
    EXPORT ASYSTargets
)

install(
    FILES 
        StringLiteral.hpp
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/ASYS/String
)
