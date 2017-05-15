//
// Created by istimaldar on 16.05.2017.
//

#ifndef GAME_GLPANEL_H
#define GAME_GLPANEL_H

#include "GLObject.h"
#include <list>

using namespace std;

class GLPanel : public GLObject {
    GLuint standardTexture;
    list<GLObject*> children;
public:
    GLPanel(std::string standardTexture, int x = 0, int y = 0, int heigth = 0, int width = 0);
    void loadTextures(std::string standardTexture);
    void addChild(GLObject *child);
    virtual void active();
    virtual void deactivate();
    virtual void press();
    std::list<GLObject*> getChildren();
    ~GLPanel();
};


#endif //GAME_GLPANEL_H
