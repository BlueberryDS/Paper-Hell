/*
 * Music.hpp
 *
 *  Created on: Aug 31, 2012
 *      Author: dong
 */

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include "Instances.h"

class MusicHandle: public Instance{
	sf::Music * music;
public:
	MusicHandle(){}
	MusicHandle(const ResourceType & target);
};


#endif /* MUSIC_HPP_ */
