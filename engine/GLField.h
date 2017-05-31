//
// Created by istimaldar on 12.05.2017.
//

#ifndef SOULRIFT_GLFIELD_H
#define SOULRIFT_GLFIELD_H

#include "GLObject.h"

class GLField : public GLObject {
    GLuint standardTexture;
public:
    GLField(std::string standardTexture, int x = 0, int y = 0, int heigth = 0, int width = 0);
    void loadTextures(std::string standardTexture);
    virtual void active();
    virtual void deactivate();
    virtual void press();
    std::string getName();
    ~GLField();
};


#endif //SOULRIFT_GLFIELD_H
