/*
 * ResourceManager.h
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */
#include<set>
#include<string>
#include<vector>
#include "InstanceTypes.hpp"
#include "ResourceTypes.h"
#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

class ResourceManager;
class ResourceBase;
class Resource;
struct RBPtrCmp{
const bool operator()(ResourceBase * a, ResourceBase * b);
};

class ResourceManager{
	std::set<ResourceBase*,RBPtrCmp>
		resourceList;
public:
	Resource getResource(std::string);
	void remove(std::string);
	//no de-constructor because object can not possibly be destroyed until end of program
} extern resourceManager;

//Base for Resources, holds key and pointer to resource
class ResourceBase{
	int instances;
	std::string id;
	ResourceType * resource;
public:
	ResourceBase (std::string n): instances(0) , id(n), resource(NULL){}
	~ResourceBase();
	void load();
	virtual void unRegister();
	void newRegister();
	Resource createResource();
	const bool operator<(const ResourceBase& ref);
};

class Dummy:public ResourceBase{
public:
	Dummy():ResourceBase(""){}
	void unRegister(){}
}extern dummy;

//instance of resource for declaring instances
class Resource{
	ResourceBase * mother;//pointer to generator
	ResourceType * target;//pointer to resource
public:
	template<class t>
	t createInstance(){
		return t(*target);
	}
	Resource():mother(&dummy){};
	Resource(ResourceBase * m, ResourceType * t);
	Resource(const Resource& cp);
	Resource & operator=(const Resource& cp);
	~Resource();
};

#endif /* RESOURCEMANAGER_H_ */
