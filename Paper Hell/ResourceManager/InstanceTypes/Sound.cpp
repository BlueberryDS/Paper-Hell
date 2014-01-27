/*
 * sounds.cpp
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#include "Sound.hpp"

Sound::Sound(const ResourceType & target)
{
	sound.SetBuffer(((SFX&)(target)).resource);
}

void Sound::play()
{
	sound.Play();
}


