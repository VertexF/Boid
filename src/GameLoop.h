#ifndef GAME_LOOP_HDR
#define GAME_LOOP_HDR

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <string>
#include <memory>

#include "Init.h"
#include "Graphics/Shader.h"

namespace util
{
class Game : public Application
{
public:
    Game(const std::string title, int w, int h);
    void mainLoop();
private:
    void display();
    void handleEvents();
    void update();

    bool _running;

    std::unique_ptr<Shader> _shader;
};
} // util

#endif // !GAME_LOOP_HDR
