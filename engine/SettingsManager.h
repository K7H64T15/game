//
// Created by istimaldar on 03.05.2017.
//

#ifndef SOULRIFT_SETTINGSMANAGER_H
#define SOULRIFT_SETTINGSMANAGER_H

#include <string>
#include <map>

class SettingsManager {
    std::map<const std::string, std::string> *configs;
    static SettingsManager *instance;
public:
    static const std::string SCREEN_HEIGHT;
    static const std::string SCREEN_WIDTH;
    static const std::string FULLSCREEN;
    static SettingsManager *getInstance();
    std::string getValue(std::string);
private:
    SettingsManager();
};


#endif //SOULRIFT_SETTINGSMANAGER_H
