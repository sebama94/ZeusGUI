cmake_minimum_required(VERSION 3.25)
project(ZeusGUIFullExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FullExample full_example.cpp)

# Ensure the include/ folder is on the path
target_include_directories(FullExample
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Link against the framework and GL libraries
target_link_libraries(FullExample
    PRIVATE
        ZeusGUI
        ${GL_LIBRARY}
        ${GLX_LIBRARY}
)
