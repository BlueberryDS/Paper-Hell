/*
 * TaskFunctions.hpp
 *
 *  Created on: Aug 1, 2012
 *      Author: dong
 */

#ifndef TASKFUNCTIONS_HPP_
#define TASKFUNCTIONS_HPP_
#include "Task.hpp"
#include <string>
#include <vector>
namespace tf{
struct TaskHandle{
	Task * target; //pointer to dynamic memory
	std::string name;
	bool running;
	bool unloadOnStop;
	enum {
		start, stop, normal
	}state;
	TaskHandle(Task* a,const std::string & b):running(false), unloadOnStop(false){target=a; name=b;}
};

extern std::vector <TaskHandle> tasks;
extern int size;
extern int current;

template<class t>
int loadTask(const std::string & name){//Load a task into memory, do not run
	tasks.push_back(TaskHandle(new t(), name));
	size++;
	return tasks.size()-1;
}

void unloadTask(int index);//delete a tasks from memory, will also serve to immediately stop task

int findTask(const std::string & name);//find a task by name lookup
inline int getThis(){return current;}//return index of current task

Task * getTask(int index);//get the task associated with index

void startTask(int index);//start task, using start routine
void stopTask(int index);//stop task with stop routine
void stopUnload(int index);//stop task then unload

void updateTask();//update function

}

#endif /* TASKFUNCTIONS_HPP_ */
