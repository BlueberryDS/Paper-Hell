/*
 * Slider.hpp
 *
 *  Created on: Jul 19, 2012
 *      Author: dong
 */

#ifndef SLIDER_HPP_
#define SLIDER_HPP_

#include "../Gui.h"
#include <vector>
namespace gui{
class Slider: public Gui {
	float barLength;
	Sprite end1, end2, slider,bar;
	float endSize;
	float sliderSize;
	float sliderStop1, sliderStop2;
	float sliderPos;
	float rangeOffset;
	float rangeScale;
	float min, max;
	bool held;
	void reposition();
public:
	Slider();
	Slider(Sprite _bar, float _endSize, float sliderStart, float sliderEnd);
	virtual void setPosition(float x, float y);//set center of bar, resets bar
	virtual void draw();//draws object
	virtual void autoHandle(int x, int y, bool a, bool b);
	virtual void changeAlpha(float a);
	void setSize(float len);
	void setRange(float min, float max);
	float getValue();
	virtual ~Slider();
};
}
#endif /* SLIDER_HPP_ */
