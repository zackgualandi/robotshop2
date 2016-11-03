/*

Zackery Gualandi 10/5/2016

*/


#ifndef ROBOTMODEL_H
#define ROBOTMODEL_H
#include <iostream>
#include <string>
#include <vector>
#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Locomotor.h"
#include "Torso.h"

class RobotModel : public Arm, public Battery, public Head, public Locomotor, public Torso
{
	public:
		Arm model_arm;
		Battery model_battery;
		Head model_head;
		Locomotor model_locomotor;
		Torso model_torso;
		void RobotModel::define_model(string mName, int mNum);
		void RobotModel::set_description(string mDescription);
		void RobotModel::set_price(double mPrice);
		void RobotModel::set_weight(double mWeight);
		void RobotModel::build_Arm(string armName, int armNum, double armCost, double armWeight, string armDescript, int armE_Consumption);
		void RobotModel::build_Battery(string batteryName, int batteryNum, double batteryCost, double batteryWeight, string batteryDescript, double batteryMaxPower);
		void RobotModel::build_Head(string headName, int headNum, double headCost, double headWeight, string headDescript);
		void RobotModel::build_Locomotor(string locomotorName, int locomotorNum, double locomotorCost, double locomotorWeight, string locomotorDescript, int locomotorMaxSpeed, int locomotorEnergyConsumption);
		void RobotModel::build_Torso(string torsoName, int torsoNum, double torsoCost, double torsoWeight, string torsoDescript, int torsoCompartments);
		string RobotModel::get_model_description();
		string RobotModel::get_model_name();
		int RobotModel::get_model_number();
		double RobotModel::get_model_price();
		double RobotModel::get_model_weight();
	protected:
		string model_name;
		string model_description;
		int model_number;
		double model_price;
		double model_weight;
};
#endif