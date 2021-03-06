#include "GameLoop.h"
#include "Graphics/Shader.h"

#include <iostream>

namespace util
{
/******************************************************************************/
Game::Game(const std::string title, int w, int h) :
    Application(title, w, h), _running(true),
    _shader(std::make_unique<Shader>())
{
    setup();
    _shader->openGLSetUp();
}

/******************************************************************************/
//! @brief Handles basic input
void Game::handleEvents()
{
    while (SDL_PollEvent(&_input))
    {
        switch (_input.type)
        {
        case SDL_QUIT:
            _running = false;
            break;

        case SDL_KEYDOWN:
            switch (_input.key.keysym.scancode)
            {
            case SDL_SCANCODE_ESCAPE:
                _running = false;
                break;
            }
        }
    }
}

/******************************************************************************/
//! @brief Updates the game.
void Game::update()
{
}

/******************************************************************************/
//! @brief Updates the display.
void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.3, 0.3, 0.3, 1.0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(_window);
}

/******************************************************************************/
//! @brief main game loop.
void Game::mainLoop()
{
    while (_running)
    {
        handleEvents();
        update();
        display();
    }
}
}; //util