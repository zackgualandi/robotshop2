/*

Zackery Gualandi 11/21/2016

*/

#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

void Customer::build_customer(string name, string address, int ID)
{
	customerName = name;
	customerAddress = address;
	customerPhone = ID;
}

string Customer::get_name()
{
	return customerName;
}

string Customer::get_address()
{
	return customerAddress;
}

int Customer::get_phone()
{
	return customerPhone;
}