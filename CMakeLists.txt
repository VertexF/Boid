cmake_minimum_required(VERSION 3.14.0)

project(Boid 
        VERSION 0.0.0
        LANGUAGES CXX
        DESCRIPTION "Boid game")
        
#Sets ups the module path to work with the a custom on so the defualt CMake modules work.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}../../../glew-2.1.0/")

set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}../../../SDL2-2.0.10/include")
set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}../../../SDL2-2.0.10/lib/x64/SDL2.lib")
set(SDL2MAIN_LIBRARY "${CMAKE_SOURCE_DIR}../../../SDL2-2.0.10/lib/x64/SDL2main.lib")

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)


include_directories(${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} )

add_subdirectory(src)
add_subdirectory(src/Graphics)

add_executable(Boid src/main.cpp)

target_link_libraries(Boid PRIVATE OpenGL::GL OpenGL::GLU SDL2::Core SDL2::Main GLEW::GLEW Boid_Lib Graphics_lib)
