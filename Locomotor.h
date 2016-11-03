/*

Zackery Gualandi 10/5/2016

*/


#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H
#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Locomotor : public robotpart
{
	public:
		void Locomotor::build_Locomotor(int partMaxSpeed);
		void Locomotor::set_powerConsumptionRate(int partEnergyConsumption);
		int Locomotor::get_maxSpeed();
		int Locomotor::get_consumtionRate();
		int Locomotor::power_consumed(int currentSpeed);
	protected:
		int maxSpeed;
		int consumptionRate;

};
#endif