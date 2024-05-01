# CMakeList.txt : CMake project for TickTackToeGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (TickTackToeGame "TickTackToeGame.cpp" "TickTackToeGame.h" "Game.h" )
target_sources (TickTackToeGame PRIVATE "Game.cpp")
# TODO: Add tests and install targets if needed.
