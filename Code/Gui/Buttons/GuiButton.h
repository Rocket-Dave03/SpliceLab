#pragma once
#include "../GuiControl.h"
#include "../../All.h"


class GuiButton : public GuiControl
{
public:
	GuiButton();
	~GuiButton();

	void draw();
};