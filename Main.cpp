#include "ALL.h"
#include "Window.h"
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
 
const int SCREEN_WIDTH = 1920 / 2;
const int SCREEN_HEIGHT = 1080 / 2;


ArrayList<Window*>* windows;

void quit(int);
void handleEvents();
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

    //The window we'll be rendering to
    windows->append(new Window("Spilce Lab"));
    windows->append(new Window("Spilce Lab"));


    running = true;
    while(running)
    {
        //SDL_Event event;
        //while (SDL_PollEvent(&event) > 0)
        //{
        //    switch (event.type)
        //    {
        //    
        //    case SDL_QUIT:
        //        for (int i = 0; i < windows->size(); i++)
        //        {
        //            delete 
        //        }
        //        quit(EXIT_SUCCESS);
        //        break; 
        //    
        //    case SDL_WINDOWEVENT:
        //        switch (event.window.event)
        //        {
        //        case SDL_WINDOWEVENT_CLOSE:
        //            if (win2 != nullptr)
        //            {
        //                if (SDL_GetWindowID(win2->handle) == event.window.windowID)
        //                {
        //                    delete win2;
        //                    win2 = nullptr;
        //                    continue;
        //            
        //                }
        //            }
        //            if (window != nullptr)
        //            {
        //                if (SDL_GetWindowID(window->handle) == event.window.windowID)
        //                {
        //                    delete window;
        //                    window = nullptr;
        //                    continue;
        //            
        //                }
        //            }
        //        }
        //    }
        //}
        for (int i = 0; i < windows->size(); i++)
        {
            Window* win = windows->get(i);


        }
        //Window* win = windows->get(0);
        //if (win->makeCurrent() == 0 )
        //{
        //   
        //    glClearColor(0, 1, 1, 1);
        //    glClear(GL_COLOR_BUFFER_BIT);
        //    SDL_GL_SwapWindow(win->handle);
        //}
        //win = windows->get(0);
        //if ( win->makeCurrent() == 0 )
        //{
        //    
        //    glClearColor(1, 1, 1, 1);
        //    glClear(GL_COLOR_BUFFER_BIT);
        //    SDL_GL_SwapWindow(win->handle);
        //}
        //
        //if (SDL_PollEvent(&event) > 0)
        //{
        //    
        //
        //}
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