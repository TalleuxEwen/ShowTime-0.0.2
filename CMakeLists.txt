cmake_minimum_required(VERSION 3.25.1)
project(ShowTime_0_0_2)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
        SFML
        URL https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip
)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PULSEAUDIO_SIMPLE REQUIRED libpulse-simple)

add_executable(ShowTime_0_0_2
        src/main.cpp
        src/core/Core.cpp
        src/core/Core.hpp
        src/graphic/Window.cpp
        src/graphic/Window.hpp)

target_link_libraries(ShowTime_0_0_2 sfml-graphics sfml-window sfml-system)
target_link_libraries(ShowTime_0_0_2 )
target_include_directories(ShowTime_0_0_2 PRIVATE ${PULSEAUDIO_SIMPLE_INCLUDE_DIRS})
target_link_libraries(ShowTime_0_0_2 ${PULSEAUDIO_SIMPLE_LIBRARIES})
