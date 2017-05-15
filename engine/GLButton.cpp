#include "GLButton.h"
#include "Utility.h"
#include "ResourseFactory.h"

GLButton::GLButton(std::string standardTexture, int x, int y, int heigth, int width) :
        GLObject(Utility::getXCoordinate(x), Utility::getYCoordinate(y), Utility::getYCoordinate(heigth),
                 Utility::getXCoordinate(width))
{
    loadTextures(standardTexture, standardTexture, standardTexture);
    texture = this->standardTexture;
}


GLButton::GLButton(std::string standardTexture, std::string activeTexture, int x, int y, int heigth, int width)
		: GLObject(Utility::getXCoordinate(x), Utility::getYCoordinate(y), Utility::getYCoordinate(heigth),
                   Utility::getXCoordinate(width))
{
	loadTextures(standardTexture, activeTexture, activeTexture);
	texture = this->standardTexture;
}

GLButton::GLButton(std::string standardTexture, std::string activeTexture, std::string clickTexture, int x, int y,
                   int heigth, int width) :
        GLObject(Utility::getXCoordinate(x), Utility::getYCoordinate(y), Utility::getYCoordinate(heigth),
                 Utility::getXCoordinate(width))
{
    loadTextures(standardTexture, activeTexture, clickTexture);
    texture = this->standardTexture;
}

void GLButton::loadTextures(std::string standardTexture, std::string activeTexture, std::string clickTexture)
{
    shaders = LoadShaders("ButtonVertexShader.vertexshader", "ButtonFragmentShader.fragmentshader");
    this->standardTexture = ResourseFactory::getInstance()->getTexture(standardTexture);
    this->activeTexture = ResourseFactory::getInstance()->getTexture(activeTexture);
    this->onClickTexture = ResourseFactory::getInstance()->getTexture(clickTexture);
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