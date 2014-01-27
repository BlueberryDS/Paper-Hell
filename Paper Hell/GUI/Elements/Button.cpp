/*
 * Button.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */

#include "Button.h"
namespace gui {

Button::Button() :
	hasHighlight(false), hasSound(false),activeLast(false), activeSprite(NULL) {

}


Button::~Button() {

}

Button::Button(Sprite off) :
	hasHighlight(false), hasSound(false),activeLast(false), activeSprite(&normal) {
	bounds.x = off.getX() - (off.getWidth() / 2);
	bounds.y = off.getY() - (off.getHeight() / 2);
	bounds.maxX = bounds.x + off.getWidth();
	bounds.maxY = bounds.y + off.getHeight();
	normal = off;
}
Button::Button(Sprite off, Sprite on) :
	hasHighlight(true), hasSound(false),activeLast(false), activeSprite(&normal) {
	bounds.x = off.getX() - (off.getWidth() / 2);
	bounds.y = off.getY() - (off.getHeight() / 2);
	bounds.maxX = bounds.x + off.getWidth();
	bounds.maxY = bounds.y + off.getHeight();
	normal = off;
	highlight = on;
	highlight.setPosition(off.getX(), off.getY());
}
Button::Button(Sprite off, Sprite on, Sound Click) :
	hasHighlight(true), hasSound(true),activeLast(false), activeSprite(&normal) {
	bounds.x = off.getX() - (off.getWidth() / 2);
	bounds.y = off.getY() - (off.getHeight() / 2);
	bounds.maxX = bounds.x + off.getWidth();
	bounds.maxY = bounds.y + off.getHeight();
	normal = off;
	highlight = on;
	sound = Click;
	highlight.setPosition(off.getX(), off.getY());
}
void Button::setNormalSprite(Sprite off) {
	bounds.x = off.getX() - (off.getWidth() / 2);
	bounds.y = off.getY() - (off.getHeight() / 2);
	bounds.maxX = bounds.x + off.getWidth();
	bounds.maxY = bounds.y + off.getHeight();
	normal = off;
	highlight.setPosition(off.getX(), off.getY());
	if (activeSprite == NULL)
		activeSprite = &normal;
}
void Button::setHighlightSprite(Sprite on) {
	highlight = on;
	hasHighlight = true;
	highlight.setPosition(normal.getX(), normal.getY());
}
void Button::setSound(Sound click) {
	sound = click;
	hasSound = true;
}
void Button::autoHandle(int x, int y, bool a, bool b) {
	if (bounds.inArea(x,y)) {
		if (a) {
			if (!activeLast){
			state = true;
			if (hasSound)
				sound.play();
			activeLast=true;
			}
			else {
				state=false;
			}
		}
		else{
			state=false;
			activeLast=false;
		}
		if (hasHighlight)
			activeSprite = &highlight;
	}
	else
		activeSprite = &normal;
}
void Button::draw() {
	activeSprite->draw();
}

void Button::setPosition(float x, float y) {
	bounds.setPos(x - (normal.getWidth() / 2.0f),
			y - (normal.getHeight() / 2.0f));
	normal.setPosition(x, y);
	highlight.setPosition(x, y);
}

void Button::clip(float left, float right, float top, float bottom)
{
	normal.setSubSect(left,top,normal.getWidth()-right, normal.getHeight()-bottom);
	highlight.setSubSect(left,top,highlight.getWidth()-right, highlight.getHeight()-bottom);
	bounds.maxX-=right;
	bounds.maxY-=bottom;
	bounds.x-=left;
	bounds.y-=top;
}

}

