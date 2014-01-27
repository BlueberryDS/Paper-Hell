/*
 * Menu1.cpp
 *
 *  Created on: Aug 13, 2012
 *      Author: dong
 */

#include "Menu1.h"
#include "TaskContainer/TaskFunctions.hpp"
#include "Design.hpp"
#include <string>
void switchToDesign(){
	tf::stopUnload(tf::getThis());
	tf::startTask(tf::loadTask<Design>("DesignLoad"));
}

Menu1::Menu1() {
	play.on = resourceManager.getResource("Resources/Menu1/PlayOn.png");
	play.off = resourceManager.getResource("Resources/Menu1/PlayOff.png");
	play.sound = resourceManager.getResource("Resources/PaperRip.wav");
	play.button.setHighlightSprite(play.on.createInstance<Sprite>());
	play.button.setNormalSprite(play.off.createInstance<Sprite>());
	play.button.setSound(play.sound.createInstance<Sound>());
	play.button.setPosition(200,325);
	GUIModule::addObject(play.button,doNothing);

	title.on=resourceManager.getResource("Resources/Menu1/TitleOn.png");
	title.off=resourceManager.getResource("Resources/Menu1/TitleOff.png");
	Sprite on = title.on.createInstance<Sprite>();
	Sprite off = title.off.createInstance<Sprite>();
	on.setScale(0.8);
	off.setScale(0.8);
	title.button.setHighlightSprite(on);
	title.button.setNormalSprite(off);
	title.button.setPosition(200,140);
	GUIModule::addObject(title.button,doNothing);

	design.on=resourceManager.getResource("Resources/Menu1/DesignOn.png");
	design.off=resourceManager.getResource("Resources/Menu1/DesignOff.png");
	design.sound = resourceManager.getResource("Resources/PaperRip.wav");
	on = design.on.createInstance<Sprite>();
	off = design.off.createInstance<Sprite>();
	on.setScale(0.5);
	off.setScale(0.5);
	design.button.setHighlightSprite(on);
	design.button.setNormalSprite(off);
	design.button.setPosition(200,525);
	design.button.setSound(design.sound.createInstance<Sound>());
	GUIModule::addObject(design.button,switchToDesign);
}
