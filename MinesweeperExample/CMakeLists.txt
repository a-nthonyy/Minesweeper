cmake_minimum_required(VERSION 3.28)
project(MinesweeperExample)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics)

add_executable(MinesweeperExample main.cpp
        welcome.h
        welcome.cpp
        game.h
        game.cpp
        leaderboard.h
        leaderboard.cpp)

target_link_libraries(MinesweeperExample PRIVATE sfml-graphics)