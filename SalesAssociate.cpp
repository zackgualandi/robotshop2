/*

Zackery Gualandi 11/21/2016

*/

#include <iostream>
#include <string>
#include <vector>
#include "SalesAssociate.h"

using namespace std;

void SalesAssociate::build_seller(string name, int ID)
{
	employeeName = name;
	idNum = ID;
}

string SalesAssociate::get_name()
{
	return employeeName;
}

int SalesAssociate::get_id()
{
	return idNum;
}