//
// Created by istimaldar on 16.05.2017.
//

#include "GLPanel.h"

GLPanel::GLPanel(std::string standardTexture, int x, int y, int heigth, int width) {
    loadTextures(standardTexture);
    texture = this->standardTexture;
}

void GLPanel::loadTextures(std::string standardTexture) {

}

void GLPanel::active() {

}

void GLPanel::deactivate() {

}

void GLPanel::press() {

}

void GLPanel::addChild(GLObject *child) {

}

std::list<GLObject *> GLPanel::getChildren() {
    return list<GLObject *>();
}

GLPanel::~GLPanel() {

}

void GLPanel::draw() {
    GLObject::draw();
    for (std::list<GLObject*>::const_iterator iterator = children.begin(), end = children.end(); iterator != end; ++iterator)
        (*iterator)->draw();
}

std::string GLPanel::getName() {
    return GLObject::getName();
}

void onPanelMouseClick(GLObject *object, int button, int action, int mods, double xpos, double ypos)
{

}

void onPanelMouseMove(GLObject *object, double xpos, double ypos)
{

}