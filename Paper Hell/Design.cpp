/*
 * Design.cpp
 *
 *  Created on: Aug 16, 2012
 *      Author: dong
 */

#include "Design.hpp"
#include "GameDataClasses/BulletData/BulletData.h"

Design::Design() {
	Sprite on, off;
	//Load text box resources
	textBoxResources.off = resourceManager.getResource("Resources/Design/TextBoxOff.png");//todo Note: Properly scale all pics before use
	textBoxResources.on  = resourceManager.getResource("Resources/Design/TextBoxOn.png");

	//Load font for TextBox
	Text text(defaultFont);
	text.setColor(0,0,0);

	//Create instances, and scale them
	on = textBoxResources.on.createInstance<Sprite>();
	off = textBoxResources.off.createInstance<Sprite>();
	on.setScale(0.4);
	off.setScale(0.4);


	textBoxResources.box = gui::TextBox(50,150,12,text,off,on);
	textBoxResources.box.setDefault("Enter File Name");
	textBoxResources.box.setPosition(250,300);
	GUIModule::addObject(textBoxResources.box,doNothing);

	load.on      = resourceManager.getResource("Resources/Design/LoadOn.png");
	load.off     = resourceManager.getResource("Resources/Design/LoadOff.png");
	load.sound   = resourceManager.getResource("Resources/PaperRip.wav");
	on           = load.on.createInstance<Sprite>();
	off          = load.off.createInstance<Sprite>();
	on.setScale(0.7);
	off.setScale(0.7);
	load.button  = gui::Button(off,on,load.sound.createInstance<Sound>());
	load.button.setPosition(200,600);
	GUIModule::addObject(load.button,doNothing);//todo, implement this
}

Design::~Design() {
}
