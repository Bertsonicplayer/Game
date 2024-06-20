cmake_minimum_required(VERSION 3.13)

project(Gametest)

find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)


add_executable(Gametest src/window.h src/main.c src/triangle.c)



target_include_directories(Gametest PUBLIC 
${GLFW_INCLUDE_DIRS}
${GLEW_INCLUDE_DIRS}
)

target_link_libraries(Gametest
    glfw
    OpenGL::GL
)
#target_link_options(Gametest PRIVATE -mwindows)