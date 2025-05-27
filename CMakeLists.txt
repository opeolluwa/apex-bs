cmake_minimum_required(VERSION 3.31)

project(apex_banking_system)

add_executable(${PROJECT_NAME} main.c include/uuidv4.c lib/utils.c lib/transaction.c lib/bank.c lib/accounts.c)

include_directories(include lib)

set(CMAKE_C_STANDARD 11)

find_package(raylib 5.5 REQUIRED)


target_link_libraries(${PROJECT_NAME} raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()