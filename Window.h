#pragma once
#include <SDL.h>
#include "ALL.h"
#include "Util.h"
#include "Gui.h"

class Window
{
protected:
    ArrayList<GuiControl*>* guiControls = new ArrayList<GuiControl*>();
    void (*drawCallback)(void);
public:
    

    Window(const char*,int, int);
    Window(const char*);
    Window();
    ~Window();

    int makeCurrent();
    void setPos(int, int);
    void setDrawFunction(void(*func)(void));

    void draw();
    void drawGUI();



    SDL_Window* handle = nullptr;
    SDL_GLContext context = NULL;

};

