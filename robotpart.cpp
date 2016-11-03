/*

Zackery Gualandi 10/5/2016

*/


 #include <iostream>
 #include <string>
 #include <vector>
 #include "robotpart.h"
 
 using namespace std;

 void robotpart::build_part(string partName, int partNum, double partCost, double partWeight)
 	{
 		// Cost is in US Dollars, weight is in Kg
		 
		name = partName;
 		partNumber = partNum;
 		cost = partCost;
 		weight = partWeight;
	}
	
 void robotpart::set_description(string partDescript)
 	{
 		description = partDescript;
	}

 string robotpart::get_name()
 	{
 		return name;
	}
	
 string robotpart::get_description()
 	{
 		return description;
	}
	
 int robotpart::get_part_number()
 	{
 		return partNumber;
	}
	
 double robotpart::get_cost()
 	{
 		return cost;
	}
	
 double robotpart::get_weight()
 	{
 		return weight;
	}
