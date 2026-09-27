add_subdirectory(String)
add_subdirectory(Something)
add_subdirectory(Traits)

set(ASYSMN ASYS_APP)

add_executable(${ASYSMN}
    Main.cpp)

target_compile_features(${ASYSMN} PRIVATE cxx_std_23)

target_link_libraries(${ASYSMN}
    PRIVATE 
        ASYS::String
        ASYS::Something
        ASYS::Traits
)
