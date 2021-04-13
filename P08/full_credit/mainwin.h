#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>

#include "entrydialog.h"
#include "parent.h"
#include "student.h"

class Mainwin : public Gtk::Window {
public :
	Mainwin();
	~Mainwin();
	
protected :
	void on_new_school_click();
	void on_new_student_click();
	void on_new_parent_click();
	void on_student_parent_click();
	void on_quit_click();
	//Added methods for sprint 3
	void on_save_click();
	void on_save_as_click();
	void on_open_click();
	void on_about_click();
	
private :
	Gtk::Label *display;
	std::vector <Student*> students;
	std::vector <Parent*> parents;
	//Added Attribute for sprint 3
	std::string filename;
	
	void show_data();
};

#endif
