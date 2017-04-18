#pragma once
#include "GLFrame.h"
#include <list>
#include <map>
#include <string>

struct MouseHandler {
    Coordinates *coordinates;
    mouseClick onMouseClick;
};

class GLWindow
{
	GLFWwindow* window;
protected:
	GLFrame* frame;
    std::map<const std::string, GLFrame*> frames;
public:
	GLWindow();
	void loop();
	//friend static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
    void loadCoordinates();  //TODO: cleanup before use
    static std::list<MouseHandler> *mouseHandlers; //TODO: move to protected block and declarate friend function
	void setFrame(const std::string frame);
	~GLWindow();
};

