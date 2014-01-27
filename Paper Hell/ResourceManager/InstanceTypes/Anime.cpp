/*
 * Anime.cpp
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#include "Anime.hpp"


Anime::Anime(const ResourceType & target)
{
	list=&((Animation*)(&target))->resource;
	frames=list->size();
}

