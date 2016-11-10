/*

Zackery Gualandi 11/9/2016

*/

#ifndef MENU_HELPER_H
#define MENU_HELPER_H
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

class Menu_Helper
{
	void create_robot_partCB(Fl_Widget* w, void* p);
	void cancel_robot_partCB(Fl_Widget* w, void* p);
};

#endif