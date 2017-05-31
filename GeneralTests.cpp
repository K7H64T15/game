//
// Created by istimaldar on 31.05.2017.
//

#include "gtest/gtest.h"

#include <engine/GLButton.h>
#include <engine/ResourceFactory.h>
#include <engine/GameWindow.h>

TEST(ButtonTextures, StandartTexture) {
    GLObject *button = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameS.bmp"), button->getTexture());
    delete button;
}

TEST(ButtonTextures, ActiveTexture) {
    GLObject *button = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
    button->active();
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameA.bmp"), button->getTexture());
    delete button;
}

TEST(ButtonTextures, PressedTexture) {
    GLObject *button = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
    button->press();
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameP.bmp"), button->getTexture());
    delete button;
}

TEST(ButtonShader, Shader) {
    GLObject *button = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
    EXPECT_EQ(ResourceFactory::getInstance()->getShader(Shader("ButtonVertexShader.vertexshader",
                                                               "ButtonFragmentShader.fragmentshader")),
              button->getShaders());
}



int main(int argc, char *argv[]) {
    GameWindow *win = GameWindow::getInstance();
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}