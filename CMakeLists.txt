cmake_minimum_required(VERSION 3.16)
project(PasswordStrengthAnalyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(PasswordStrengthAnalyzer
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(PasswordStrengthAnalyzer PRIVATE Qt6Widgets)