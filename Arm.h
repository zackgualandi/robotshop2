/*

Zackery Gualandi 10/5/2016

*/


#ifndef ARM_H
#define ARM_H
#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Arm : public robotpart
{
	public:
		void Arm::set_powerConsumptionRate(int partEnergyConsumption);
		int Arm::get_consumtionRate();
		int Arm::power_consumed(int currentSpeed);
	protected:
		int consumptionRate;
};
#endif