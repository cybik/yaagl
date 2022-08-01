//
// Created by cybik on 22-07-31.
//

#include "Settings.h"

#include <algorithm>

void Settings::parse(const YAML::Node &file) {
    runner = file["runner"].as<std::string>();
    dxvk = file["dxvk"].as<std::string>();
    theme = file["theme"].as<std::string>();
    hud = file["hud"].as<std::string>();
    shaders = file["shaders"].as<std::string>();
    discord.parse(file["discord"]);
    gamemode = file["gamemode"].as<bool>();
    fps_unlocker = file["fps_unlocker"].as<bool>();
    purge_dxvk_logs = file["purge_dxvk_logs"].as<bool>();
    lang.parse(file["lang"]);
    env = nullptr;
    folders.parse(file["folders"]);
    purge_logs.parse(file["purge_logs"]);
    wine.parse(file["wine"]);
    borderless_window = file["borderless_window"].as<bool>();
    use_terminal = file["use_terminal"].as<bool>();
    skip_analytics = file["skip_analytics"].as<bool>();
    server = file["server"].as<std::string>();
}

Settings::Settings(const YAML::Node &file) {
    parse(file);
}

std::unique_ptr<YAML::Node> Settings::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["runner"] = runner;
    (*out)["dxvk"] = dxvk;
    (*out)["theme"] = theme;
    (*out)["hud"] = hud;
    (*out)["shaders"] = shaders;
    (*out)["discord"] = (*discord.generate());
    (*out)["gamemode"] = gamemode;
    (*out)["fps_unlocker"] = fps_unlocker;
    (*out)["purge_dxvk_logs"] = purge_dxvk_logs;
    (*out)["lang"] = (*lang.generate());
    (*out)["env"] = std::list<std::string>();
    (*out)["folders"] = (*folders.generate());
    (*out)["purge_logs"] = (*purge_logs.generate());
    (*out)["wine"] = (*wine.generate());
    (*out)["borderless_window"] = borderless_window;
    (*out)["use_terminal"] = use_terminal;
    (*out)["skip_analytics"] = skip_analytics;
    (*out)["server"] = server;
    return std::move(out);
}

void SettingsWine::parse(const YAML::Node &file) {
    sync = file["sync"].as<std::string>();
    fsr = file["fsr"].as<bool>();
    virtual_desktop.parse(file["virtual_desktop"]);
}

std::unique_ptr<YAML::Node> SettingsWine::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["sync"] = sync;
    (*out)["fsr"] = fsr;
    (*out)["virtual_desktop"] = (*virtual_desktop.generate());
    return std::move(out);
}

void SettingsWineVirtualDesktop::parse(const YAML::Node &file) {
    enabled = file["enabled"].as<bool>();
    width = file["width"].as<int>();
    height = file["height"].as<int>();
}

std::unique_ptr<YAML::Node> SettingsWineVirtualDesktop::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["enabled"] = enabled;
    (*out)["width"] = width;
    (*out)["height"] = height;
    return std::move(out);
}

void SettingsPurge::parse(const YAML::Node &file) {
    launcher = file["launcher"].as<std::string>();
    game = file["game"].as<bool>();
}

std::unique_ptr<YAML::Node> SettingsPurge::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["game"] = game;
    (*out)["launcher"] = launcher;
    return std::move(out);
}

void SettingsFolders::parse(const YAML::Node &file) {
    prefix = file["prefix"].as<std::string>();
    game = file["game"].as<std::string>();
    temp = file["temp"].as<std::string>();
}

std::unique_ptr<YAML::Node> SettingsFolders::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["prefix"] = prefix;
    (*out)["game"] = game;
    (*out)["temp"] = temp;
    return std::move(out);
}

void SettingsLanguage::parse(const YAML::Node &file) {
    launcher = file["launcher"].as<std::string>();
    if(file["voice"].Type() != YAML::NodeType::Sequence) {
        abort();
    }
    for(int i = 0; i < file["voice"].size(); i++) {
        voice.push_back(file["voice"][i].as<std::string>());
    }
}

std::unique_ptr<YAML::Node> SettingsLanguage::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["launcher"] = launcher;
    for(int i = 0; i < voice.size(); i++) {
        for (const auto &item: voice) {
            (*out)["voice"].push_back(item);
        }
    }
    return std::move(out);
}


void SettingsDiscord::parse(const YAML::Node &file) {
    enabled = file["enabled"].as<bool>();
    timer = file["timer"].as<bool>();
    inLauncher.parse(file["states"]["in-launcher"]);
    inGame.parse(file["states"]["in-game"]);
}

std::unique_ptr<YAML::Node> SettingsDiscord::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["enabled"] = enabled;
    (*out)["timer"] = timer;
    YAML::Node states;
    states["in-launcher"] = (*inLauncher.generate());
    states["in-game"] = (*inGame.generate());
    (*out)["states"] = states;
    return std::move(out);
}

void SettingsDiscordState::parse(const YAML::Node &file) {
    details = file["details"].as<std::string>();
    state = file["state"].as<std::string>();
    icon = file["icon"].as<std::string>();
}

std::unique_ptr<YAML::Node> SettingsDiscordState::generate() {
    auto out = std::make_unique<YAML::Node>();
    (*out)["details"] = details;
    (*out)["state"] = state;
    (*out)["icon"] = icon;
    return std::move(out);
}
