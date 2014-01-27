/*
 * CharacterBuffer.cpp
 *
 *  Created on: Aug 16, 2012
 *      Author: dong
 */

#ifndef MAINFUNCTIONS_CPP_
#define MAINFUNCTIONS_CPP_
#include <string>

namespace cc{

//****************
//getChars():
//Returns string of chars entered
//during the frame.
//****************
const std::string & getChars();

//****************
//setActive():
//Sets the character buffering active.
//This is so time is not wasted buffering
//characters.
//****************
void setState(bool state);
}
#endif
