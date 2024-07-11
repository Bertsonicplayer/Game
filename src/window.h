#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include <math.h>
#include "glad/include/glad/glad.h"
#include "glfw/include/GLFW/glfw3.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>




void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods); /*This function helps us use the functions inside it which will be used to create key will be pressed. */

void window()
{


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow *window;
    // Initialize the library which helps us for sure.
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1280, 720, "Test", NULL, NULL);
    if (!window)
    {
        printf("Failed to create OPENGL window");
        glfwTerminate(); // haha if window not open then close window.
        return -1;
    }
    glfwMakeContextCurrent(window);
           if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Glad failed to load");
        return -1;
    }
    int height, width;
    int channels;
    unsigned char *pixels = stbi_load("Game/game.png", &width, &height, &channels, 4);
    //setting a window icon.
    GLFWimage images[1];
    images[0].width = width;
    images[0].height = height;
    images[0].pixels = pixels;
    glfwSetWindowIcon(window, 1, images);
    // Make the window's context current
    glfwSetKeyCallback(window, key_callback);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Render here and make window color.      
    
        // Swap front and back buffers
        glfwSwapBuffers(window);
        
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) /*this helps us make a key call back*/
{
  static bool fullscreen = false;
  static bool windowe = false;
  static bool windowtwo = false;
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    int width;
    int height;
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {

        glfwSetWindowShouldClose(window, true);
    }
else if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
{
    if(fullscreen == false)    // if the screen is not in fullscreen mode, let's set it to fullscreen mode
    {
         printf("\nFullscreen On\n\nWindow mode Off\n");
         glfwSetWindowMonitor(window, monitor, NULL, NULL, mode->width, mode->height, NULL);
        fullscreen = true;
    }
    else if(fullscreen == true)    // if we are currently in fullscreen mode, set it back to windowed mode.
    {
    printf("\nWindow mode On\n\nFullscreen Off\n");
       glfwSetWindowMonitor(window, NULL, 600, 300, 640, 400, NULL); 
    
        fullscreen = false; 
    }
        else if(fullscreen == false)    // if we are currently in fullscreen mode, set it back to windowed mode.
    {
    printf("\nWindow mode 2\n\nFullscreen Off\n");
       glfwSetWindowMonitor(window, NULL, 600, 300, 640, 400, NULL); 
    
        windowe = true;
    }

}
}
