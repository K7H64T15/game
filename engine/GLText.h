//
// Created by istimaldar on 16.05.2017.
//

#ifndef GAME_GLTEXT_H
#define GAME_GLTEXT_H
#include <iostream>
#include <map>
#include <string>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
// GL includes
#include "Shader.h"

struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};

class GLText {
    GLuint vao, vbo, vboT;
    std::map<GLchar, Character> Characters;
    Shader *shader;
    float x;
    float y;
    std::string text;
    glm::vec3 color;
public:
    GLText(std::string, float x, float y, glm::vec3 color);
    void RenderText();
    void draw();
};


#endif //GAME_GLTEXT_H
