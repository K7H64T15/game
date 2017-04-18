#include <iostream>
#include "GLObject.h"

void onStandardMouseClick(GLObject *object, int button, int action, int mods, double xpos, double ypos);
void onStandardMouseMove(GLObject *object, double xpos, double ypos);

void GLObject::InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, points, GL_STATIC_DRAW);
	glEnableVertexAttribArray((GLuint) arrayNum);
	glVertexAttribPointer((GLuint) arrayNum, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

GLObject::GLObject(int x, int y, int heigth, int width) : x(x), y(y), width(width), height(heigth)
{
	GLfloat g_vertex_buffer_data[] = {
		(((float)x + width) / SCREEN_WIDTH) * 2 - 1, (2 - ((float)y / SCREEN_HEIGTH) * 2) - 1, // bottom-right
		((float)x / SCREEN_WIDTH) * 2 - 1, (2 - ((float)y / SCREEN_HEIGTH) * 2) - 1, // bottom-left
		(((float)x + width) / SCREEN_WIDTH * 2) - 1, (2 - (((float)y + heigth) / SCREEN_HEIGTH) * 2) - 1, // top-left
		((float)x / SCREEN_WIDTH) * 2 - 1, (2 - (((float)y + heigth) / SCREEN_HEIGTH) * 2) - 1, // top-right
	};
	GLfloat uv_vertex_buffer_data[] = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	coordinates = new GLfloat[8];
	uvcoordinates = new GLfloat[8];
	for (int i = 0; i < 8; i++)
	{
		coordinates[i] = g_vertex_buffer_data[i];
		uvcoordinates[i] = uv_vertex_buffer_data[i];
	}
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	InitObject(coordinates, 8 * sizeof(GLfloat), vbo, 0);
	glBindVertexArray(0);
	glGenBuffers(1, &vboT);
	glBindVertexArray(vao);
	InitObject(uvcoordinates, 8 * sizeof(GLfloat), vboT, 1);
	glBindVertexArray(1);
    onMouseClick = &onStandardMouseClick;
    onMouseMove = &onStandardMouseMove;
}

void GLObject::draw()
{
	glUseProgram(shaders);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//glBindVertexArray(0);
}

bool GLObject::isMouseOnObject(double xpos, double ypos)
{
	return (xpos >= x && xpos <= (x + height) && ypos >= y && ypos <= (y + width));
}

void GLObject::active()
{
}

void GLObject::deactivate()
{
}

GLObject::~GLObject()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

Coordinates * GLObject::getCoordinates() {
    return new Coordinates(x, (x + width), y, y + height);
}

void GLObject::setOnMouseClick(mouseClick onMouseClick) {
    this->onMouseClick = onMouseClick;
}

void GLObject::setOnMouseMove(mouseMove onMouseMove) {
    this->onMouseMove = onMouseMove;
}

void onStandardMouseClick(GLObject *object, int button, int action, int mods, double xpos, double ypos)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        object->press();
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        object->deactivate();
    }
}

void onStandardMouseMove(GLObject *object, double xpos, double ypos)
{
    object->active();
}