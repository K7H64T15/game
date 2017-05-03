//
// Created by istimaldar on 03.05.2017.
//

#include "Utility.h"
#include "SettingsManager.h"


Utility::Utility() {

}

int Utility::getXCoordinate(int oldX) {
    int screenWidth = stol(SettingsManager::getInstance()->getValue(SettingsManager::SCREEN_WIDTH));
    return (int)((double)oldX / STANDART_WIDTH * screenWidth);
}

int Utility::getYCoordinate(int oldY) {
    int screenHeigth = stol(SettingsManager::getInstance()->getValue(SettingsManager::SCREEN_HEIGHT));
    return (int)((double)oldY / STANDART_HEIGHT * screenHeigth);
}
