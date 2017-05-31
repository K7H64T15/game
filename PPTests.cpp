#include <iostream>
#include "gtest/gtest.h"

#include <engine/GLButton.h>
#include <engine/ResourceFactory.h>
#include <engine/GameWindow.h>

// IndependentMethod is a test case - here, we have 2 tests for this 1 test case

TEST(ButtonTextures, ContinueNormal) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "continueS.bmp840400") {
            button = (*iterator);
        }
    }
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("continueS.bmp"), ((GLButton*)button)->getTexture());
}


TEST(ButtonTextures, ContinueMove) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "continueS.bmp840400") {
            button = (*iterator);
        }
    }
    win->emulateMouseMove(841, 401);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("continueA.bmp"), ((GLButton*)button)->getTexture());
}

TEST(ButtonTextures, ContinuePress) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "continueS.bmp840400") {
            button = (*iterator);
        }
    }
    win->emulateMouseClick(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS, 0, 841, 401);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("continueP.bmp"), ((GLButton*)button)->getTexture());
}

TEST(ButtonTextures, SettingsNormal) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "settingsS.bmp840600") {
            button = (*iterator);
        }
    }
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("settingsS.bmp"), ((GLButton*)button)->getTexture());
}


TEST(ButtonTextures, SettingsMove) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "settingsS.bmp840600") {
            button = (*iterator);
        }
    }
    win->emulateMouseMove(841, 601);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("settingsA.bmp"), ((GLButton*)button)->getTexture());
}

TEST(ButtonTextures, SettingsPress) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "settingsS.bmp840600") {
            button = (*iterator);
        }
    }
    win->emulateMouseClick(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS, 0, 841, 601);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("settingsP.bmp"), ((GLButton*)button)->getTexture());
}
TEST(ButtonTextures, NewNormal) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "newGameS.bmp840200") {
            button = (*iterator);
        }
    }
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameS.bmp"), ((GLButton*)button)->getTexture());
}


TEST(ButtonTextures, NewMove) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "newGameS.bmp840200") {
            button = (*iterator);
        }
    }
    win->emulateMouseMove(841, 201);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameA.bmp"), ((GLButton*)button)->getTexture());
}

TEST(ButtonTextures, NewPress) {
    GameWindow *win = GameWindow::getInstance();
    IGLObject *button = nullptr;
    auto children = win->getChildren();
    for (auto iterator = children.begin(); iterator != children.end(); ++iterator) {
        std::cout << (*iterator)->getName() << std::endl;
        if ((*iterator)->getName() == "newGameS.bmp840200") {
            button = (*iterator);
        }
    }
    win->emulateMouseClick(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS, 0, 841, 201);
    EXPECT_EQ(ResourceFactory::getInstance()->getTexture("newGameP.bmp"), ((GLButton*)button)->getTexture());
}

int main(int argc, char *argv[]) {
    GameWindow *win = GameWindow::getInstance();
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

// }  // namespace - could surround Project1Test in a namespace