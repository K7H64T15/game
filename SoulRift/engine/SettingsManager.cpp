//
// Created by istimaldar on 03.05.2017.
//

#include "SettingsManager.h"

const std::string SettingsManager::SCREEN_HEIGHT = "screen_height";
const std::string SettingsManager::SCREEN_WIDTH = "screen_width";
SettingsManager *SettingsManager::instance = nullptr;

std::string SettingsManager::getValue(std::string key) {
    auto value = configs->find(key);
    if (value == configs->end()) {
        throw new std::invalid_argument("No such parameter");
    }
    return (value)->second;
}

SettingsManager *SettingsManager::getInstance() {
    if (instance == nullptr) {
        instance = new SettingsManager();
    }
    return instance;
}

SettingsManager::SettingsManager() {
    configs = new std::map<const std::string, std::string>();
    (*configs)[SCREEN_HEIGHT] = std::string("1080");
    (*configs)[SCREEN_WIDTH] = std::string("1920");
}
