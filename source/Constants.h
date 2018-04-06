#ifndef CONSTANTS_H
#define CONSTANTS_H

// Integers
#define LOG_SIZE    512

// Strings
#define FRAGMENT_SHADER    "shaders/fragment.shader"
#define VERTEX_SHADER      "shaders/vertex.shader"
#define WINDOW_TITLE       "GLFW Base"

// Colors                         R          G          B          A
#define STONE_AGE_ARTISANS    0.152941f, 0.152941f, 0.160784f, 1.000000f

// Shader Types
enum ShaderType
{
    FRAGMENT,
    VERTEX
};


#endif /* CONSTANTS_H */
