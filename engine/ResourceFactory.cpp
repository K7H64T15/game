//
// Created by istimaldar on 15.05.2017.
//

#include "ResourceFactory.h"

ResourceFactory *ResourceFactory::instance = nullptr;

ResourceFactory::ResourceFactory() {

}

ResourceFactory *ResourceFactory::getInstance() {
    if (instance == nullptr)
    {
        instance = new ResourceFactory();
    }
    return instance;
}

GLuint ResourceFactory::getTexture(string name) {
    if (textures.find(name) == textures.end()) {
        textures[name] = loadBMP_custom(name.c_str());
    }
    return textures[name];
}

GLuint ResourceFactory::getShader(Shader name) {
    if (shader.find(name) == shader.end()) {
        shader[name] = LoadShaders(name.vertex.c_str(), name.fragment.c_str());
    }
    return shader[name];
}
