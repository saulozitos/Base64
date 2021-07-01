cmake_minimum_required(VERSION 3.5)

project(Base64 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Base64 src/main.cpp src/base64.cpp)
