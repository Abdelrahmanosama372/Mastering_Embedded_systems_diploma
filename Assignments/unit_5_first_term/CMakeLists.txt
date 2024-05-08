cmake_minimum_required(VERSION 3.15)

project("Student_Managment_System")

include_directories(include)
set(SRC src/main.c src/student.c src/FIFO.c src/systemManager.c src/fileManager.c)

add_executable(${PROJECT_NAME} ${SRC})

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(${PROJECT_NAME} PRIVATE "-O3")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE "-g")
endif()


