#include "GLButton.h"

GLButton::GLButton(int x, int y, int heigth, int width, std::string standardTexture, std::string activeTexture)
		: GLObject(x, y, heigth, width)
{
	shaders = LoadShaders("ButtonVertexShader.vertexshader", "ButtonFragmentShader.fragmentshader");
	this->standardTexture = loadBMP_custom(standardTexture.c_str());
	this->activeTexture = loadBMP_custom(activeTexture.c_str());
	GLuint TextureID = (GLuint) glGetUniformLocation(shaders, "myTextureSampler");
	texture = this->standardTexture;
}

void GLButton::active()
{
	if (texture != activeTexture)
		texture = activeTexture;
}

void GLButton::press() {
    if (texture != activeTexture)
        texture = activeTexture;
}

void GLButton::deactivate()
{
	if (texture != standardTexture)
		texture = standardTexture;
}

GLButton::~GLButton()
{
	glDeleteProgram(shaders);
	glDeleteTextures(1, &texture);
}


