#include <iostream>
#include "GameWindow.h"
#include "Constants.h"
#include "GLField.h"

GameWindow *GameWindow::instance = nullptr;

void onStartmouseClick(GLObject* object, int button, int action, int mods, double, double);
void onResumemouseClick(GLObject* object, int button, int action, int mods, double, double);
void onSettingsmouseClick(GLObject* object, int button, int action, int mods, double, double);
void onExitMouseClick(GLObject *object, int button, int action, int mods, double, double);

void onStartMouseMove(GLObject* object, double xpos, double ypos);
void onResumeMouseMove(GLObject* object, double xpos, double ypos);
void onSettingsMouseMove(GLObject* object, double xpos, double ypos);
void onExitMouseMove(GLObject* object, double xpos, double ypos);

GameWindow::GameWindow()
{
	GLObject *start = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
	GLObject *resume = new GLButton("continueS.bmp", "continueA.bmp", 840, 400, 100, 300);
	GLObject *settings = new GLButton("settingsS.bmp", "settingsA.bmp", 840, 600, 100, 300);
	GLObject *exit = new GLButton("exitS.bmp", "exitA.bmp", 840, 800, 100, 300);
	exit->setOnMouseClick(&onExitMouseClick);
	start->setOnMouseClick(&onStartmouseClick);
	GLWindow::frame->addChild(start);
	GLWindow::frame->addChild(resume);
	GLWindow::frame->addChild(settings);
	GLWindow::frame->addChild(exit);
	loadCoordinates();
}

GameWindow::~GameWindow()
{
}

GameWindow *GameWindow::getInstance() {
	if (instance == nullptr)
	{
		instance = new GameWindow();
	}
	return instance;
}

void onStartmouseClick(GLObject *object, int button, int action, int mods, double, double)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        object->press();
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        object->deactivate();
    }
	GameWindow::getInstance()->setFrame(Constants::GAME_FRAME);
//    Map *baka = new Map();
//    auto fields = baka->fields;
//    for (auto i = 0; i < 30; i++)
//    {
//        for (auto j = 0; j < 60; j++)
//        {
//            int height = 1280 / 30;
//            int width = 1920 / 60;
//            if (!fields[i][j].getEnabled())
//            {
//                GLObject *texture = new GLField("wall.bmp", j * width, i * height, height, width);
//            }
//            else
//            {
//                GLObject *texture = new GLField("tunel.bmp", j * width, i * height, height, width);
//            }
//        }
//    }
}

void onResumemouseClick(GLObject *object, int button, int action, int mods, double, double)
{

}

void onSettingsmouseClick(GLObject *object, int button, int action, int mods, double, double)
{

}

void onExitMouseClick(GLObject *object, int button, int action, int mods, double, double)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        object->press();
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        object->deactivate();
        GLWindow::closeWindow();
    }
}

void onStartMouseMove(GLObject* object, double xpos, double ypos)
{

}

void onResumeMouseMove(GLObject* object, double xpos, double ypos)
{

}

void onSettingsMouseMove(GLObject* object, double xpos, double ypos)
{

}

void onExitMouseMove(GLObject* object, double xpos, double ypos)
{

}