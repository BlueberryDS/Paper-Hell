/*
 * Task.hpp
 *
 *  Created on: Jul 31, 2012
 *      Author: dong
 */

#ifndef TASK_HPP_
#define TASK_HPP_

class Task {
private:
	bool paused;
public:
	bool isPaused() {return paused;}
	virtual bool start(){return false;}
	//start routine, call
	//again till returns false
	virtual bool stop(){return false;}
	//stop routine, call
	//again till returns false
	void togglePause(){paused=false;}
	//sets hidden flag
	virtual void update(bool handle = true){}//update function
	Task():paused(false) {}//loading will be handled by this
	virtual ~Task(){}
};

#endif /* TASK_HPP_ */
