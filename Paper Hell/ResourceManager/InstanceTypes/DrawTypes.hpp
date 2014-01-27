/*
 * DrawTypes.hpp
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#ifndef DRAWTYPES_HPP_
#define DRAWTYPES_HPP_
#include "Instances.h"
#include <SFML/Graphics.hpp>

class DrawTypes:public Instance{
protected:
	static sf::RenderWindow * target;
public:
	DrawTypes(){}
	static void setDrawTarget(sf::RenderWindow& t);
};

#endif /* DRAWTYPES_HPP_ */
