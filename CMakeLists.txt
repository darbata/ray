cmake_minimum_required(VERSION 4.3)
project(ray)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(raylib
        src/Tuple.cpp
        src/Colour.cpp
        src/Float.cpp
        src/Canvas.cpp
        src/Matrix.cpp
        src/Ray.cpp
        src/Geometry.cpp
)
target_include_directories(raylib PUBLIC src)

add_executable(ray src/main.cpp
        src/Transform.cpp
        src/Transformation.h
        src/Transformation.h
        src/Ray.cpp
        src/Ray.h
        src/Geometry.h
        src/Geometry.cpp
)
target_link_libraries(ray PRIVATE raylib)

add_executable(tests tests/matrix_test.cpp
        tests/tuple_test.cpp
        tests/colour_test.cpp
        tests/ray_test.cpp)
target_link_libraries(tests PRIVATE raylib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
