/*
 * Scroller.h
 *
 *  Created on: Jul 21, 2012
 *      Author: dong
 */

#ifndef SCROLLER_H_
#define SCROLLER_H_

#include "../Gui.h"
#include "Slider.hpp"
#include "Button.h"
#include <vector>
namespace gui {

class Scroller: public Gui {
	std::vector <Button*> items;
	Slider slider;
	float itemHeight, itemWidth;
public:
	Scroller(const Slider & slider, float buttonHeight, float buttonWidth);
	void addButton(Button & button);//puts button under control of class
	virtual void setPosition(float x, float y);
	void setSize(float size);
	virtual void autoHandle(int x, int y, bool a, bool b);
	virtual void draw();
	virtual ~Scroller();
};

}

#endif /* SCROLLER_H_ */
