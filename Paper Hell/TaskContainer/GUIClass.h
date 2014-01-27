/*
 * GUIClass.h
 *
 *  Created on: Aug 8, 2012
 *      Author: dong
 */

#ifndef GUICLASS_H_
#define GUICLASS_H_

#include "Task.hpp"
#include <map>
#include "../GUI/Gui.h"
class GUIModule: public Task {
private:
typedef std::map <gui::Gui*, void(*)()> ObjList;
typedef std::pair <gui::Gui*, void(*)()> ObjPair;
ObjList objects;
static int x, y, b1, b2;
int fadeAlpha;
protected:
void addObject(gui::Gui & obj, void(*callback)()){objects.insert(ObjPair(&obj,callback));}
void removeObject(gui::Gui & obj){objects.erase(&obj);}
virtual void doPerFrame(){}
void applyToAll(void (*func) (gui::Gui &));
static void doNothing(){};
public:
	static void updateMouse(int _x,int _y,int _b1,int _b2){x=_x; y=_y;b1=_b1;b2=_b2;}
	GUIModule();
	virtual ~GUIModule();
	virtual void update(bool handle = true);
	virtual bool start();
	virtual bool stop();
};

#endif /* GUICLASS_H_ */
