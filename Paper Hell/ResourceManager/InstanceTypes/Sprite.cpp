/*
 * Sprite.cpp
 *
 *  Created on: Jul 11, 2012
 *      Author: dong
 */
#include"Sprite.hpp"
#include<cmath>

void Sprite::setPosition(float x,float y)
{
	sprite.SetPosition(x,y);
}


void Sprite::setHue(float r, float g, float b){
	sf::Color color = sprite.GetColor();
	color.r=r;
	color.g=g;
	color.b=b;
	sprite.SetColor(color);
}

void Sprite::changeAlpha(float mod)
{
	alpha+=mod;
	if (alpha<0) alpha=0;
	if (alpha>255) alpha=255;
	sf::Color color = sprite.GetColor();
	color.a=alpha;
	sprite.SetColor(color);
}



void Sprite::setSize(float x, float y)
{
	sprite.Scale(x/clipping.size.x, y/clipping.size.y);
	clipping.size.x=x;
	clipping.size.y=y;
}



void Sprite::setRotation(float deg)
{
	sprite.SetRotation(deg);
}

void Sprite::setScale(float s){
	sprite.SetScale(s,s);
	clipping.size.x*= s;//todo think about this later, floating point errors
	clipping.size.y*= s;
}


void Sprite::draw()
{
	target->Draw(sprite);
}



void Sprite::setAlpha(float a)
{
	alpha=a;
	sf::Color color = sprite.GetColor();
	color.a=alpha;
	sprite.SetColor(color);
}

float Sprite::getX(){
	return sprite.GetPosition().x;
}
float Sprite::getY(){
	return sprite.GetPosition().y;
}
float Sprite::getHeight(){
	return clipping.size.y;
}
float Sprite::getWidth(){
	return clipping.size.x;
}


void Sprite::setSubSect(float x, float y, float maxX, float maxY, bool recenter){
	sf::IntRect newRect;
	sf::Vector2f cent = sprite.GetCenter();
	float top = (y/clipping.size.y) * (clipping.original.GetHeight()) + clipping.original.Top;
	newRect.Top=top;
	newRect.Bottom=(maxY/clipping.size.y) * (clipping.original.GetHeight()) + clipping.original.Top;
	float left=(x/clipping.size.x) * (clipping.original.GetWidth()) + clipping.original.Left;
	newRect.Right=left;
	newRect.Right=(maxX/clipping.size.x) * (clipping.original.GetWidth()) + clipping.original.Left;
	sprite.SetSubRect(newRect);
	if (recenter){
		sprite.SetCenter(newRect.GetWidth()/2.0f, newRect.GetHeight()/2.0f);
		clipping.size=sprite.GetSize();
	}
	else sprite.SetCenter((((float)clipping.original.GetWidth()/2.0f) +(float)clipping.original.Left) - floor(left),
						  (((float)clipping.original.GetHeight()/2.0f)+ (float)clipping.original.Top) - floor(top));
	sprite.Resize(ceil(maxX-x),ceil(maxY-y));
}


Sprite::Sprite(const ResourceType & target):sprite(((Image&)(target)).resource),alpha(0), clipping(sprite){
	sf::Vector2f x = sprite.GetSize();
	sprite.SetCenter((x.x/2.0f),(x.y/2.0f));
}



Sprite::A::A(sf::Sprite & sprite)
{
	original = sprite.GetSubRect();
	size=sprite.GetSize();
}



