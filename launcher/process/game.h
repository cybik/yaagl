//
// Created by cybik on 23-02-04.
//

#ifndef QAGL_GAME_H
#define QAGL_GAME_H

#include <memory>
#include <functional>

#include "launch.h"

class Game {
public:
    static std::shared_ptr<Game> getGame();
    qint64 LaunchIt(qint64*);
    std::shared_ptr<Game> Setup();
private:
    Game();
    static std::shared_ptr<Game> _game;

    std::shared_ptr<Launch> _launch;
};

#endif //QAGL_GAME_H
