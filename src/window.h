#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include <math.h>
#include "glad/include/glad/glad.h"
#include "glfw/include/GLFW/glfw3.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define HEIGHT
void window_size_callback(GLFWwindow *window, int width, int height) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    printf("Window resized: Width = %d, Height = %d\n", width, height);
}

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height); /*create a framebuffer callback*/
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods); /*This function helps us use the functions inside it which will be used to create key will be pressed.*/

void window() // window function
{
    int *widthwin;
    int *heightwin;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window;
    // Initialize the library which helps us for sure.
    if (!glfwInit()) //void values doesn't accept return values --Bert
        return;
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1280, 720, "Test", NULL, NULL);
    if (!window)
    {
        printf("Failed to create OPENGL window");
        glfwTerminate(); // haha if window not open then close window.
        return;
    }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        
        printf("WIDTH %d, HEIGHT: %d", widthwin, heightwin);


           if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Glad failed to load");
        return;
    }




    int height, width; //icon stuff
    int channels;
    unsigned char *pixels = stbi_load("../../Game/game.png", &width, &height, &channels, 4);
    //setting a window icon.
    GLFWimage images[1];
    images[0].width = width;
    images[0].height = height;
    images[0].pixels = pixels;

    glfwSetWindowIcon(window, 1, images);

    // Make the window's context current

    glfwSetKeyCallback(window, key_callback);


//creating a vertex shader here
unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
glCompileShader(vertexShader);
int success;
char infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
if(!success)
{
glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
printf("Gl shader not successful %s", infoLog);

}

//making triangle
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

unsigned int VBO;

glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


glfwSetWindowSizeCallback(window, window_size_callback);

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

    return;
}



void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) /*this helps us make a key call back*/
{
    static int fullscreen;
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    
    int width;
    int height;
    #define null 0 // NULL being int instead of pointer
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {

        glfwSetWindowShouldClose(window, true);
    }
    else if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
            {
            
                if(fullscreen == 0)    //Ok what we want to do here is set 0 as window 2// Fullscreen would be 1 window 1 
                    {
                        printf("\nFullscreen On\n\nWindow mode Off\n");
                        glfwSetWindowMonitor(window, monitor, null, null, mode->width, mode->height, null);
                        fullscreen = 1;
                    }

                else if(fullscreen == 1)    // if we are currently in fullscreen mode, set it back to windowed mode.
                        {
                            width = 640;
                            height = 400;
                        printf("\nWindow mode On\n\nFullscreen Off\n");
                        glfwSetWindowMonitor(window, NULL, 600, 300, width, height, null); 
                        
                    
                        
                        fullscreen = 2; //this is window 1 as set as 2
                        
                        
    }
                else if(fullscreen == 2) 
                      {
                       width = 1280;
                       height = 720;
                      printf("\nWindow mode On the second\n\nFullscreen Off\n");
                      glfwSetWindowMonitor(window, NULL, 300, 200, width, height, null);
                      fullscreen = 0; //we did fullscreen 0 to loop this whole thing.
                      }
                }
    return;
}

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
            return;
  }  
