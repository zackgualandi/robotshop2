/*

Zackery Gualandi 11/21/2016

*/


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
public:
	void build_customer(string name, string address, int phone);
	string get_name();
	string get_address();
	int get_phone();
protected:
	string customerName;
	string customerAddress;
	int customerPhone;

};
#endif