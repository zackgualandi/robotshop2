/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "Torso.h"

using namespace std;

void Torso::set_compartments(int partCompartments)
{
	batteryCompartments = partCompartments;
}

int Torso::get_Compartments()
{
	return batteryCompartments;
}