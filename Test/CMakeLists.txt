set(ASYSTEST ASYS_Test)

add_executable(${ASYSTEST}
    StringLiteral.cpp
    Traits.cpp
)

target_compile_features(${ASYSTEST} PRIVATE cxx_std_23)

target_link_libraries(${ASYSTEST}
    PRIVATE 
        ASYS::Something
        ASYS::String
        ASYS::Traits
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(${ASYSTEST})
