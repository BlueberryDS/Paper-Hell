/*
 * Background.h
 *
 *  Created on: Aug 12, 2012
 *      Author: dong
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "TaskContainer/Task.hpp"
#include "ResourceManager/ResourceManager.h"

class Background: public Task {
		Resource bgPic;

		Sprite bgSprite;

	public:

		//****************
		//Background():
		//- Initializes the background picture.
		//-Sizes it.
		//****************
		Background() : bgPic(resourceManager.getResource("Resources/Background.jpg")){
			bgSprite = bgPic.createInstance<Sprite>();
			bgSprite.setSize(400, 800);//todo I dislike this, scaling is costy
			bgSprite.setPosition(200, 400);
		}

		//****************
		//Background():
		//Draws the background pic.
		//****************
		virtual void update(bool handle = true){
			bgSprite.draw();
		}

		//***************
		//DUMMY DECONSTRUCTOR
		//***************
		virtual ~Background(){}
};

#endif /* BACKGROUND_H_ */
