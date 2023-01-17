cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.2.1
)
FetchContent_MakeAvailable(Catch2)

add_executable(ransom_note ransom_note.cpp)
target_link_libraries(ransom_note PRIVATE Catch2::Catch2WithMain)
