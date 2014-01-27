/*
 * BulletBank.cpp
 *
 *  Created on: Aug 29, 2012
 *      Author: dong
 */

#include "BulletBank.h"
#include <set>
using namespace std;
namespace bb{
struct comp{
	bool operator()(const BulletData & x, const BulletData & y){
		return x.name < y.name;
	}
};

set <BulletData, comp> bullets;
typedef set <BulletData, comp>::iterator SetIter;

void addBullet(const BulletData & bullet){
	bullets.insert(bullet);
}
void removeBullet(const std::string & name){
	bullets.erase(BulletData(name));
}
const BulletData * findBullet(const std::string & name){
	return &(*bullets.find(BulletData(name)));
}

BulletData extractData(const std::string & name){
	SetIter iterBullet = bullets.find(BulletData(name));
	BulletData bullet=*iterBullet;
	bullets.erase(iterBullet);
	return bullet;
}

std::vector<string> getNames(){
	vector<string> names;
	for(SetIter i = bullets.begin(); i!=bullets.end(); i++){
		names.push_back(i->name);
	}
	return names;
}
}
