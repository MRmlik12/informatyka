project(quiz)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
find_package(nlohmann_json CONFIG REQUIRED)

configure_file(quiz.json quiz.json COPYONLY)

add_executable(quiz main.cpp reader.cpp quiz_manager.cpp quiz_manager.h reader.h quiz_item.h)
target_link_libraries(quiz PRIVATE nlohmann_json::nlohmann_json)
