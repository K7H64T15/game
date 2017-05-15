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
