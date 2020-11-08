#pragma once
#include <SDL.h>
#include "../ALL.h"
#include "../Util/Util.h"
#include "../Gui/Gui.h"

class Window
{
protected:
    ArrayList<GuiControl*>* guiControls = new ArrayList<GuiControl*>();
public:
    

    Window(const char*,int, int);
    Window(const char*);
    Window();
    ~Window();

    int makeCurrent();
    void setPos(int, int);

    void drawGUI();



    SDL_Window* handle = nullptr;
    SDL_GLContext context = NULL;

};

