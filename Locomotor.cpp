/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Locomotor.h"

using namespace std;

void Locomotor::build_Locomotor(int partMaxSpeed)
{
	maxSpeed = partMaxSpeed;
}

void Locomotor::set_powerConsumptionRate(int partEnergyConsumption)
{
	consumptionRate = partEnergyConsumption;
}

int Locomotor::get_maxSpeed()
{
	return maxSpeed;
}

int Locomotor::get_consumtionRate()
{
	return consumptionRate;
}

int Locomotor::power_consumed(int currentSpeed)
{
	return (currentSpeed * consumptionRate);
}