//
// Created by istimaldar on 12.05.2017.
//

#include "GLField.h"
#include "ResourceFactory.h"

GLField::GLField(std::string standardTexture, int x, int y, int heigth, int width) : GLObject(x, y, heigth, width) {
    loadTextures(standardTexture);
    texture = this->standardTexture;
}

void GLField::loadTextures(std::string standardTexture) {
    shaders = ResourceFactory::getInstance()->getShader(Shader("ButtonVertexShader.vertexshader",
                                                               "ButtonFragmentShader.fragmentshader"));
    this->standardTexture = ResourceFactory::getInstance()->getTexture(standardTexture);
    GLuint TextureID = (GLuint) glGetUniformLocation(shaders, "myTextureSampler");
}

void GLField::active() {

}

void GLField::deactivate() {

}

void GLField::press() {

}

GLField::~GLField() {
    glDeleteProgram(shaders);
    glDeleteTextures(1, &texture);
}


