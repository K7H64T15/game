#pragma once
#include "GLFrame.h"
#include <list>

class GLWindow
{
	GLFWwindow* window;
protected:
	GLFrame* frame;
	static std::list<Coordinates *> *click_positions; //TODO: cleanup before use
public:
	GLWindow();
	void loop();
	//friend static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
    void loadCoordinates();
	~GLWindow();
};

