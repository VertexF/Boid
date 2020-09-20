#ifndef INIT_HDR
#define INIT_HDR

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <string>

namespace util
{
class Application
{
public:
    Application(const std::string title, int w, int h);
    void setup();

protected:
    SDL_GLContext _context;
    SDL_Window* _window;
    SDL_Event _input;

    std::string _title;
    int _width;
    int _height;
    float _ratio;
};
};

#endif //INIT_HDR