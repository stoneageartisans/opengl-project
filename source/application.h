#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application
{
public:
    Application();
    virtual ~Application();
private:
    GLFWwindow* window;
    int shaderProgram;
    unsigned int vertexArrayObject;
    unsigned int vertexBufferObject;

    void exit();
    void initialize();
    void initializeShaders();
    void initializeVertexData();
    void processInput();
    void run();
    void validateShaders();
};

/*
 * Non-Member Methods
 */
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

#endif /* APPLICATION_H */
