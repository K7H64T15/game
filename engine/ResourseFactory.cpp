//
// Created by istimaldar on 15.05.2017.
//

#include "ResourseFactory.h"

ResourseFactory *ResourseFactory::instance = nullptr;

ResourseFactory::ResourseFactory() {

}

ResourseFactory *ResourseFactory::getInstance() {
    if (instance == nullptr)
    {
        instance = new ResourseFactory();
    }
    return instance;
}

GLuint ResourseFactory::getTexture(string name) {
    if (textures.find(name) == textures.end()) {
        textures[name] = loadBMP_custom(name.c_str());
    }
    return textures[name];
}

GLuint ResourseFactory::getShader(string name) {
    return 0;
}
