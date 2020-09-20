#include <memory>

#include "GameLoop.h"

int main(int argv, char *argc[])
{
    std::unique_ptr<util::Game> game(std::make_unique<util::Game>("Boid", 640, 480));
    game->mainLoop();

    return 0;
}