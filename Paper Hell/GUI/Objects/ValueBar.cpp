/*
 * ValueBar.cpp
 *
 *  Created on: Jul 26, 2012
 *      Author: dong
 */

#include "ValueBar.h"

ValueBar::ValueBar() {
}

inline void ValueBar::setFullSprite(Sprite full)
{
	full.setPosition(fullBar.getX(),fullBar.getY());
	full.setSubSect(0,(max-value)*scale,full.getWidth(),full.getHeight());
	fullBar=full;
}

void ValueBar::setRange(float _max, float _min)
{
	max=_max;
	min=_min;
	scale= fullBar.getHeight()/(max-min);
}

void ValueBar::changeValue(float v)
{
	value+=v;
	if (value>max) value=max;
	else if(value<min) value=min;
	fullBar.setSubSect(0,(max-value)*scale,fullBar.getWidth(),fullBar.getHeight());
}

ValueBar::ValueBar(Sprite empty, Sprite full):emptyBar(empty), fullBar(full)
{
fullBar.setPosition(emptyBar.getX(), emptyBar.getY());
setValue(0);
}

void ValueBar::draw()
{
	emptyBar.draw();
	fullBar.draw();
}

void ValueBar::setValue(float v)
{
	value=v;
	if (value>max) value=max;
	else if(value<min) value=min;
	fullBar.setSubSect(0,(max-value)*scale,fullBar.getWidth(),fullBar.getHeight());
}

float ValueBar::getValue()
{
	return value;
}

void ValueBar::setPosition(float x, float y){
	fullBar.setPosition(x,y);
	emptyBar.setPosition(x,y);
}

ValueBar::~ValueBar() {
}
