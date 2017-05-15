//
// Created by istimaldar on 15.05.2017.
//

#ifndef GAME_TEXTUREFACTORY_H
#define GAME_TEXTUREFACTORY_H

#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <string>
#include <common/shader.hpp>
#include <common/texture.hpp>

using namespace std;

struct Shaders {
    string vertex;
    string fragment;
};

class ResourseFactory {
    map<string, GLuint> textures;
    map<string, GLuint> shaders;
    static ResourseFactory *instance;
    ResourseFactory();
public:
    static ResourseFactory *getInstance();
    GLuint getTexture(string name);
    GLuint getShader(string name);
};


#endif //GAME_TEXTUREFACTORY_H
