# CMakeLists.txt
cmake_minimum_required(VERSION 3.12)
project(ToDoListApp)

set(CMAKE_CXX_STANDARD 14)

# Add your source files here
set(SOURCE_FILES
    main.cpp
    task.cpp
    task_list.cpp
    user_interface.cpp
    file_manager.cpp
)

add_executable(ToDoListApp ${SOURCE_FILES})
