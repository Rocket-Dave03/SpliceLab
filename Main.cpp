#include "ALL.h"
#include "Window.h"
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>

//Constant Screen Size
const int SCREEN_WIDTH = 1920 / 2;
const int SCREEN_HEIGHT = 1080 / 2;

//Function Quit
void quit(int);
int exitCode = 0;
bool running;

int main(int argc, char* args[])
{
    printf("Starting Splicelab\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    //The Window We'll Be Rendering To
    Window* window = nullptr;
    Window* win2 = nullptr;
    window = new Window("Spilcelab");
    win2 = new Window("Spilcelab");

    running = true;
    SDL_Event event;
    while (running)
    {
        if (window->makeCurrent() == 0)
        {
            glClearColor(0, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            SDL_GL_SwapWindow(window->handle);
        }
        if (win2->makeCurrent() == 0)
        {
            glClearColor(1, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            SDL_GL_SwapWindow(win2->handle);
        }

        if (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                delete window;
                delete win2;
                window = nullptr;
                win2 = nullptr;
                quit(EXIT_SUCCESS);
                break;

            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                    if (win2 != nullptr)
                    {
                        if (SDL_GetWindowID(win2->handle) == event.window.windowID)
                        {
                            delete win2;
                            win2 = nullptr;
                            continue;
                        }
                    }
                    if (window != nullptr)
                    {
                        if (SDL_GetWindowID(window->handle) == event.window.windowID)
                        {
                            delete window;
                            window = nullptr;
                            continue;

                        }
                    }
                }
            }

        }
    }
    printf("Closing\n");
    SDL_Quit();
    exit(exitCode);
}

//Quit
void quit(int code)
{
    exitCode = code;
    running = false;
}