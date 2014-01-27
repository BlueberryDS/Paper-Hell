/*
 * BulletData.h
 *
 *  Created on: Aug 24, 2012
 *      Author: dong
 */

#ifndef BULLETDATA_H_
#define BULLETDATA_H_
#include <iostream>
#include <string>
class BulletData {
public:
	std::string name;
	struct a{
		float r,g,b;
		a():r(255),g(255),b(255){};
	}shading;
	float rotation;
	struct b{
		float force;
		float timer;
		b():force(0), timer(0){};
	}explosive;
	float weight;
	float speed;
	float powerDrain;
	BulletData():
		name("NotNamingWillCauseErrors"),
		rotation(0),
		weight(0),
		speed(0),
		powerDrain(0)
	{}
	BulletData(const std::string & _name): name(_name){}
};

std::ostream & operator<< (std::ostream & stream, const BulletData & data);
std::istream & operator>> (std::istream & stream, BulletData & data);

#endif /* BULLETDATA_H_ */
