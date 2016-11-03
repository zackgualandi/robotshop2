/*

Zackery Gualandi 10/5/2016

*/


#include <iostream>
#include <string>
#include <vector>
#include "RobotModel.h"
#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Locomotor.h"
#include "Torso.h"

using namespace std;

void RobotModel::define_model(string mName, int mNum)
{
	model_name = mName;
	model_number = mNum;
}

void RobotModel::set_description(string mDescription)
{
	model_description = mDescription;
}

void RobotModel::set_price(double mPrice)
{
	model_price = mPrice;
}

void RobotModel::set_weight(double mWeight)
{
	model_weight = mWeight;
}

void RobotModel::build_Arm(string armName, int armNum, double armCost, double armWeight, string armDescript, int armE_Consumption)
{
	model_arm.build_part(armName, armNum, armCost, armWeight);
	model_arm.set_description(armDescript);
	model_arm.set_powerConsumptionRate(armE_Consumption);

}

void RobotModel::build_Battery(string batteryName, int batteryNum, double batteryCost, double batteryWeight, string batteryDescript, double batteryMaxPower)
{
	model_battery.build_part(batteryName, batteryNum, batteryCost, batteryWeight);
	model_battery.set_description(batteryDescript);
	model_battery.build_Battery(batteryMaxPower);
}

void RobotModel::build_Head(string headName, int headNum, double headCost, double headWeight, string headDescript)
{
	model_head.build_part(headName, headNum, headCost, headWeight);
	model_head.set_description(headDescript);
}

void RobotModel::build_Locomotor(string locomotorName, int locomotorNum, double locomotorCost, double locomotorWeight, string locomotorDescript, int locomotorMaxSpeed, int locomotorEnergyConsumption)
{
	model_locomotor.build_part(locomotorName, locomotorNum, locomotorCost, locomotorWeight);
	model_locomotor.set_description(locomotorDescript);
	model_locomotor.build_Locomotor(locomotorMaxSpeed);
	model_locomotor.set_powerConsumptionRate(locomotorEnergyConsumption);
}

void RobotModel::build_Torso(string torsoName, int torsoNum, double torsoCost, double torsoWeight, string torsoDescript, int torsoCompartments)
{
	model_torso.build_part(torsoName, torsoNum, torsoCost, torsoWeight);
	model_torso.set_description(torsoDescript);
	model_torso.set_compartments(torsoCompartments);
}

string RobotModel::get_model_description()
{
	return model_description;
}

string RobotModel::get_model_name()
{
	return model_name;
}

int RobotModel::get_model_number()
{
	return model_number;
}

double RobotModel::get_model_price()
{
	return model_price;
}

double RobotModel::get_model_weight()
{
	return model_weight;
}