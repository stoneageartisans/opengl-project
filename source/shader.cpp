#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include "logger.h"
#include "shader.h"

Shader::Shader(ShaderType type, const char* filename, bool verifyIt)
{
    data = 0;
    this->type = type;
    
    loadSource(filename, true); // For debugging
    //loadSource(filename);
    
    switch(type)
    {
        case FRAGMENT:
            data = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        case VERTEX:
            data = glCreateShader(GL_VERTEX_SHADER);            
            break;
    }
    
    const char* shaderSource = source.c_str();
    glShaderSource(data, 1, &shaderSource, NULL); 
    
    glCompileShader(data);
    
    if(verifyIt)
    {
        verifyCompilation();
    }
}

Shader::~ Shader()
{
    glDeleteShader(data);
}

void Shader::loadSource(const char* filename, bool logIt)
{
    fstream file;
    
    file.open(filename, ios::in);

    if(file.is_open())
    {
        while(file.good())
        {
            string line;
            getline(file, line);
            if(line.size() > 0)
            {
                source += line;
                source += "\n";
            }
        }

        file.close();
    }
    else
    {
        string errorMessage = "ERROR: File '";
        errorMessage += filename;
        errorMessage += "' could not be read.";
        
        Logger::log(errorMessage);
    }
    
    if(logIt)
    {
        Logger::log(source);
    }
}

void Shader::verifyCompilation()
{
    int successful;
    char* logInfo;
    
    glGetShaderiv(data, GL_COMPILE_STATUS, &successful);
    
    if(!successful)
    {
        glGetShaderInfoLog(data, LOG_SIZE, NULL, logInfo);
        
        switch(type)
        {
            case FRAGMENT:
                Logger::log("ERROR: Fragment shader compilation failed...");
                break;
            case VERTEX:
                Logger::log("ERROR: Vertex shader compilation failed...");           
                break;
        }
        
        Logger::log(logInfo);
    }
}