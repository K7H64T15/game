#include "GLButton.h"

GLButton::GLButton(std::string standardTexture, int x, int y, int heigth, int width) : GLObject(x, y, heigth, width)
{
    loadTextures(standardTexture, standardTexture, standardTexture);
    texture = this->standardTexture;
}


GLButton::GLButton(std::string standardTexture, std::string activeTexture, int x, int y, int heigth, int width)
		: GLObject(x, y, heigth, width)
{
	loadTextures(standardTexture, activeTexture, activeTexture);
	texture = this->standardTexture;
}

GLButton::GLButton(std::string standardTexture, std::string activeTexture, std::string clickTexture, int x, int y,
                   int heigth, int width) : GLObject(x, y, heigth, width)
{
    loadTextures(standardTexture, activeTexture, clickTexture);
    texture = this->standardTexture;
}

void GLButton::loadTextures(std::string standardTexture, std::string activeTexture, std::string clickTexture)
{
    shaders = LoadShaders("ButtonVertexShader.vertexshader", "ButtonFragmentShader.fragmentshader");
    this->standardTexture = loadBMP_custom(standardTexture.c_str());
    this->activeTexture = loadBMP_custom(activeTexture.c_str());
    this->onClickTexture = loadBMP_custom(clickTexture.c_str());
    GLuint TextureID = (GLuint) glGetUniformLocation(shaders, "myTextureSampler");
}

void GLButton::active()
{
	if (texture != activeTexture)
		texture = activeTexture;
}

void GLButton::press() {
    if (texture != onClickTexture)
        texture = onClickTexture;
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