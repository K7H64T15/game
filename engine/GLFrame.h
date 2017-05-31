#pragma once
#include "GLButton.h"
#include <list>
#include <map>

class GLFrame;

typedef void (*KeyPress)(GLFrame*, int key, int scancode, int action, int mods);

class GLFrame
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	GLuint shaders;
	GLuint texture;
	std::list<IGLObject*> children;
    KeyPress onKeyPress;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
public:
	GLFrame(std::string background="background.bmp");
	void addChild(IGLObject *child);
	void draw();
    void setOnKeyPress(KeyPress onKeyPress);
    KeyPress getOnKeyPress();
	std::list<Coordinates *> * getCoordinates();
    std::list<IGLObject*> getChildren();
	void clearChidren();
    ~GLFrame();
	std::list<mouseClick> *getOnMouseClickHandlers();
};

