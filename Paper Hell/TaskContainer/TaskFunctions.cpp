/*
 * taskFunctions.cpp
 *
 *  Created on: Aug 1, 2012
 *      Author: dong
 */
#include"TaskFunctions.hpp"
using namespace std;
namespace tf {

std::vector <TaskHandle> tasks;
int size=0;
int current;

void updateTask() {
	for (int i = 0; i < size; i++) {
		if (tasks[i].running) {
			current=i;
			if(tasks[i].state == TaskHandle::normal) tasks[i].target->update();
			else if(tasks[i].state == TaskHandle::start){
				if(!tasks[i].target->start()) tasks[i].state = TaskHandle::normal;
			}
			else if(tasks[i].state == TaskHandle::stop){
				if(!tasks[i].target->stop()) {
					tasks[i].running=false;
					if(tasks[i].unloadOnStop==true){
						unloadTask(i);
						i--;
					}
				}
			}
		}
	}
}

int findTask(const std::string & name) {
	int size = tasks.size();
	for (int i = 0; i < size; i++) {
		if (tasks[i].name == name)
			return i;
	}
	return -1;
}

Task * getTask(int index) {
	return tasks.at(index).target;
}

void startTask(int index) {
	tasks[index].running = true;
	tasks[index].state = TaskHandle::start;
}


void stopTask(int index) {
	tasks[index].state = TaskHandle::stop;
}

void unloadTask(int index){
	if (index<current)current--;
	delete tasks[index].target;
	tasks.erase(tasks.begin()+index);
	size--;
}

void stopUnload(int index){
stopTask(index);
tasks[index].unloadOnStop=true;
}

}
