/*
 * GuiPack.h
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */
#ifndef GUIPACK_H_
#define GUIPACK_H_
#include"Elements/Button.h"
#include "Elements/Slider.hpp"
#include "Elements/TextBox.h"
#include "../ResourceManager/ResourceManager.h"
	struct ButtonSet{
		gui::Button button;
		Resource sound;
		Resource on;
		Resource off;
	};

	struct TextBoxSet{
		gui::TextBox box;
		Resource sound;
		Resource on;
		Resource off;
	};

#endif /* GUIPACK_H_ */
