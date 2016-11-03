/*

Zackery Gualandi 10/5/2016

*/


#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<FL/Fl_Window.H>
#include "RobotModel.h"
const int maxModels = 5; // sets the maximun number of robots to sell.

class Menu : public RobotModel
{
	public:
		void Menu::openMainMenu();
		void Menu::openCreateMenu();
		void Menu::openBrowseMenu();
		void Menu::openOrderMenu();
		void Menu::displayRobotModel(RobotModel selectedModel);
		void Menu::buildRobotModel(RobotModel selectedModel);
		void Menu::orderRobotModel(RobotModel selectedModel);
	private:
		RobotModel ourModels[maxModels];
};
#endif
