/*
 * TextBox.h
 *
 *  Created on: Aug 15, 2012
 *      Author: dong
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

#include "Button.h"
#include <string>
namespace gui {

class TextBox: public Button {
	Text text;
	std::string string;
	std::string defText;
	float offX, offY;
	unsigned int numCharactors;
	void setText(float x, float y);
public:
	TextBox(){};
	TextBox(float textX, float textY,int chars,const Text & _text)
			:text(_text),offX(textX), offY(textY),numCharactors(chars)
		{setText(offX,offY);}
	TextBox(float textX, float textY,int chars,const Text & _text,Sprite off)
			:Button(off),text(_text),offX(textX), offY(textY),numCharactors(chars)
		{setText(offX,offY);};//sprite off should be in correct position
	TextBox(float textX, float textY,int chars,const Text & _text,Sprite off, Sprite on)
			:Button(off,on),text(_text),offX(textX), offY(textY),numCharactors(chars)
		{setText(offX,offY);}//sprite off should be in correct position
	TextBox(float textX, float textY,int chars,const Text & _text,Sprite off, Sprite on,Sound Click)
			:Button(off,on,Click),text(_text),offX(textX), offY(textY),numCharactors(chars)
		{setText(offX,offY);}//sprite off should be in correct position
	void setTextInstance(float textX,int chars, float textY,const Text & _text)
	{offX=textX; offY=textY; text=_text; setText(offX, offY);}
	void unActivate();
	std::string & getString(){return string;}
	void setDefault(const std::string & def){defText=def;unActivate();}
	virtual void autoHandle(int x, int y, bool a, bool b);
	virtual void draw(){Button::draw();
			text.draw();}
	virtual void setPosition(float x, float y){Button::setPosition(x,y); setText(offX,offY);}
	virtual void changeAlpha(float a){Button::changeAlpha(a);text.changeAlpha(a);}
	virtual ~TextBox(){}
};

}

#endif /* TEXTBOX_H_ */
