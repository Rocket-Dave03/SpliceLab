#pragma once
#include "../SDL.h"
#include "../ALL.h"
#include "../Util/Util.h"
#include "../Gui/Gui.h"

class Window
{
protected:
    ArrayList<GuiControl*>* guiControls = new ArrayList<GuiControl*>();
private:
    static SDL_Surface* icon;
public:
    

    Window(const char*,int, int);
    Window(const char*);
    Window();
    ~Window();

    int makeCurrent();
    void setPos(int, int);

    void drawGUI();
    void setProgramIcon(const char*);



    SDL_Window* handle = nullptr;
    SDL_GLContext context = NULL;

};

