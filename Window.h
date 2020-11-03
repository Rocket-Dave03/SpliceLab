#pragma once
#include <SDL.h>
#include "ALL.h"
#include "Util.h"

class Window
{
public:
    

    Window(const char*,int, int);
    Window(const char*);
    Window();
    ~Window();

    int makeCurrent();
    int setPos(int, int);



    SDL_Window* handle = nullptr;
    SDL_GLContext context = NULL;

};

