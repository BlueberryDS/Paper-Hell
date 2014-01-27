/*
 * Gui.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */

#include "Gui.h"
namespace gui{
Gui::Gui():state(false) {

}

/*bool Gui::setAndCheckCurserPos(int x, int y, bool a, bool b)
{
	cursorState.inArea= x<bounds.maxX && x>bounds.x
			&& y<bounds.maxY && y>bounds.y;
	cursorState.x=x;
	cursorState.y=y;
	cursorState.a=a;
	cursorState.b=b;
	return cursorState.inArea;
}*/

bool Gui::isAwake()
{
	return state;
}

Gui::~Gui() {
}

}

void gui::Gui::Box::setPos(int _x, int _y)
{
	int cx, cy;
	cx= x-_x;
	cy=y-_y;
	y-=cy;
	maxY-=cy;
	maxX-=cx;
	x-=cx;
}



void gui::Gui::Box::move(int cx, int cy)
{
	y+=cy;
	maxY+=cy;
	maxX+=cx;
	x+=cx;
}

bool gui::Gui::Box::inArea(int _x, int _y)
{
	return _x<maxX && _x>x
			&& _y<maxY && _y>y;
}




