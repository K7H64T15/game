#include "GLFrame.h"

void GLFrame::InitObject(const GLfloat points[], const int size, GLuint vbo, int arrayNum) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, points, GL_STATIC_DRAW);
	glEnableVertexAttribArray((GLuint) arrayNum);
	glVertexAttribPointer((GLuint) arrayNum, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

GLFrame::GLFrame()
{
	GLfloat g_vertex_buffer_data[] = {
		1.0f, -1.0f, // bottom-right
		-1.0f, -1.0f, // bottom-left
		1.0f, 1.0f, // top-left
		-1.0f, 1.0f, // top-right
	};
	GLfloat uv_vertex_buffer_data[] = {
		1.0f, 0.0f, // bottom-right
		0.0f, 0.0f, // bottom-left
		1.0f, 1.0f, // top-left
		0.0f, 1.0f, // top-right
	};
	coordinates = new GLfloat[8];
	uvcoordinates = new GLfloat[8];
	for (int i = 0; i < 8; i++)
	{
		coordinates[i] = g_vertex_buffer_data[i];
		uvcoordinates[i] = uv_vertex_buffer_data[i];
	}
	shaders = LoadShaders("FrameVertexShader.vertexshader", "FrameFragmentShader.fragmentshader");
	texture = loadBMP_custom("background.bmp");
	GLuint TextureID = (GLuint) glGetUniformLocation(shaders, "myTextureSampler");
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	InitObject(coordinates, 8 * sizeof(GLfloat), vbo, 0);
	glBindVertexArray(0);
	glGenBuffers(1, &vboT);
	glBindVertexArray(vao);
	InitObject(uvcoordinates, 8 * sizeof(GLfloat), vboT, 1);
	glBindVertexArray(1);
}

void GLFrame::addChild(GLObject *child)
{
	children.push_back(child);
}

void GLFrame::draw()
{
	glUseProgram(shaders);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//glBindVertexArray(0);
	//glBindVertexArray(1);
	for (std::list<GLObject*>::const_iterator iterator = children.begin(), end = children.end(); iterator != end; ++iterator) 
		(*iterator)->draw();
}

GLFrame::~GLFrame()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glDeleteProgram(shaders);
	glDeleteTextures(1, &texture);
	while (!children.empty())
	{
		delete children.back();
		children.pop_back();
	}
}

std::list<Coordinates *> * GLFrame::getCoordinates() {
	std::list<Coordinates* > *result = new std::list<Coordinates* >();
    for (std::list<GLObject*>::const_iterator iterator = children.begin(), end = children.end();
         iterator != end; ++iterator) {
        result->push_back((*iterator)->getCoordinates());
    }
    return result;
}

std::list<mouseClick> * GLFrame::getOnMouseClickHandlers() {
    std::list<mouseClick> *result = new std::list<mouseClick>();
    for (std::list<GLObject*>::const_iterator iterator = children.begin(), end = children.end();
         iterator != end; ++iterator) {
        result->push_back((*iterator)->getOnMouseClick());
    }
    return result;
}
