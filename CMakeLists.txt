cmake_minimum_required(VERSION 3.10)
project(QtSQLiteTest)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Sql)

add_executable(QtSQLiteTest main.cpp)
target_link_libraries(QtSQLiteTest Qt6::Core Qt6::Sql)
