#pragma once
#include "GLObject.h"
class GLButton :
	public GLObject
{
	GLuint standardTexture, activeTexture, onClickTexture;
public:
	GLButton(int x = 0, int y = 0, int heigth = 0, int width = 0, std::string standardTexture = "asd",
             std::string activeTexture = "bakane");
	virtual void active();
	virtual void deactivate();
    virtual void press();
	~GLButton();
};

