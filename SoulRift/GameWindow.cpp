#include "GameWindow.h"

void onStartmouseClick(GLObject* object, int button, int action, int mods, double, double);
void onResumemouseClick(GLObject* object, int button, int action, int mods, double, double);
void onSettingsmouseClick(GLObject* object, int button, int action, int mods, double, double);
void onExitmouseClick(GLObject* object, int button, int action, int mods, double, double);

GameWindow::GameWindow()
{
	GLObject *start = new GLButton(840, 800, 100, 300, "newGameS.bmp");
	GLObject *resume = new GLButton(840, 600, 100, 300, "continueS.bmp");
	GLObject *settings = new GLButton(840, 400, 100, 300, "settingsS.bmp");
	GLObject *exit = new GLButton(840, 200, 100, 300, "exitS.bmp");
	GLWindow::frame->addChild(start);
	GLWindow::frame->addChild(resume);
	GLWindow::frame->addChild(settings);
	GLWindow::frame->addChild(exit);
	loadCoordinates();
}

GameWindow::~GameWindow()
{
}

void onStartmouseClick(GLObject *object, int button, int action, int mods, double, double) {

}

void onResumemouseClick(GLObject *object, int button, int action, int mods, double, double) {

}

void onSettingsmouseClick(GLObject *object, int button, int action, int mods, double, double) {

}

void onExitmouseClick(GLObject *object, int button, int action, int mods, double, double) {

}
