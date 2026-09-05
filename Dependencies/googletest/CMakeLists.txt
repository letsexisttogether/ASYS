include(FetchContent)

set(PackageName googletest)

FetchContent_Declare(
    ${PackageName}
    GIT_REPOSITORY
        https://github.com/google/googletest.git
    GIT_TAG
        v1.17.0
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(${PackageName})
