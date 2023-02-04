//
// Created by cybik on 23-02-04.
//

#include "game.h"

std::shared_ptr<Game> Game::_game(nullptr);

std::shared_ptr<Game> Game::getGame() {
    if(!_game) {
        std::make_shared<Game>();
    }
    return _game;
}

std::shared_ptr<Game> Game::Launch(qint64* _pid) {
    Launch::getLaunch()->LaunchIt(_pid);
    return getGame();
}

std::shared_ptr<Game> Game::Setup() {
    return getGame();
}
