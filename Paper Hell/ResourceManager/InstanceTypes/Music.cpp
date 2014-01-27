/*
 * Music.cpp
 *
 *  Created on: Aug 31, 2012
 *      Author: dong
 */

#include "Music.hpp"

MusicHandle::MusicHandle(const ResourceType & target)
{
	music=&((Music&)(target)).resource;
}

