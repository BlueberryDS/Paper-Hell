/*
 * PatternData.h
 *
 *  Created on: Aug 26, 2012
 *      Author: dong
 */

#ifndef PATTERNDATA_H_
#define PATTERNDATA_H_
#include <set>
#include <iostream>
#include <string>
#include "BulletData/BulletData.h"

struct ShotData{
	float time;
	float angle;
	int cannon;
	const BulletData * bullet;
	bool operator<(const ShotData & comp)const{
		return time < comp.time;
	}
};

class PatternData {
	std::set<ShotData> shots;
	std::set<ShotData>::iterator internal;
public:
	std::string name;
	const ShotData * getShot();//get shot ptr from internal iterator, returns null if fail
	int getNum() const {return shots.size();}//gets num of shots
	void reset(){internal = shots.begin();}//resets internal iterator
	void addShot(float time, float angle, int cannon, const BulletData& bullet);
	void addShot(float time, float angle, int cannon, const std::string & bulletName);
	PatternData():shots(),internal(shots.begin()), name("NotNamingPatternWillCauseError"){}
	~PatternData(){}
};

std::ostream & operator<<(std::ostream & stream, PatternData & data);//must have actual dataobject
std::istream & operator>>(std::istream & stream, PatternData & data);
#endif /* PATTERNDATA_H_ */
