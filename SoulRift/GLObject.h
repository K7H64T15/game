#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glfw3.h>
#include <string>
#include <common/shader.hpp>
#include <common/texture.hpp>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGTH 1080

struct Coordinates {
	int leftX;
	int rightX;
	int bottomY;
	int topY;
	Coordinates(int leftX, int rightX, int bottomY, int topY) : leftX(leftX), rightX(rightX), bottomY(bottomY),
																topY(topY) {};
};

class GLObject;

typedef void (*mouseClick)(GLObject*, int , int , int , double, double);

class GLObject
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
protected:
	int x, y, height, width;
	GLuint shaders;
	GLuint texture;
    mouseClick onMouseClick;
public:
	GLObject(int x = 0, int y = 0, int heigth = 0, int width = 0);
	void draw();
	//void onMouseMove(double xpos, double ypos);
	bool isMouseOnObject(double xpos, double ypos);
	virtual void active() = 0;
	virtual void disactive() = 0;
    void setOnMouseClick(mouseClick onMouseClick);
    mouseClick getOnMouseClick() { return onMouseClick; }
	Coordinates * getCoordinates();
	virtual ~GLObject();
};