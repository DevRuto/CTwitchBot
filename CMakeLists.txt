cmake_minimum_required(VERSION 3.6)
project(CTwitchBot)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c values.h nr_socket.c nr_socket.h platform.h twitch.c twitch.h platform.c nr_func.c nr_func.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(CTwitchBot ${SOURCE_FILES})

if(WIN32)
    target_link_libraries(CTwitchBot wsock32 ws2_32)
endif()