/*
 * GUIClass.cpp
 *
 *  Created on: Aug 8, 2012
 *      Author: dong
 */

#include "GUIClass.h"
int GUIModule::x=0, GUIModule::y=0, GUIModule::b1=0, GUIModule::b2=0;



typedef std::map <gui::Gui*, void(*)()>::iterator MapIter;
GUIModule::GUIModule():fadeAlpha(0) {

}

GUIModule::~GUIModule() {
}

void GUIModule::applyToAll(void (*func) (gui::Gui &))
{
	for (MapIter i = objects.begin(); i != objects.end(); i++){
		func(*(i->first));
	}
}

void GUIModule::update(bool handle)
{
	for (MapIter i = objects.begin(); i != objects.end(); i++){
		if (handle){
			i->first->autoHandle(x,y,b1,b2);
			if (i->first->isAwake()) i->second();
		}

		i->first->draw();
	}
	doPerFrame();
}


float changeValue=0;
void changeAlpha(gui::Gui& a){
	a.changeAlpha(changeValue);
}

bool GUIModule::start()
{
	changeValue=0.5;//todo smoothen this
	GUIModule::applyToAll(changeAlpha);
	GUIModule::update();
	fadeAlpha++;
	if (fadeAlpha< 510) return true;//todo make efficient
	else return false;
}

bool GUIModule::stop()
{
	changeValue=-0.5;//todo smoothen this
	GUIModule::applyToAll(changeAlpha);
	GUIModule::update(false);
	fadeAlpha--;
	if (fadeAlpha>0) return true;
	else return false;
}

