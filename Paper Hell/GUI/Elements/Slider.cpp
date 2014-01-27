/*
 * Slider.cpp
 *
 *  Created on: Jul 19, 2012
 *      Author: dong
 */

#include "Slider.hpp"
#include <cmath>

namespace gui{
Slider::Slider() {

}

Slider::Slider(Sprite _bar, float _endSize, float sliderStart, float sliderEnd):end1(_bar),end2(_bar),slider(_bar),bar(_bar),sliderSize(abs(sliderStart-sliderEnd)),held(false)
{
	float secondEnd = _bar.getHeight()-_endSize;
	float width= _bar.getWidth();
	sliderStop2=secondEnd-sliderSize/2;
	sliderStop1=_endSize+sliderSize/2;
	end1.setSubSect(0,0,width, _endSize,true);
	end2.setSubSect(0,secondEnd, width, end2.getHeight(),true);
	slider.setSubSect(0,sliderStart,width,sliderEnd,true);
	if (secondEnd - sliderEnd > sliderStart - _endSize){
		bar.setSubSect(0,sliderEnd+1, width, secondEnd-1,true);
	}
	else{
		bar.setSubSect(0,_endSize+1, width,sliderStart-1,true);
	}
	reposition();
}

void Slider::setPosition(float x, float y)
{
	bar.setPosition(x,y);
	reposition();
}

void Slider::setSize(float len)
{
	barLength=len;
	bar.setSize(bar.getWidth(), len);
	reposition();
}

void Slider::reposition(){
	float len = bar.getHeight();
	end1.setPosition(bar.getX(), bar.getY()-len/2-end1.getHeight()/2);
	end2.setPosition(bar.getX(), bar.getY()+len/2+end2.getHeight()/2);
	sliderStop1=bar.getY() - len/2 + sliderSize/2;
	sliderStop2=bar.getY() + len/2 - sliderSize/2;
	slider.setPosition(bar.getX(),sliderStop1);
	sliderPos = sliderStop1;
	bounds.x=bar.getX()-bar.getWidth()/2.0f;
	bounds.maxX=bar.getWidth()+bounds.x;
	bounds.y=end1.getY() - end1.getHeight()/2;
	bounds.maxY=end2.getY() - end2.getHeight()/2.0f;
	barLength=sliderStop2-sliderStop1;
	rangeScale=(max-min)/barLength;
	rangeOffset=min;
}

void Slider::draw(){
	bar.draw();
	end1.draw();
	end2.draw();
	slider.draw();
}

void Slider::autoHandle(int x, int y, bool a, bool b) {
	if (a){
	if (bounds.inArea(x,y)) {
		if (y > sliderPos - sliderSize / 2
				&& y < sliderPos + sliderSize / 2) {
			held=true;
		}
	}
	}
	else held=false;
	if (held){
		sliderPos=y;
		if (sliderPos<sliderStop1){
			sliderPos=sliderStop1;
		}
		else if(sliderPos>sliderStop2){
			sliderPos=sliderStop2;
		}
		slider.setPosition(slider.getX(), sliderPos);
		state=true;
	}
	else state=false;
}
    void Slider::setRange(float _min, float _max)
    {
    	min=_min;
    	max=_max;
    	reposition();
    }

    float Slider::getValue()
    {
    	return (sliderPos-sliderStop1)*rangeScale + rangeOffset;
    }

Slider::~Slider() {

}

void Slider::changeAlpha(float a){
	end1.changeAlpha(a);end2.changeAlpha(a);slider.changeAlpha(a);bar.changeAlpha(a);
}
}
