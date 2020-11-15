#include "ALL.h"
#include "Windows/Window.h"
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
 
const int SCREEN_WIDTH = 1920 / 2;
const int SCREEN_HEIGHT = 1080 / 2;


ArrayList<Window*>* windows;
ArrayList<long*>* longs;

void quit(int);
int exitCode = 0;
bool running;

int main(int argc, char* args[])
{
    printf("Starting SpliceLab\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    

    windows = new ArrayList<Window*>();
    longs = new ArrayList<long*>();
    //The window we'll be rendering to
    windows->append(new Window("Spilce Lab"));
    

    running = true;
    while(running)
    {
        for (int i = 0; i < windows->size(); i++)
        {
            Window* win = windows->get(i);
            if (win != nullptr)
            {
                win->drawGUI();
            }
        }

        SDL_Event event;
        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            
            case SDL_QUIT:
                for (int i = 0; i < windows->size(); i++)
                {
                    windows->deleteElement(i);
                    windows->set(i, nullptr);
                }
                quit(EXIT_SUCCESS);
                break; 
            case SDL_KEYDOWN:
                if (event.key.type == SDL_KEYDOWN)
                {
                    longs->append(new long[100]);
                }
            
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                    for (int i = 0; i < windows->size(); i++)
                    {

                        Window* win = windows->get(i);
                        if (win != nullptr)
                        {
                            if (event.window.windowID == SDL_GetWindowID(win->handle))
                            {
                                windows->deleteElement(i);
                                windows->set(i, nullptr);
                            }
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

void quit(int code) 
{
    exitCode = code;
    running = false;
}