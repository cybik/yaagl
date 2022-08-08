//
// Created by cybik on 22-07-30.
//

#include "SettingsData.h"

#include <string>

#include <yaml-cpp/node/emit.h>

#define ANIME_PATH "/anime-game-launcher"


std::unique_ptr<SettingsData> SettingsData::getSettingsData(std::string path) {
    return std::move(std::make_unique<SettingsData>(path.append(ANIME_PATH)));
}

std::string SettingsData::to_string() {
    return YAML::Dump(*_settings->generate());
}

SettingsData::SettingsData(std::filesystem::path path) {
    _file = ((_path = path).string() + "/config.yaml");
    if(is_regular_file(_file)) {
        _settings = std::make_shared<Settings>(YAML::LoadFile(_file.string()));
        return;
    }
    //_settings = std::make_shared<Settings>();
}
