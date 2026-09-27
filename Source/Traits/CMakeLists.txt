set(ASYS_Traits ASYS_Traits)

add_library(${ASYS_Traits} INTERFACE)

add_library(ASYS::Traits ALIAS ${ASYS_Traits})

set_target_properties(${ASYS_Traits} PROPERTIES EXPORT_NAME Traits)

target_compile_features(${ASYS_Traits} INTERFACE cxx_std_23)

file(CREATE_LINK
    ${PROJECT_SOURCE_DIR}/Source/Traits
    ${ASYS_BUILD_INCLUDE_DIR}/ASYS/Traits
    SYMBOLIC
)
