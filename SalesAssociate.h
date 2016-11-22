/*

Zackery Gualandi 11/21/2016

*/


#ifndef SALESASSOCIATE_H
#define SALESASSOCIATE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SalesAssociate
{
	public:
		void build_seller( string name, int ID);
		string get_name();
		int get_id();
	protected:
		string employeeName;
		int idNum;

};
#endif