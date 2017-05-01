/*
 * TeamStats.cpp
 *
 *  Created on: 20/08/2010
 *      Author: endlessdark
 */

#include "TeamStats.h"

void TeamStats::setPo(int index,int po){
	teamStats[index].po = po;
}
void TeamStats::setSp(int index,int sp){
	teamStats[index].sp = sp;
}
void TeamStats::setDe(int index,int de){
	teamStats[index].de = de;
}
int TeamStats::getPo(int index){
	return teamStats[index].po;
}
int TeamStats::getSp(int index){
	return teamStats[index].sp;
}
int TeamStats::getDe(int index){
	return teamStats[index].de;
}
