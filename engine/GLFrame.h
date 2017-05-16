#pragma once
#include "GLButton.h"
#include <list>

class GLFrame
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	GLuint shaders;
	GLuint texture;
	std::list<IGLObject*> children;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
public:
	GLFrame(std::string background="background.bmp");
	void addChild(IGLObject *child);
	void draw();
	std::list<Coordinates *> * getCoordinates();
    std::list<IGLObject*> getChildren();
    ~GLFrame();
	std::list<mouseClick> *getOnMouseClickHandlers();
};

