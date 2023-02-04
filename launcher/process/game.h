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
    std::shared_ptr<Game> Launch(qint64*);
    std::shared_ptr<Game> Setup();
private:
    static std::shared_ptr<Game> _game;
};

#endif //QAGL_GAME_H
