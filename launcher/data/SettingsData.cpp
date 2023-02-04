//
// Created by cybik on 22-07-30.
//

#include "SettingsData.h"

#include <string>

#include <yaml-cpp/node/emit.h>

#define ANIME_PATH "/anime-game-launcher"

#include <XdgUtils/BaseDir/BaseDir.h>
std::shared_ptr<SettingsData> SettingsData::_settingsData = nullptr;
std::shared_ptr<SettingsData> SettingsData::getSettingsData() {
    if(!_settingsData) {
        _settingsData = std::make_shared<SettingsData>(
            std::string(XdgUtils::BaseDir::XdgDataHome()).append(ANIME_PATH)
        );
    }
    return _settingsData;
}

std::shared_ptr<Settings> SettingsData::getSettings() {
    return _settings;
}

SettingsData::SettingsData(std::filesystem::path path) {
    _file = ((_path = path).string() + "/config.yaml");
    if(is_regular_file(_file)) {
        _settings = std::make_shared<Settings>(YAML::LoadFile(_file.string()));
        return;
    }
    //_settings = std::make_shared<Settings>();
}
