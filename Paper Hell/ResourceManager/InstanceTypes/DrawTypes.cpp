/*
 * DrawTypes.cpp
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */
#include "DrawTypes.hpp"
sf::RenderWindow * DrawTypes::target=NULL;

void DrawTypes::setDrawTarget(sf::RenderWindow & t)
{
	target=&t;
}
