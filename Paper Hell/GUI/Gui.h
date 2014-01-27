/*
 * Gui.h
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */

#ifndef GUI_H_
#define GUI_H_
#include "../ResourceManager/InstanceTypes.hpp"
#include <vector>
namespace gui{
class Gui {
protected:
	bool state;
	struct Box{
		int x,y, maxX, maxY;
		void setPos(int _x, int _y);//this function is not center orientated
		void move(int _x, int _y);
		bool inArea(int _x,int _y);
	}bounds;
public:
	virtual void autoHandle(int x, int y, bool a, bool b)=0;//autohandles using mouse state
	virtual void draw()=0;//draws this element
	virtual void setPosition(float x, float y)=0;
	virtual void changeAlpha(float a)=0;
	bool isAwake();//checks if item is awake
	Gui();
	virtual ~Gui();
};
}
#endif /* GUI_H_ */
