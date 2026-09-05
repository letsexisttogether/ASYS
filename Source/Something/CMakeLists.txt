# ASYSCurrentLibName
set(ASYSCLN ASYS_Something)

add_library(${ASYSCLN} STATIC
    Something.cpp
)

add_library(ASYS::Something ALIAS ${ASYSCLN})

target_compile_features(${ASYSCLN} PUBLIC cxx_std_23)

file(CREATE_LINK
    ${PROJECT_SOURCE_DIR}/Source/Something
    ${ASYS_BUILD_INCLUDE_DIR}/ASYS/Something
    SYMBOLIC
)

target_include_directories(${ASYSCLN} PUBLIC 
    $<BUILD_INTERFACE:${ASYS_BUILD_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS ${ASYSCLN}
    EXPORT ASYSTargets

    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    FILES
        Something.hpp
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/ASYS/Something
)
