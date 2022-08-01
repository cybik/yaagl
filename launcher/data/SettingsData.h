//
// Created by cybik on 22-07-30.
//

#ifndef QAGL_SETTINGSDATA_H
#define QAGL_SETTINGSDATA_H


#include <memory>
#include <filesystem>
#include <string>

#include "Settings.h"

class SettingsData {
public:
    static std::shared_ptr<SettingsData> getSettingsData(std::string path);
    explicit SettingsData(std::filesystem::path);

    void parse();
private:
    SettingsData() = delete;

    std::filesystem::path _path;
    std::filesystem::path _file;

    std::shared_ptr<Settings> _settings;
};


#endif //QAGL_SETTINGSDATA_H
