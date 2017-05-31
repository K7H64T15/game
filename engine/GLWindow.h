#pragma once
#include "GLFrame.h"
#include <list>
#include <map>
#include <string>

static void onMouseMove(GLFWwindow * window, double xpos, double ypos);
void onMouseClick(GLFWwindow* window, int button, int action, int mods);
void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);

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
    void emulateMouseMove(double xpos, double ypos);
    void emulateMouseClick(int button, int action, int mods, double xpos, double ypos);
    void addChild(GLObject *object);
    void clearChilds();
    std::list<IGLObject*> getChildren();
	~GLWindow();
};

