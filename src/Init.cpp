#include <iostream>

#include "Init.h"

namespace util 
{
Application::Application(const std::string title, int w, int h) : 
    _title(title), _width(w), _height(h)
{
}

/******************************************************************************/
//! @brief The setup of the application.
void Application::setup()
{
    //This sets up what openGL version we are going to use, in 
    // this case it's 3.3 that why it say that.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL failed to start" << std::endl;
    }
    else
    {
        //What these function do is set up the Attributes we are going to be working with.
        //There are default values to all these SDL_GL_ function.
        //This function works by taking in a attribute and then setting up the totally number of bits it will be using
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (_window == nullptr)
        {
            std::cerr << "Window could not be started for some reason" << std::endl;
        }
        else
        {
            //This is how we start up the render.
            _context = SDL_GL_CreateContext(_window);
            if (_context == nullptr)
            {
                std::cerr << "Context could not be started for some reason" << std::endl;
            }
            else
            {
                //This is the vsync to stop the ripped animations.
                if (SDL_GL_SetSwapInterval(1) < 0)
                {
                    std::cerr << "Warning: Unable to set VSync!" << std::endl;
                }

                //Here we are starting up glew.
                glewExperimental = GL_TRUE;
                GLenum error = glewInit();
                if (GLEW_OK != error)
                {
                    std::cerr << stderr << "You are have glew error :(" << std::endl;
                }

                //Make sure OpenGL 3.3 is supported
                if (!GLEW_VERSION_3_2)
                {
                    printf("OpenGL 3.2 not supported!\n");
                }
            }
        }
    }
}


}