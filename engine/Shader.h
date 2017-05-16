//
// Created by istimaldar on 16.05.2017.
//

#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>


class Shader
{
public:
    GLuint Program;
    // Constructor generates the shader on the fly
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // Uses the current shader
    void Use();
};


#endif //GAME_SHADER_H
