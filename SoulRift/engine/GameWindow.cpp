#include <iostream>
#include "GameWindow.h"

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
	GLWindow::frame->addChild(start);
	GLWindow::frame->addChild(resume);
	GLWindow::frame->addChild(settings);
	GLWindow::frame->addChild(exit);
	loadCoordinates();
}

GameWindow::~GameWindow()
{
}

void onStartmouseClick(GLObject *object, int button, int action, int mods, double, double)
{

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