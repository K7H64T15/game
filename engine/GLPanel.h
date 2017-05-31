//
// Created by istimaldar on 16.05.2017.
//

#ifndef GAME_GLPANEL_H
#define GAME_GLPANEL_H

#include "GLObject.h"
#include <list>

using namespace std;

void onPanelMouseClick(GLObject *object, int button, int action, int mods, double xpos, double ypos);
void onPanelMouseMove(GLObject *object, double xpos, double ypos);

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
    void draw();
    std::list<GLObject*> getChildren();
    std::string getName();
    ~GLPanel();
};


#endif //GAME_GLPANEL_H
