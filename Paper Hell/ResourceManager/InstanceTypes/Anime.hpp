/*
 * Anime.h
 *
 *  Created on: Jul 18, 2012
 *      Author: dong
 */

#include "Sprite.hpp"
#include <vector>
#ifndef ANIME_H_
#define ANIME_H_


class Anime: public Sprite{
	std::vector<sf::Image> * list;
	sf::Sprite sprite;
	int frames;
public:
	Anime(){}
	Anime(const ResourceType & target);
};

#endif /* ANIME_H_ */
