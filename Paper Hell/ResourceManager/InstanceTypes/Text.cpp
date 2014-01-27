/*
 * Text.cpp
 *
 *  Created on: Aug 15, 2012
 *      Author: dong
 */

#include "Text.h"

Text::Text(const ResourceType & target): alpha(0) {
string.SetFont(((Font&)(target)).resource);
string.SetSize(((Font&)(target)).resource.GetCharacterSize());
}

void Text::setText(const std::string & str){
string.SetText(str);
}

void Text::setSize(float size){
	string.SetSize(size);
}

void Text::setPosition(float x, float y){
	string.SetPosition(x,y);
}

void Text::changeAlpha(float mod)
{
	alpha+=mod;
	if (alpha<0) alpha=0;
	if (alpha>255) alpha=255;
	sf::Color color = string.GetColor();
	color.a=alpha;
	string.SetColor(color);
}

void Text::setAlpha(float a)
{
	alpha=a;
	sf::Color color = string.GetColor();
	color.a=alpha;
	string.SetColor(color);
}

void Text::setColor(float r, float g, float b)
{string.SetColor(sf::Color(r,b,b,alpha));}
Text::~Text() {
}
