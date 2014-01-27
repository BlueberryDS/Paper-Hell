/*
 * ResourceTypes.h
 *
 *  Created on: Jul 7, 2012
 *      Author: dong
 */
#include"SFML/Audio.hpp"
#include"SFML/Graphics/Image.hpp"
#include"SFML/Graphics/Font.hpp"
#include <string>
#include <exception>
#ifndef RESOURCETYPES_H_
#define RESOURCETYPES_H_

struct ResourceType {
	virtual ~ResourceType(){}
};

struct SFX: public ResourceType{
	sf::SoundBuffer resource;
	SFX(const std::string & id);
};

struct Music: public ResourceType{
	sf::Music resource;
	Music(const std::string & id);
};

struct Image: public ResourceType{
	sf::Image resource;
	Image(const std::string & id);
};

struct Animation: public ResourceType{
	std::vector<sf::Image> resource;
	Animation(const std::string & id);
};

struct Font: public ResourceType{
	sf::Font resource;
	bool def;
	Font(const std::string & id);

}extern defaultFont;

ResourceType * newResource(const std::string& id);
#endif /* RESOURCETYPES_H_ */


