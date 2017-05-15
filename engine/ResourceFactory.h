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

struct Shader {
    string vertex;
    string fragment;
    bool operator ==(const Shader &right) const
    {
        return vertex == right.vertex && fragment == right.fragment;
    }
    bool operator !=(const Shader &right) const
    {
        return vertex != right.vertex || fragment != right.fragment;
    }
    bool operator <(const Shader &right) const
    {
        return vertex != right.vertex ? vertex < right.vertex : fragment < right.fragment;
    }
    bool operator >(const Shader &right) const
    {
        return vertex != right.vertex ? vertex > right.vertex : fragment > right.fragment;
    }
    Shader(string vertex, string fragment) : vertex(vertex), fragment(fragment) {}
};

class ResourceFactory {
    map<string, GLuint> textures;
    map<Shader, GLuint> shader;
    static ResourceFactory *instance;
    ResourceFactory();
public:
    static ResourceFactory *getInstance();
    GLuint getTexture(string name);
    GLuint getShader(Shader name);
};


#endif //GAME_TEXTUREFACTORY_H
