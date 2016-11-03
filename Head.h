/*

Zackery Gualandi 10/5/2016

*/


#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <string>
#include <vector>
#include "robotpart.h"

using namespace std;

class Head: public robotpart
{
	// head is an empty class as it does not require additional data compared to robot parts, but making the head class simplifies the robot model class.
};
#endif