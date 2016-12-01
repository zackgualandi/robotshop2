/*

Zackery Gualandi 10/5/2016

*/

#include <iostream>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include "RobotModel.h"
#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Locomotor.h"
#include "Torso.h"
#include "Customer.h"
#include "SalesAssociate.h"

using namespace std;

//
// Declarations (we'll define later, just need to declare some variables!)
//
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
void create_robot_modelCB(Fl_Widget* w, void* p);
void cancel_robot_modelCB(Fl_Widget* w, void* p);
void create_customerCB(Fl_Widget* w, void* p);
void cancel_customerCB(Fl_Widget* w, void* p);
void create_sales_associateCB(Fl_Widget* w, void* p);
void cancel_sales_associateCB(Fl_Widget* w, void* p);
void menu_browse_robot_modelCB(Fl_Widget* w, void* p);
void leave_robot_model_catalogCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;
class Robot_Model_Dialog;
class Browse_Robot_Model_Dialog;
class Customer_Dialog;
class Sales_Associate_Dialog;
RobotModel test_model;
Arm test_arm;
Battery test_battery;
Head test_head;
Locomotor test_locomotor;
Torso test_torso;
Customer test_customer;
SalesAssociate test_SA;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg; // The dialog of interest!
Robot_Model_Dialog *robot_model_dlg;
Customer_Dialog *customer_dlg;
Sales_Associate_Dialog *sales_associate_dlg;
Browse_Robot_Model_Dialog *browse_robot_model_dlg;
//
// Robot Part dialog
//

class Robot_Part_Dialog 
{
public:
	Robot_Part_Dialog() 
	{
		dialog = new Fl_Window(440, 370, "Robot Part");

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

		rp_other1 = new Fl_Input(120, 160, 210, 25, "Other #1:");
		rp_other1->align(FL_ALIGN_LEFT);

		rp_other2 = new Fl_Input(120, 190, 210, 25, "Other #2:");
		rp_other2->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 220, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 320, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_partCB, 0);

		rp_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
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
	string other1() { return rp_other1->value(); }
	string other2() { return rp_other2->value(); }
	string description() { return rp_description->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_other1;
	Fl_Input *rp_other2;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

//
// Robot Model dialog
//

class Robot_Model_Dialog
{
public:
	Robot_Model_Dialog()
	{
		dialog = new Fl_Window(440, 370, "Robot Model");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 70, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 320, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_modelCB, 0);

		rp_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string model_number() { return rp_model_number->value(); }
	string description() { return rp_description->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_model_number;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

//
// Browse Robot Model dialog
//

class Browse_Robot_Model_Dialog
{
public:
	Browse_Robot_Model_Dialog()
	{
		dialog = new Fl_Window(440, 370, "Robot Model");

		rp_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() 
	{ 
		Fl_Box box(0, 0, 440, 370, "Hey, I mean, Hello, World!");
		dialog->show(); 
	}
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string model_number() { return rp_model_number->value(); }
	string description() { return rp_description->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_model_number;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

//
// Customer Dialog
//

class Customer_Dialog
{
public:
	Customer_Dialog()
	{
		dialog = new Fl_Window(440, 370, "Sales Associate");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_address = new Fl_Input(120, 40, 210, 25, "Address: ");
		rp_address->align(FL_ALIGN_LEFT);

		rp_phone_number = new Fl_Input(120, 70, 210, 25, "Phone Number:");
		rp_phone_number->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 320, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_customerCB, 0);

		rp_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_customerCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string address() { return rp_address->value(); }
	string phone_number() { return rp_phone_number->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_address;
	Fl_Input *rp_phone_number;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

//
// Sales Associate Dialog
//

class Sales_Associate_Dialog
{
public:
	Sales_Associate_Dialog()
	{
		dialog = new Fl_Window(440, 370, "Sales Associate");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_id_number = new Fl_Input(120, 40, 210, 25, "ID Number:");
		rp_id_number->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 320, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_sales_associateCB, 0);

		rp_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_sales_associateCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string id_number() { return rp_id_number->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_id_number;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

//
// Callbacks
//

void CB(Fl_Widget* w, void* p) { } // No action

//
// Robot Part Callbacks
//

void menu_create_robot_partCB(Fl_Widget* w, void* p)
{
	robot_part_dlg->show();
}

void create_robot_partCB(Fl_Widget* w, void* p) 
{
	if (robot_part_dlg->type() == "Arm")
	{
		cout << "### Creating Robot Arm" << endl;
		cout << "Name    : " << robot_part_dlg->name() << endl;
		cout << "Part #  : " << robot_part_dlg->part_number() << endl;
		cout << "Type    : " << robot_part_dlg->type() << endl;
		cout << "Weight  : " << robot_part_dlg->weight() << endl;
		cout << "Cost    : " << robot_part_dlg->cost() << endl;
		cout << "Consumption Rate: " << robot_part_dlg->other1() << endl;
		cout << "Descript: " << robot_part_dlg->description() << endl;
		test_arm.build_part(robot_part_dlg->name(), stoi(robot_part_dlg->part_number()), stod(robot_part_dlg->cost()), stod(robot_part_dlg->weight()));
		test_arm.set_powerConsumptionRate(stoi(robot_part_dlg->other1()));
		test_arm.set_description(robot_part_dlg->description());
	}

	else if (robot_part_dlg->type() == "Battery")
	{
		cout << "### Creating Robot Battery" << endl;
		cout << "Name    : " << robot_part_dlg->name() << endl;
		cout << "Part #  : " << robot_part_dlg->part_number() << endl;
		cout << "Type    : " << robot_part_dlg->type() << endl;
		cout << "Weight  : " << robot_part_dlg->weight() << endl;
		cout << "Cost    : " << robot_part_dlg->cost() << endl;
		cout << "Max Power: " << robot_part_dlg->other1() << endl;
		cout << "Descript: " << robot_part_dlg->description() << endl;
		test_battery.build_part(robot_part_dlg->name(), stoi(robot_part_dlg->part_number()), stod(robot_part_dlg->cost()), stod(robot_part_dlg->weight()));
		test_battery.build_Battery(stoi(robot_part_dlg->other1()));
		test_battery.set_description(robot_part_dlg->description());
	}

	else if (robot_part_dlg->type() == "Head")
	{
		cout << "### Creating Robot Head" << endl;
		cout << "Name    : " << robot_part_dlg->name() << endl;
		cout << "Part #  : " << robot_part_dlg->part_number() << endl;
		cout << "Type    : " << robot_part_dlg->type() << endl;
		cout << "Weight  : " << robot_part_dlg->weight() << endl;
		cout << "Cost    : " << robot_part_dlg->cost() << endl;
		cout << "Descript: " << robot_part_dlg->description() << endl;
		test_head.build_part(robot_part_dlg->name(), stoi(robot_part_dlg->part_number()), stod(robot_part_dlg->cost()), stod(robot_part_dlg->weight()));
		test_head.set_description(robot_part_dlg->description());
	}

	else if (robot_part_dlg->type() == "Locomotor")
	{
		cout << "### Creating Robot Locomotor" << endl;
		cout << "Name    : " << robot_part_dlg->name() << endl;
		cout << "Part #  : " << robot_part_dlg->part_number() << endl;
		cout << "Type    : " << robot_part_dlg->type() << endl;
		cout << "Weight  : " << robot_part_dlg->weight() << endl;
		cout << "Cost    : " << robot_part_dlg->cost() << endl;
		cout << "Max Speed: " << robot_part_dlg->other1() << endl;
		cout << "Consumption Rate: " << robot_part_dlg->other2() << endl;
		cout << "Descript: " << robot_part_dlg->description() << endl;
		test_locomotor.build_part(robot_part_dlg->name(), stoi(robot_part_dlg->part_number()), stod(robot_part_dlg->cost()), stod(robot_part_dlg->weight()));
		test_locomotor.build_Locomotor(stoi(robot_part_dlg->other1()));
		test_locomotor.set_powerConsumptionRate(stoi(robot_part_dlg->other2()));
		test_locomotor.set_description(robot_part_dlg->description());
	}

	else if (robot_part_dlg->type() == "Torso")
	{
		cout << "### Creating Robot Torso" << endl;
		cout << "Name    : " << robot_part_dlg->name() << endl;
		cout << "Part #  : " << robot_part_dlg->part_number() << endl;
		cout << "Type    : " << robot_part_dlg->type() << endl;
		cout << "Weight  : " << robot_part_dlg->weight() << endl;
		cout << "Cost    : " << robot_part_dlg->cost() << endl;
		cout << "Battery Compartments: " << robot_part_dlg->other1() << endl;
		cout << "Descript: " << robot_part_dlg->description() << endl;
		test_torso.build_part(robot_part_dlg->name(), stoi(robot_part_dlg->part_number()), stod(robot_part_dlg->cost()), stod(robot_part_dlg->weight()));
		test_torso.set_compartments(stoi(robot_part_dlg->other1()));
		test_torso.set_description(robot_part_dlg->description());
	}

	robot_part_dlg->hide();
}

void cancel_robot_partCB(Fl_Widget* w, void* p) 
{
	robot_part_dlg->hide();
}

//
// Robot Model Callbacks
//

void menu_create_robot_modelCB(Fl_Widget* w, void* p)
{
	robot_model_dlg->show();
}

void create_robot_modelCB(Fl_Widget* w, void* p)
{
	double totalCost, armCost = test_arm.get_cost(), batteryCost = test_battery.get_cost(), 
		headCost = test_head.get_cost(), locomotorCost = test_locomotor.get_weight(), torsoCost = test_torso.get_cost();

	int tCompartments = test_torso.get_Compartments();

	double totalWeight, armWeight = test_arm.get_weight(), batteryWeight = test_battery.get_weight(), 
		headWeight = test_head.get_weight(), locomotorWeight = test_locomotor.get_weight(), torsoWeight = test_torso.get_weight();

	cout << "### Creating Robot Model" << endl;
	cout << "Name    : " << robot_model_dlg->name() << endl;
	cout << "Model # : " << robot_model_dlg->model_number() << endl;
	test_model.model_arm = test_arm;
	cout << "Arm     : " << test_arm.get_name() << endl;
	test_model.model_battery = test_battery;
	cout << "Battery : " << test_battery.get_name() << endl;
	test_model.model_head = test_head;
	cout << "Head    : " << test_head.get_name() << endl;
	test_model.model_locomotor = test_locomotor;
	cout << "Locomotor: " << test_locomotor.get_name() << endl;
	test_model.model_torso = test_torso;
	cout << "Torso   : " << test_torso.get_name() << endl;
	totalCost = (armCost * 2) + (batteryCost * tCompartments) + locomotorCost
		+ headCost + torsoCost;
	test_model.set_price(totalCost);
	cout << "Total Cost: " << test_model.get_model_price() << endl;
	totalWeight = (armWeight * 2) + (batteryWeight * tCompartments) + locomotorWeight
		+ headWeight + torsoWeight;
	test_model.set_weight(totalWeight);
	cout << "Total Weight: " << test_model.get_model_weight() << endl;
	robot_model_dlg->hide();
}

void cancel_robot_modelCB(Fl_Widget* w, void* p)
{
	robot_model_dlg->hide();
}

//
// Customer Callbacks
//

void menu_create_customerCB(Fl_Widget* w, void* p)
{
	customer_dlg->show();
}

void create_customerCB(Fl_Widget* w, void* p)
{
	cout << "### Creating Customer" << endl;
	cout << "Name    : " << customer_dlg->name() << endl;
	cout << "Address : " << customer_dlg->address() << endl;
	cout << "Phone # : " << customer_dlg->phone_number() << endl;
	test_customer.build_customer(customer_dlg->name(), customer_dlg->address(), stoi(customer_dlg->phone_number()));
	customer_dlg->hide();
}

void cancel_customerCB(Fl_Widget* w, void* p)
{
	customer_dlg->hide();
}

//
// Sales Associates Callbacks
//

void menu_sales_associateCB(Fl_Widget* w, void* p)
{
	sales_associate_dlg->show();
}

void create_sales_associateCB(Fl_Widget* w, void* p)
{
	cout << "### Creating Sales Associate" << endl;
	cout << "Name    : " << sales_associate_dlg->name() << endl;
	cout << "ID #    : " << sales_associate_dlg->id_number() << endl;
	test_SA.build_seller(sales_associate_dlg->name(), stoi(sales_associate_dlg->id_number()));
	sales_associate_dlg->hide();
}

void cancel_sales_associateCB(Fl_Widget* w, void* p)
{
	sales_associate_dlg->hide();
}

//
// Browse Robot Model Callbacks
//

void menu_browse_robot_modelCB(Fl_Widget* w, void* p)
{
	browse_robot_model_dlg->show();
}

void leave_robot_model_catalogCB(Fl_Widget* w, void* p)
{
	browse_robot_model_dlg->hide();
}

//
// Menu
//

Fl_Menu_Item menuitems[] = 
{
	{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)menu_create_customerCB },
	{ "Sales Associate", 0, (Fl_Callback *)menu_sales_associateCB, 0, FL_MENU_DIVIDER },
	{ "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
	{ "Robot Model", 0, (Fl_Callback *)menu_create_robot_modelCB },
	{ 0 },
	{ "&Browse", 0, 0, 0, FL_SUBMENU },
	{ "All Customers", 0, (Fl_Callback *)CB },
	{ "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "All Robot Models", 0, (Fl_Callback *)menu_browse_robot_modelCB },
	{ "All Robot Parts", 0, (Fl_Callback *)CB },
	{ 0 },
	{ "&Help", 0, 0, 0, FL_SUBMENU },
	{ "&Manual", 0, (Fl_Callback *)CB },
	{ "&About", 0, (Fl_Callback *)CB },
	{ 0 },
	{ 0 }
};

//
// Main
//

int main() 
{
	const int X = 720;
	const int Y = 440;

	// Create dialogs
	robot_part_dlg = new Robot_Part_Dialog{};
	robot_model_dlg = new Robot_Model_Dialog{};
	customer_dlg = new Customer_Dialog{};
	sales_associate_dlg = new Sales_Associate_Dialog{};
	browse_robot_model_dlg = new Browse_Robot_Model_Dialog{};

	// Create a window
	win = new Fl_Window{ X, Y, "Robbie Robot Shop Manager" };
	win->color(FL_WHITE);

	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);

	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}
