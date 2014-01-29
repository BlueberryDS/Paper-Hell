/*
 * CharacterBuffer.cpp
 *
 *	Catches Characters Entered since previous check.
 *	Defined in Main()
 *
 *  Created on: Aug 16, 2012
 *      Author: dong
 */

#ifndef MAINFUNCTIONS_CPP_
#define MAINFUNCTIONS_CPP_
#include <string>

namespace cc{


const std::string & getChars();
//getChars():
//Returns string of chars entered
//during the frame.
//****************


void setState(bool state);
//setActive():
//Sets the character buffering active.
//This is so time is not wasted buffering
//characters.
//****************

}
#endif
