/*
 * Button.h
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../Gui.h"

namespace gui {

class Button: public Gui {
	Sound sound;
	bool hasHighlight, hasSound,activeLast;
	Sprite * activeSprite;
protected:
	Sprite normal, highlight;
public:
	Button();
	Button(Sprite off);//sprite off should be in correct position
	Button(Sprite off, Sprite on);//sprite off should be in correct position
	Button(Sprite off, Sprite on,Sound Click);//sprite off should be in correct position
	void setNormalSprite(Sprite off);//sprite off should be in correct position
	void setHighlightSprite(Sprite on);//will be set to position of sprite off
	void setSound(Sound click);
	void clip(float left, float right, float top, float bottom);//clips button by amount on each side
	virtual void autoHandle(int x, int y, bool a, bool b);
	virtual void draw();
	virtual void setPosition(float x, float y);
	virtual void changeAlpha(float a){normal.changeAlpha(a);highlight.changeAlpha(a);}
	~Button();
};

}

#endif /* BUTTON_H_ */
