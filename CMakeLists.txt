cmake_minimum_required(VERSION 3.25)
project(market_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(market_manager main.cpp Account.h Stock.h Item.h MainFunctions.h)
