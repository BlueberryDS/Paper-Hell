/*
 * ValueBar.h
 *
 *  Created on: Jul 26, 2012
 *      Author: dong
 */

#ifndef VALUEBAR_H_
#define VALUEBAR_H_
#include "../../ResourceManager/InstanceTypes.hpp"
class ValueBar{
	float value;
	float scale;
	float max,min;
	Sprite emptyBar, fullBar;
public:
	ValueBar();
	ValueBar(Sprite empty, Sprite full);
	void setRange(float _max, float _min);
	void setValue(float v);
	void changeValue(float v);
	float getValue();
	void setPosition(float x, float y);
	virtual void draw();
	void setFullSprite(Sprite full);
	virtual ~ValueBar();
};

#endif /* VALUEBAR_H_ */
