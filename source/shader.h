#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "constants.h"

using namespace std;

class Shader
{
public:
    int data;
    ShaderType type;
    string source;

    Shader(ShaderType type, const char* filename, bool verifyIt = false);
    virtual ~Shader();
private:
    void loadSource(const char* filename, bool logIt = false);
    void verifyCompilation();
};

#endif /* SHADER_H */
