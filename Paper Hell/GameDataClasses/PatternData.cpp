/*
 * PatternData.cpp
 *
 *  Created on: Aug 26, 2012
 *      Author: dong
 */

#include "PatternData.h"
#include "BulletData/BulletBank.h"
using namespace std;

const ShotData * PatternData::getShot(){
	if (internal  == shots.end()) return NULL;
	else {
		return const_cast<ShotData*>(&(*(internal++)));//justifiable
	}
}


void PatternData::addShot(float time, float angle, int cannon, const BulletData& bullet){
	ShotData shot;
	shot.angle=angle;
	shot.cannon=cannon;
	shot.time=time;
	shot.bullet=&bullet;
	shots.insert(--shots.end(),shot);
}
void PatternData::addShot(float time, float angle, int cannon, const std::string & bulletName){
	ShotData shot;
	shot.angle=angle;
	shot.cannon=cannon;
	shot.time=time;
	shot.bullet=bb::findBullet(bulletName);
	shots.insert(--shots.end(),shot);
}

ostream & operator<<(ostream & stream, PatternData & data){
	stream << "Pattern[" << data.name << ']' <<'\n';
	stream << "Size: "<< data.getNum()<<'\n';
	const ShotData * shot = data.getShot();
	while (shot == NULL){
		stream  <<'\n'<<"Time: "<< shot->time <<'\n';
		stream <<"Angle: "<< shot->angle <<'\n';
		stream <<"Cannon: "<< shot->cannon <<'\n';
		stream <<"Bullet["<< shot->bullet->name << ']';
		shot = data.getShot();
	}
	return stream;
}
istream & operator>>(istream & stream, PatternData & data){
	int size;
	stream.ignore(1000,'[');//Pattern[]
	std::getline(stream,data.name,']');
	stream.ignore(1000,':');//Size:
	stream>>size;
	for (int i = 0; i<size; i++){
		float time, angle;
		int cannon;
		std::string bulletName;
		stream.ignore(1000,':');//Time:
		stream >> time;
		stream.ignore(1000,':');//Angle:
		stream >> angle;
		stream.ignore(1000,':');//Cannon:
		stream >>cannon;
		stream.ignore(1000,'[');//Bullet[
		std::getline(stream,bulletName,']');
		data.addShot(time,angle,cannon,bulletName);
	}
	return stream;
}
