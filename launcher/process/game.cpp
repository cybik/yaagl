//
// Created by cybik on 23-02-04.
//

#include "game.h"

#include "launcher/data/SettingsData.h"

std::shared_ptr<Game> Game::_game(nullptr);

//const QString _genpath = "/Depot/Games/Genshin/Game/drive_c/Program Files/Genshin Impact";
const QString _winepath = "/home/cybik/.steam/root/compatibilitytools.d/proton-latest/files/bin/wine";
const QString _executable = "GenshinImpact.exe";
//const QString _winepfx = "/Depot/Games/Genshin/GameTrash2";
std::shared_ptr<Game> Game::getGame() {
    if(!_game) {
        _game.reset(new Game());
    }
    return _game;
}

qint64 Game::LaunchIt(qint64* _pid) {
    _launch->LaunchIt(_pid);
    return (*_pid);
}

std::shared_ptr<Game> Game::Setup() {
    return getGame();
}

Game::Game() {
    _launch.reset(new Launch(
            QString(_winepath),
            QString(SettingsData::getSettingsData()->getSettings()->folders.game.c_str()),
            _executable,
            QString(SettingsData::getSettingsData()->getSettings()->folders.prefix.c_str())
        )
    );
}
