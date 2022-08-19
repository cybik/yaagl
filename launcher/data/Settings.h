//
// Created by cybik on 22-07-31.
//

#ifndef QAGL_SETTINGS_H
#define QAGL_SETTINGS_H

#include <string>
#include <list>
#include <yaml-cpp/yaml.h>

class SettingsParsing {
public:
    virtual void parse(const YAML::Node& file) = 0;
    virtual std::unique_ptr<YAML::Node> generate() = 0;
protected:
    SettingsParsing() = default;
};

class SettingsDiscordState : protected SettingsParsing {
public:
    SettingsDiscordState() = default;
    std::string details;
    std::string state;
    std::string icon;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
};

class SettingsDiscord : protected SettingsParsing  {
public:
    SettingsDiscord() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    bool enabled;
    bool timer;
    SettingsDiscordState inLauncher;
    SettingsDiscordState inGame;
};

class SettingsLanguage : protected SettingsParsing  {
public:
    SettingsLanguage() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    std::string launcher;         // enum?
    std::list<std::string> voice; // enum list?
};

class SettingsFolders : protected SettingsParsing  {
public:
    SettingsFolders() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    std::string prefix;
    std::string game;
    std::string temp;
};

class SettingsPurge : protected SettingsParsing  {
public:
    SettingsPurge() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    bool game;
    std::string launcher;
};

class SettingsWineVirtualDesktop : protected SettingsParsing  {
public:
    SettingsWineVirtualDesktop() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    bool enabled;
    int width;
    int height;
};

class SettingsWine : protected SettingsParsing  {
public:
    SettingsWine() = default;
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    std::string sync;        // enum?
    bool fsr;
    SettingsWineVirtualDesktop virtual_desktop;
};

class Settings : protected SettingsParsing {
public:
    Settings(); // TODO: config being initiated.
    Settings(const YAML::Node& file);
    void parse(const YAML::Node& file) override;
    std::unique_ptr<YAML::Node> generate() override;
    std::string runner;      // enum?
    std::string dxvk;        // enum?
    std::string theme;       // enum?
    std::string hud;         // enum?
    std::string shaders;
    SettingsDiscord discord;
    bool gamemode;
    bool fps_unlocker;
    bool purge_dxvk_logs;
    SettingsLanguage lang;
    void* env; // map
    SettingsFolders folders;
    SettingsPurge purge_logs;
    SettingsWine wine;
    bool borderless_window;
    bool use_terminal;
    bool skip_analytics;
    std::string server; // enum

    std::string to_string();
};

#endif //QAGL_SETTINGS_H
