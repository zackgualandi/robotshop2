/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Battery.h"

using namespace std;

void Battery::build_Battery(double partMaxPower)
{
	maxPower = partMaxPower;
}

double Battery::get_maxPower()
{
	return maxPower;
}