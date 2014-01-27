/*
 * sounds.h
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#ifndef SOUNDS_H_
#define SOUNDS_H_
#include<SFML/Audio.hpp>
#include"Instances.h"

class Sound: public Instance{
	sf::Sound sound;
public:
	Sound(){}
	Sound(const ResourceType & target);
	void play();
};

#endif /* SOUNDS_H_ */
