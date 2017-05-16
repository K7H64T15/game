//
// Created by istimaldar on 16.05.2017.
//

#ifndef GAME_IGLOBJECT_H
#define GAME_IGLOBJECT_H

struct Coordinates {
    int leftX;
    int rightX;
    int bottomY;
    int topY;
    Coordinates(int leftX, int rightX, int bottomY, int topY) : leftX(leftX), rightX(rightX), bottomY(bottomY),
                                                                topY(topY) {};
};

class IGLObject;

typedef void (*mouseClick)(IGLObject*, int , int , int , double, double);
typedef void (*mouseMove)(IGLObject*, double, double);

class IGLObject {
public:
    virtual void draw() = 0;
    virtual bool isMouseOnObject(double xpos, double ypos) = 0;
    virtual void setOnMouseClick(mouseClick onMouseClick) = 0;
    virtual mouseClick getOnMouseClick() = 0;
    virtual void setOnMouseMove(mouseMove onMouseMove) = 0;
    virtual mouseMove getOmMouseMove() = 0;
    virtual Coordinates * getCoordinates() = 0;
    virtual void active() = 0;
    virtual void press() = 0;
    virtual void deactivate() = 0;
};


#endif //GAME_IGLOBJECT_H
