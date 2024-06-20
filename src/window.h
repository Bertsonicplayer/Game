#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
// #include <windows.h>
#include <math.h>
#include "GLFW/glfw3.h"
#include "GL/gl.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods); /*This function helps us use the functions inside it which will be used to create key will be pressed. */

void window()
{

    GLFWwindow *window;
    // Initialize the library which helps us for sure.
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1280, 720, "Test", NULL, NULL);
    if (!window)
    {
        glfwTerminate(); // haha if window not open then close window.
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // Render here and make window color.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);    
    
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
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    int width;
    int height;
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {

        glfwSetWindowShouldClose(window, true);
    }
   else if(key == GLFW_KEY_F11 && action == GLFW_PRESS)
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

}
}
