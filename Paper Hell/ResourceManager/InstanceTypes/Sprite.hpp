/*
 * Sprite.hpp
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "DrawTypes.hpp"


class Sprite: public DrawTypes{
	sf::Sprite sprite;
	float alpha;
	struct A{
		sf::IntRect original;
		sf::Vector2f size;
		A(sf::Sprite & sprite);
		A(){}
	}clipping;
public:
	Sprite(const ResourceType & target);
	Sprite(){}
	void draw();
	void setPosition(float x, float y);
	void setRotation(float deg);
	void setAlpha(float a);
	void setHue(float r, float g, float b);
	void setScale(float s);
	float getX();
	float getY();
	float getHeight();
	float getWidth();
	void setSubSect(float x, float y, float maxX, float maxY,bool recenter=false);
	void changeAlpha(float mod);
	void setSize(float x, float y);
};


#endif /* SPRITE_HPP_ */
