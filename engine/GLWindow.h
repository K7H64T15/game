#pragma once
#include "GLFrame.h"
#include <list>
#include <map>
#include <string>

class GLWindow
{
	static bool shouldClose;
protected:
	GLFrame* frame;
    GLFWwindow* window;
public:
	GLWindow();
	void loop();
	//friend static void onMouseMove(GLFWwindow* window, double xpos, double ypos);
    void loadCoordinates();  //TODO: cleanup before use
    static std::map<const std::string, GLFrame*> *frames;
    static std::string current;
    static void closeWindow();
	void setFrame(const std::string frame);
	~GLWindow();
};

