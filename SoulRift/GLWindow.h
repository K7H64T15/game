#pragma once
#include "GLFrame.h"
#include <list>
#include <map>
#include <string>

//static void onMouseMove(GLFWwindow* window, double xpos, double ypos);

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
    void loadCoordinates();
    static std::list<Coordinates *> *click_positions; //TODO: cleanup before use
	void setFrame(const std::string frame);
	~GLWindow();
};

