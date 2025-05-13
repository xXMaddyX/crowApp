cmake_minimum_required(VERSION 3.10.0)
project(crowApp VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
    Crow-1.2.1.2/include
    asio-1.34.2/include
)

add_executable(crowApp main.cpp)

target_link_libraries(crowApp PRIVATE ws2_32 mswsock)