/*
 * Text.h
 *
 *  Created on: Aug 15, 2012
 *      Author: dong
 */

#ifndef TEXT_H_
#define TEXT_H_

#include "DrawTypes.hpp"
#include <string>

class Text: public DrawTypes {
sf::String string;
float alpha;
public:
	Text(){}
	Text(const ResourceType & target);
	void setText(const std::string & str);
	void setSize(float size);
	void setPosition(float x,float y);
	void changeAlpha(float mod);
	void setAlpha(float a);
	void setColor(float r, float g, float b);
	void draw(){target->Draw(string);};
	virtual ~Text();
};

#endif /* TEXT_H_ */
