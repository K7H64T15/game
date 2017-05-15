#include <iostream>
#include <code/Map.h>
#include "GameWindow.h"
#include "Constants.h"
#include "GLField.h"

GameWindow *GameWindow::instance = nullptr;

void onStartMouseClick(GLObject *object, int button, int action, int mods, double, double);
void onResumeMouseClick(GLObject *object, int button, int action, int mods, double, double);
void onSettingsMouseClick(GLObject *object, int button, int action, int mods, double, double);
void onExitMouseClick(GLObject *object, int button, int action, int mods, double, double);

void onStartMouseMove(GLObject* object, double xpos, double ypos);
void onResumeMouseMove(GLObject* object, double xpos, double ypos);
void onSettingsMouseMove(GLObject* object, double xpos, double ypos);
void onExitMouseMove(GLObject* object, double xpos, double ypos);

GameWindow::GameWindow()
{
	GLObject *start = new GLButton("newGameS.bmp", "newGameA.bmp", "newGameP.bmp", 840, 200, 100, 300);
	GLObject *resume = new GLButton("continueS.bmp", "continueA.bmp", "continueP.bmp", 840, 400, 100, 300);
	GLObject *settings = new GLButton("settingsS.bmp", "settingsA.bmp", "settingsP.bmp", 840, 600, 100, 300);
	GLObject *exit = new GLButton("exitS.bmp", "exitA.bmp", "exitP.bmp", 840, 800, 100, 300);
	exit->setOnMouseClick(&onExitMouseClick);
	start->setOnMouseClick(&onStartMouseClick);
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

void onStartMouseClick(GLObject *object, int button, int action, int mods, double, double)
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
    Map *baka = new Map();
    auto fields = baka->fields;
    for (auto i = 0; i < 30; i++)
    {
        for (auto j = 0; j < 60; j++)
        {
            int height = .9 * 1280 / 30;
            int width =  .8 * 1920 / 60;
            GLObject *texture;
            if (!fields[i][j].getEnabled())
            {
                texture = new GLField("wall.bmp", j * width, i * height, height, width);
            }
            else
            {
                texture = new GLField("tunel.bmp", j * width, i * height, height, width);
            }
            (*GameWindow::getInstance()->frames)[Constants::GAME_FRAME]->addChild(texture);
        }
    }
}

void onResumeMouseClick(GLObject *object, int button, int action, int mods, double, double)
{

}

void onSettingsMouseClick(GLObject *object, int button, int action, int mods, double, double)
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