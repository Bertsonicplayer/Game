cmake_minimum_required(VERSION 3.13)
project(Gametest)
find_package(OpenGL REQUIRED)
add_subdirectory(src/glad)
add_subdirectory(src/glfw)

set(SOURCE_FILES src/window.h src/main.c src/triangle.c )


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
    glfw
    glad
    ${OPENGL_LIBRARIES}
)
#target_link_options(Gametest PRIVATE -mwindows):window
