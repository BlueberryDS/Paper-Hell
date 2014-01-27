/*
 * ResourceTypes.cpp
 *
 *  Created on: Jul 7, 2012
 *      Author: dong
 */

#include "ResourceTypes.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#define EXT_LEN 3
#define MUSICKEY_LEN 7
#define MUSICKEY "(music)"

class BadFileCanNotLoad{
};

Image::Image(const std::string & id)
{
	resource.LoadFromFile(id);
}



Animation::Animation(const std::string & id)
{
	int file=0;
	std::stringstream name("0");
	sf::Image img;
	while(img.LoadFromFile(name.str()+".*")){
		resource.push_back(img);
		name.clear();
		name<< ++file;
	}
}



Music::Music(const std::string & id)
{
	resource.OpenFromFile(id);
}



SFX::SFX(const std::string & id)
{
	resource.LoadFromFile(id);
}

Font::Font(const std::string & id){
		int tmp = id.find(':');
		int size = atoi(id.substr(0, tmp).c_str());
		std::string name=id;
		name.erase(0,tmp+1);
		resource.LoadFromFile(name, size);
		def=false;
}

Font defaultFont("35:Resources/PenOfTruth.ttf");

ResourceType * newResource(const std::string & id)
{
	if (id.substr(0, MUSICKEY_LEN) == MUSICKEY)
		return new Music(id.substr(MUSICKEY_LEN));

	else if (id[id.size()-1] == '/' || id[id.size()-1] == '\\')
		return new Animation(id);

	std::string cases = id.substr(id.size()-EXT_LEN-1);

	if (cases == ".png"||
			cases == ".bmp"||
			cases == ".jpg")
		return new Image(id);

	else if (cases == ".mp3"||
			cases == ".wav"||
			cases ==  ".ogg")
		return new SFX(id);
	else if (cases == ".tf"||
			cases == ".ttf"
			) return new Font(id);

throw BadFileCanNotLoad();

}






