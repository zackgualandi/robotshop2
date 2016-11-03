/*

Zackery Gualandi 10/5/2016

*/


#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Battery : public robotpart
{
	public:
		void Battery::build_Battery(double partMaxPower); //the max power is in kilowatt hours
		double Battery::get_maxPower();
	protected:
		double maxPower;
};
#endif