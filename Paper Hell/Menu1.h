/*
 * Menu1.h
 *
 * Main Menu Class
 *
 *  Created on: Aug 13, 2012
 *      Author: dong
 */

#ifndef MENU1_H_
#define MENU1_H_

#include "TaskContainer/GUIClass.h"
#include "GUI/GuiPack.h"
#include "ResourceManager/ResourceManager.h"

class Menu1: public GUIModule {
    ButtonSet play, title, design;
public:
	Menu1();
	virtual ~Menu1(){}
};

#endif /* MENU1_H_ */
