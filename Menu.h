/*

Zackery Gualandi 10/5/2016

*/


#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include "RobotModel.h"
#include "Menu_Helper.h"
const int maxModels = 5; // sets the maximun number of robots to sell.

class Menu : public RobotModel
{
	public:
		Menu()
		{
			dialog = new Fl_Window(340, 270, "Robot Part");

			rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
			rp_name->align(FL_ALIGN_LEFT);

			rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
			rp_part_number->align(FL_ALIGN_LEFT);

			rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
			rp_type->align(FL_ALIGN_LEFT);

			rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
			rp_weight->align(FL_ALIGN_LEFT);

			rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
			rp_cost->align(FL_ALIGN_LEFT);

			rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
			rp_description->align(FL_ALIGN_LEFT);

			rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
			rp_create->callback((Fl_Callback *)create_robot_partCB, 0);

			rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
			rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);

			dialog->end();
			dialog->set_non_modal();
		}
		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		string name() { return rp_name->value(); }
		string part_number() { return rp_part_number->value(); }
		string type() { return rp_type->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		Fl_Window *win;
		Fl_Menu_Bar *menubar;
		Menu *robot_part_dlg;
	private:
		RobotModel ourModels[maxModels];
		Fl_Window *dialog;
		Fl_Input *rp_name;
		Fl_Input *rp_part_number;
		Fl_Input *rp_type;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;
};
#endif
