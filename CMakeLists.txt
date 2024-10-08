cmake_minimum_required(VERSION 3.10)  # Specify the minimum version of CMake
project(flocking_viz)  # Name your project

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Eigen3 REQUIRED)


# reynolds_flock library
add_library(flocking_technique src/flocking_utils/flocking_technique.cpp)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})

add_executable(flocking_viz src/main.cpp 
    src/ogl_utils/ogldev_util.cpp
    src/ogl_utils/ogldev_math_3d.cpp
    src/ogl_utils/technique.cpp
    src/multi_utils/camera.cpp 
    src/multi_utils/world_transform.cpp
    src/multi_utils/shaders.cpp
    src/multi_utils/mesh.cpp
    )
    
target_link_libraries(flocking_viz flocking_technique ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} glfw)