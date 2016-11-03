/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Arm.h"

using namespace std;

void Arm::set_powerConsumptionRate(int partEnergyConsumption)
{
	consumptionRate = partEnergyConsumption;
}

int Arm::get_consumtionRate()
{
	return consumptionRate;
}

int Arm::power_consumed(int currentSpeed)
{
	return (currentSpeed * consumptionRate);
}