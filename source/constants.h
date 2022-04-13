#ifndef CONSTANTS_H
#define CONSTANTS_H

#define FRAGMENT_SHADER     "shaders/fragment.shader"
#define LOG_SIZE            512
#define VERTEX_SHADER       "shaders/vertex.shader"
#define WINDOW_TITLE        "GLFW Base"


// Colors                         R          G          B          A
#define STONE_AGE_ARTISANS  0.152941f, 0.152941f, 0.160784f, 1.000000f


enum ShaderType
{
    FRAGMENT,
    VERTEX
};

#endif /* CONSTANTS_H */
