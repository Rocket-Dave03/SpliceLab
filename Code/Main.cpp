#include <GL/glew.h>
#include "SDL.h"
#include <SDL_opengl.h>

#include "ALL.h"
#include "Windows/Window.h"
#include "Util/MeshLoader/MeshLoader.h"


 
const int SCREEN_WIDTH = 1920 / 2;
const int SCREEN_HEIGHT = 1080 / 2;





ArrayList<Window*> windows;

void quit(int);
void handleMouseEvent(SDL_Event);
int  exitCode = 0;
bool running;



#pragma warning( disable : 4100 )
int main(int argc, char* args[])
{

    printf("Starting SpliceLab\n");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    // Create List to hold window pointers
    windows = *(new ArrayList<Window*>());
    // Create Window with a name and pointer to list
    windows.append(new Window("Spilce Lab"));
    


    MeshLoader::Mesh* mesh;
    mesh = new MeshLoader::Mesh("Data/Meshes/Gui/Buttons/button_rouded.obj");

    // Main loop
    running = true;
    while(running)
    {
        // Draw Window Contents
        for (int i = 0; i < windows.size(); i++)
        {
            Window* win = windows[i];
            if (win != nullptr)
            {
                win->drawGUI();
            }
        }

        // Handle Window Events
        SDL_Event event;
        while (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
            
            case SDL_QUIT:
                for (int i = 0; i < windows.size(); i++)
                {
                    windows.deleteElement(i);
                    windows[i] = nullptr;
                }
                quit(EXIT_SUCCESS);
                break; 
            case SDL_MOUSEMOTION:
                handleMouseEvent(event);
                break;

            case SDL_MOUSEBUTTONDOWN:
                handleMouseEvent(event);
                break;

            case SDL_MOUSEBUTTONUP:
                handleMouseEvent(event);
                break;
            
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_CLOSE:
                    for (int i = 0; i < windows.size(); i++)
                    {

                        Window* win = windows[i];
                        if (win != nullptr)
                        {
                            if (event.window.windowID == SDL_GetWindowID(win->handle))
                            {
                                windows.deleteElement(i);
                                windows[i] = nullptr;
                            }
                        }
                    }
                    break;
                }
                break;
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
void handleMouseEvent(SDL_Event event)
{
    if (event.type == SDL_QUIT) {
        return;
    }
}
