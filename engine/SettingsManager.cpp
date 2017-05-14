//
// Created by istimaldar on 03.05.2017.
//

#include "SettingsManager.h"
#include <iostream>
#include <fstream>

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
    std::string line, parameter, value;
    std::ifstream config ("parametres.config");
    if (config.is_open())
    {
        while (std::getline (config,line) )
        {
            parameter = "";
            value = "";
            if (line != "")
            {
                unsigned long long int position = line.find ('=');
                for (unsigned long long i = 0; i < position; i++)
                {
                    parameter += line[i];
                }
                for (unsigned long long i = position + 1; i < line.length(); i++)
                {
                    value += line[i];
                }
                (*configs)[parameter] = value;
            }
        }
        config.close();
    }
}
