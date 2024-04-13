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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(ShowTime_0_0_2
        src/main.cpp
        src/core/Core.cpp
        src/core/Core.hpp
        src/graphic/Window.cpp
        src/graphic/Window.hpp
        src/graphic/Scenes/IScene.hpp
        src/graphic/Scenes/AScene.cpp
        src/graphic/Scenes/AScene.hpp
        src/graphic/Components/IComponent.hpp
        src/graphic/Components/AComponent.cpp
        src/graphic/Components/AComponent.hpp
        src/graphic/Components/SpriteComponent/SpriteComponent.cpp
        src/graphic/Components/SpriteComponent/SpriteComponent.hpp
        src/graphic/Scenes/LoadScene/LoadScene.cpp
        src/graphic/Scenes/LoadScene/LoadScene.hpp
        src/graphic/Components/VueMeterComponent/VueMeterComponent.cpp
        src/graphic/Components/VueMeterComponent/VueMeterComponent.hpp
        src/graphic/Components/TimerComponent/TimerComponent.cpp
        src/graphic/Components/TimerComponent/TimerComponent.hpp
        src/graphic/Scenes/MainScene/MainScene.cpp
        src/graphic/Scenes/MainScene/MainScene.hpp
        src/audio/AudioEngine/AudioEngine.cpp
        src/audio/AudioEngine/AudioEngine.hpp
        src/audio/AudioEngine/Inputs/Inputs.cpp
        src/audio/AudioEngine/Inputs/Inputs.hpp
        src/audio/AudioEngine/Outputs/Outputs.cpp
        src/audio/AudioEngine/Outputs/Outputs.hpp
        src/audio/AudioEngine/BuffersPool.cpp
        src/audio/AudioEngine/BuffersPool.hpp
        src/audio/AudioEngine/Buffer.cpp
        src/audio/AudioEngine/Buffer.hpp)

target_link_libraries(ShowTime_0_0_2 sfml-graphics sfml-window sfml-system)
target_link_libraries(ShowTime_0_0_2 )
target_include_directories(ShowTime_0_0_2 PRIVATE ${PULSEAUDIO_SIMPLE_INCLUDE_DIRS})
target_link_libraries(ShowTime_0_0_2 ${PULSEAUDIO_SIMPLE_LIBRARIES})
