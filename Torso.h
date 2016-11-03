/*

Zackery Gualandi 10/5/2016

*/


#ifndef TORSO_H
#define TORSO_H
#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

class Torso : public robotpart
{
	public:
		void Torso::set_compartments(int partCompartments);
		int Torso::get_Compartments();
	protected:
		int batteryCompartments;
};
#endif