#pragma once
#include "GLObject.h"
class GLButton :
	public GLObject
{
	GLuint standardTexture, activeTexture, onClickTexture;
public:
    GLButton(std::string standardTexture, int x = 0, int y = 0, int heigth = 0, int width = 0);
	GLButton(std::string standardTexture, std::string activeTexture, int x = 0, int y = 0, int heigth = 0,
             int width = 0);
    GLButton(std::string standardTexture, std::string activeTexture, std::string clickTexture, int x = 0, int y = 0,
             int heigth = 0, int width = 0);
    void loadTextures(std::string standardTexture, std::string activeTexture, std::string clickTexture);
	virtual void active();
	virtual void deactivate();
    virtual void press();
	~GLButton();
};

