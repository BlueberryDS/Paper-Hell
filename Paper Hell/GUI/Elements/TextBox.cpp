/*
 * TextBox.cpp
 *
 *  Created on: Aug 15, 2012
 *      Author: dong
 */

#include "TextBox.h"
#include <cstdlib>
#include "../../CharacterBuffer.hpp"
namespace gui {

TextBox * active = NULL;

void TextBox::setText(float x, float y){
	float tX, tY;
	tX=Button::normal.getX() - (Button::normal.getWidth()/2.0f)+x;
	tY=Button::normal.getY() - (Button::normal.getHeight()/2.0f)+y;
	text.setPosition(tX,tY);
}

void TextBox::autoHandle(int x, int y, bool a, bool b){
	Button::autoHandle(x,y,a,b);
	if (Gui::isAwake()){
		active = this;
		cc::setState(true);
	}
	if (active==this){
		const std::string & chars = cc::getChars();
			for (unsigned int i = 0; i<chars.size(); i++){
				if (chars[i]==8/*backspace*/){
					string.erase(string.size()>1?string.size()-1:0,1);
				}
				else if (chars[i]==13/*enter*/) unActivate();
				else string.append(1,chars[i]);
			}
		text.setText(string.size() == 0? defText
				:string.substr(string.size()>numCharactors?string.size()-numCharactors-1:0)
				);
	}
}

void TextBox::unActivate(){
	text.setText(defText);
	if (active==this) {
		active = NULL;
		cc::setState(false);
	}
}

}
