/*

Zackery Gualandi 10/5/2016

*/


#ifndef ROBOTPART_H
#define ROBOTPART_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
class robotpart 
{
	public:
		void build_part(string partName, int partNum, double partCost, double partWeight);
		void set_description(string partDescript);
		string get_name();
		string get_description();
		int get_part_number();
		double get_cost();
		double get_weight();
		
	protected:
		string name;
		string description;
		int partNumber;
		double cost;
		double weight;
};
#endif