cmake_minimum_required(VERSION 3.20)
project(pet)
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(csv)
add_subdirectory(filelog)
add_subdirectory(utils)

target_link_libraries(${PROJECT_NAME} Csv Utils Filelog)


