#pragma once
#include "GLButton.h"
#include <list>

class GLFrame
{
	GLuint vao, vbo, vboT;
	GLfloat* coordinates, *uvcoordinates;
	GLuint shaders;
	GLuint texture;
	std::list<GLObject*> children;
	void InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum);
public:
	GLFrame();
	void addChild(GLObject *child);
	void draw();
	std::list<Coordinates *> * getCoordinates();

    ~GLFrame();
};

