#include "application.h"
#include "constants.h"
#include "logger.h"
#include "shader.h"

Application::Application()
{
    Logger::log("GLFW Base started...");
    
    initialize();
}

Application::~ Application()
{
    exit();
    Logger::log("...GLFW Base ended");
}

void Application::exit()
{
    glfwTerminate();
}

void Application::initialize()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(1280, 800, WINDOW_TITLE, NULL, NULL);
    
    if(window == NULL)
    {
        Logger::log("ERROR: Failed to create GLFW window");
    }
    else
    {
        glfwMakeContextCurrent(window);
        
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            Logger::log("ERROR: Failed to initialize GLAD");
        }
        else
        {
            initializeShaders();
            initializeVertexData();
            glViewport(0, 0, 1280, 800);
            glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);            
            run();
        }
    }
}

void Application::initializeShaders()
{
    Logger::log("Initializing shaders...");
    
    Shader* vertexShader = new Shader(ShaderType::VERTEX, VERTEX_SHADER, true); // For debugging
    Shader* fragmentShader = new Shader(ShaderType::FRAGMENT, FRAGMENT_SHADER, true); // For debugging
    
    //Shader* vertexShader = new Shader(ShaderType::VERTEX, VERTEX_SHADER);
    //Shader* fragmentShader = new Shader(ShaderType::FRAGMENT, FRAGMENT_SHADER);
    
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader->data);
    glAttachShader(shaderProgram, fragmentShader->data);
    
    glLinkProgram(shaderProgram);
    
    validateShaders();
    
    delete fragmentShader;
    delete vertexShader;
    
    Logger::log("...shaders initialized.");
}

void Application::initializeVertexData()
{
    float vertices[] =
    {
        -0.5f, -0.5f, 0.0f, // bottom left
         0.5f, -0.5f, 0.0f, // bottom right
         0.0f,  0.5f, 0.0f  // top center
    }; 

    glGenVertexArrays(1, &vertexArrayObject);
    glGenBuffers(1, &vertexBufferObject);
    
    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(0);
}

void Application::processInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void Application::run()
{
    while(!glfwWindowShouldClose(window))
    {
        processInput();
        
        glClearColor(STONE_AGE_ARTISANS);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(vertexArrayObject);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}

void Application::validateShaders()
{
    int successful;
    char* logInfo;

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successful);
    
    if(!successful)
    {
        glGetProgramInfoLog(shaderProgram, LOG_SIZE, NULL, logInfo);
        
        Logger::log("ERROR: Linking of shader program failed...");
        Logger::log(logInfo);
    }
}

/*
 * Non-Member Methods
 */
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
