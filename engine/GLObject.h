#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <string>
#include <common/shader.hpp>
#include <common/texture.hpp>

class GLObject;

#include "IGLObject.h"

//typedef void (*mouseClick)(GLObject*, int , int , int , double, double);
//typedef void (*mouseMove)(GLObject*, double, double);

class GLObject : public IGLObject
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
protected:
	int x, y, height, width;
	GLuint shaders;
	GLuint texture;
    mouseClick onMouseClick;
    mouseMove onMouseMove;
public:
	GLObject(int x = 0, int y = 0, int heigth = 0, int width = 0);
	virtual void draw();
	//void onMouseMove(double xpos, double ypos);
	bool isMouseOnObject(double xpos, double ypos);
    void setOnMouseClick(mouseClick onMouseClick);
    mouseClick getOnMouseClick() { return onMouseClick; }
    void setOnMouseMove(mouseMove onMouseMove);
    mouseMove getOmMouseMove() { return onMouseMove; }
	Coordinates * getCoordinates();
	virtual ~GLObject();
};