#pragma once
#include "GLWindow.h"
class GameWindow : public GLWindow
{
	static GameWindow *instance;
    GameWindow();
public:
	static GameWindow *getInstance();
	~GameWindow();
};

