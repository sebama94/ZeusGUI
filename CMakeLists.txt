# Root CMakeLists.txt (for ZeusGUI Framework)
cmake_minimum_required(VERSION 3.25)
project(ZeusGUI VERSION 0.1.0 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build ZeusGUI as a shared library" ON)
option(ENABLE_LTO "Enable link-time optimization" ON)

# Compiler settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Find required packages
find_package(Threads REQUIRED)

# X11 and OpenGL manually
find_path(X11_INCLUDE_DIR NAMES X11/Xlib.h)
find_library(X11_LIBRARY NAMES X11)
find_path(GL_INCLUDE_DIR NAMES GL/gl.h)
find_library(GL_LIBRARY NAMES GL)
find_library(GLX_LIBRARY NAMES GLX)

if(NOT X11_INCLUDE_DIR OR NOT X11_LIBRARY)
    message(FATAL_ERROR "X11 development files not found. Please install libx11-dev.")
endif()
if(NOT GL_INCLUDE_DIR OR NOT GL_LIBRARY OR NOT GLX_LIBRARY)
    message(FATAL_ERROR "OpenGL development files not found. Please install libgl1-mesa-dev.")
endif()

add_library(ZeusGUI
    src/ZeusGUI.cpp
    src/platform/linux/X11Window.cpp
    src/core/BasicRenderer.cpp
    src/core/EventDispatcher.cpp
    src/widgets/Button.cpp
)

# Includes
set(ZEUSGUI_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(ZEUSGUI_PRIVATE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Include directories
target_include_directories(ZeusGUI
        PUBLIC ${ZEUSGUI_PUBLIC_INCLUDE_DIR}
        PRIVATE ${X11_INCLUDE_DIR} ${GL_INCLUDE_DIR} ${ZEUSGUI_PRIVATE_SRC_DIR}
)

# Link libraries
target_link_libraries(ZeusGUI
        PUBLIC Threads::Threads
        PRIVATE ${X11_LIBRARY} ${GL_LIBRARY} ${GLX_LIBRARY}
)

# Enable LTO
if(ENABLE_LTO)
    include(CheckIPOSupported)
    check_ipo_supported(RESULT LTO_OK)
    if(LTO_OK)
        set_property(TARGET ZeusGUI PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    endif()
endif()

# Build examples
add_subdirectory(examples)

# Optional install and packaging can go here