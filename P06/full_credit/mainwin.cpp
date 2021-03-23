#include "mainwin.h"



Mainwin::Mainwin() {
	 
	 //Set window
	 set_default_size(400, 400);
	 set_title("");
	 
	 //What goes into window
	 Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
	 add(*vbox);
	 
	 //Menu Bar set up
	 Gtk::MenuBar *menu = Gtk::manage(new Gtk::MenuBar);
	 vbox->pack_start(*menu, PACK_SHRINK, 0);
	 
	 //File menu added
	 Gtk::MenuItem *menuItem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	 menu->append(*menuItem_file);
	 Gtk::Menu *fileMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_file->submenu(*fileMenu);
	 
	 //New school add to file menu
	 Gtk::MenuItem *menuItem_new_school = Gtk::mangae(new Gtk::MenuItem("_New School", true));
	 menuItem_new_school->signal_activate().connect([this] {this->on_new_school_click();});
	 fileMenu->append(*menuItem_new_school);
	 
	 //Quit add to file menuItem_file
	 Gtk::MenuItem *menuItem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	 menuItem_quit->signal_activate().connect([this] {this->on_quit_click();});
	 fileMenu->append(*menuItem_quit);
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_school_click() {}

void Mainwin::on_new_student_click() {}

void Mainwin::on_new_parent_click() {}

void Mainwin::on_student_parent_click() {}

void Mainwin::on_quit_click() {}

void Mainwin::show_data() {}

