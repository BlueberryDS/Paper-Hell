/*
 * ResourceManager.cpp
 *
 *  Created on: Jul 5, 2012
 *      Author: dong
 */

#include "ResourceManager.h"

ResourceManager resourceManager;
Dummy dummy;

void ResourceManager::remove(std::string allocator)
{
	ResourceBase res(allocator);
	std::set<ResourceBase*,RBPtrCmp>::iterator it=resourceList.find(&res);
	if (it==resourceList.end()) throw 0;
	delete (*it);
	resourceList.erase(it);
}



Resource ResourceManager::getResource(std::string allocator)
{
	ResourceBase * newRes= new ResourceBase (allocator);
	std::set<ResourceBase*,RBPtrCmp>::iterator it=resourceList.find(newRes);
	if(it != resourceList.end()){
		delete newRes;
		return (*it) -> createResource();
	}
	else{
		resourceList.insert(newRes);
		newRes->load();
		return newRes->createResource();
	}
}

const bool RBPtrCmp::operator()(ResourceBase *a, ResourceBase *b)
{
	return *a<*b;
}

ResourceBase::~ResourceBase()
{
	delete resource;
}

void ResourceBase::load()
{
	resource = newResource(id);
}

Resource ResourceBase::createResource()
{
	return Resource(this, resource);
}

void ResourceBase::unRegister()
{
	instances--;
	if (instances == 0) resourceManager.remove(id);
}

void ResourceBase::newRegister()
{
	instances++;
}

inline const bool ResourceBase::operator <(const ResourceBase & ref)
{
	return id<ref.id;
}

Resource & Resource::operator =(const Resource & cp)
{
	target=cp.target;
	cp.mother->newRegister();
	mother->unRegister();
	mother=cp.mother;
	return *this;
}

Resource::~Resource()
{
	mother->unRegister();
}

Resource::Resource(const Resource& cp):mother(cp.mother),target(cp.target){
mother->newRegister();
}

Resource::Resource(ResourceBase * m, ResourceType * t):mother(m), target(t){
	mother->newRegister();
}








