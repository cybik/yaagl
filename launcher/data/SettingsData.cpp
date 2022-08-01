//
// Created by cybik on 22-07-30.
//

#include "SettingsData.h"
#include <iostream>

#define ANIME_PATH "/anime-game-launcher"


std::shared_ptr<SettingsData> SettingsData::getSettingsData(std::string path) {
    return std::make_shared<SettingsData>(path.append(ANIME_PATH));
}

void SettingsData::parse() {

}

SettingsData::SettingsData(std::filesystem::path path) {
    _file = ((_path = path).string() + "/config.yaml");
    if(is_regular_file(_file)) {
        _settings = std::make_shared<Settings>(YAML::LoadFile(_file.string()));
        return;
    }
    //_settings = std::make_shared<Settings>();
}
