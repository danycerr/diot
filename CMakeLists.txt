project(biot LANGUAGES CXX)
cmake_minimum_required(VERSION 3.2)

find_package(deal.II 8 REQUIRED HINTS $ENV{DEAL_II_DIR} $ENV{mkDealiiPrefix})
DEAL_II_INITIALIZE_CACHED_VARIABLES()

include_directories(${CMAKE_SOURCE_DIR})
add_executable(biot main.cpp
                    biot.cpp)
DEAL_II_SETUP_TARGET(biot)
