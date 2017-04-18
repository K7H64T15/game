#pragma once
#include "GLObject.h"
class GLButton :
	public GLObject
{
	GLuint standartTexture, activeTexture, onClickTexture;
    std::string textureString; //TODO: test field. Remove in final version
public:
	GLButton(int x = 0, int y = 0, int heigth = 0, int width = 0, std::string standartTexture = "asd", std::string activeTexture = "bakane");
	virtual void active();
	virtual void disactive();
    virtual std::string print();
	~GLButton();
};

