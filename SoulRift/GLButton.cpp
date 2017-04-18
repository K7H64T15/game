#include "GLButton.h"

GLButton::GLButton(int x, int y, int heigth, int width, std::string standardTexture, std::string activeTexture)
		: GLObject(x, y, heigth, width)
{
	shaders = LoadShaders("ButtonVertexShader.vertexshader", "ButtonFragmentShader.fragmentshader");
	this->standartTexture = loadBMP_custom(standardTexture.c_str());
	this->activeTexture = loadBMP_custom(standardTexture.c_str());
	GLuint TextureID = (GLuint) glGetUniformLocation(shaders, "myTextureSampler");
	texture = this->standartTexture;
}

void GLButton::active()
{
	if (texture != activeTexture)
		texture = activeTexture;
}

void GLButton::disactive()
{
	if (texture != standartTexture)
		texture = standartTexture;
}

GLButton::~GLButton()
{
	glDeleteProgram(shaders);
	glDeleteTextures(1, &texture);
}
