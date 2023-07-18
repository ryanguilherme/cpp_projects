cmake_minimum_required(VERSION 3.25)
project(market_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(market_manager src/main.cpp lib/Account.h lib/Stock.h lib/Item.h lib/MainFunctions.h src/Account.cpp src/Item.cpp src/Stock.cpp src/MainFunctions.cpp)
