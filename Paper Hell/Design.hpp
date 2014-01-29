/*
 * Design.hpp
 *
 *	Loaded when Design mode is clicked.
 *
 *  Created on: Aug 16, 2012
 *      Author: dong
 */

#ifndef DESIGN_HPP_
#define DESIGN_HPP_
#include "GUI/GuiPack.h"
#include "TaskContainer/GUIClass.h"

class Design : public GUIModule {
	ButtonSet load;
	TextBoxSet textBoxResources;
public:
	Design();
	virtual ~Design();
};

#endif /* DESIGN_HPP_ */
