/*
 * Background.h
 *
 * Task for displaying the Background
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


		Background() : bgPic(resourceManager.getResource("Resources/Background.jpg")){
		//Background():
		//- Initializes the background picture.
		//-Sizes it.
		//****************
			bgSprite = bgPic.createInstance<Sprite>();
			bgSprite.setSize(400, 800);//todo I dislike this, scaling is costy
			bgSprite.setPosition(200, 400);
		}

		virtual void update(bool handle = true){
		//Background():
		//Draws the background pic.
		//****************
			bgSprite.draw();
		}

		virtual ~Background(){
		//DUMMY DECONSTRUCTOR
		//***************
		}
};

#endif /* BACKGROUND_H_ */
