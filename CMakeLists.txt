cmake_minimum_required(VERSION 3.10)
project(2DPhysicsEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)
add_executable(Engine Engine.cpp)
target_link_libraries(Engine raylib)