/*
 * BulletBank.h
 *
 *  Created on: Aug 29, 2012
 *      Author: dong
 */

#ifndef BULLETBANK_H_
#define BULLETBANK_H_
#include "BulletData.h"
#include <string>
#include <vector>
namespace bb {
void addBullet(const BulletData & bullet);
void removeBullet(const std::string & name);
const BulletData * findBullet(const std::string & name);
BulletData extractData(const std::string & name);
std::vector<std::string> getNames();
}
#endif /* BULLETBANK_H_ */
