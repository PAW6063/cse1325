#include "mainwin.h"



Mainwin::Mainwin() {
	 
	 //Set window
	 set_default_size(400, 400);
	 set_title("SMART");
	 
	 //What goes into window
	 Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
	 add(*vbox);
	 
	 //Menu Bar set up
	 Gtk::MenuBar *menu = Gtk::manage(new Gtk::MenuBar);
	 vbox->pack_start(*menu, Gtk::PACK_SHRINK, 0);
	 
	 //FILE
	 //File menu added
	 Gtk::MenuItem *menuItem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	 menu->append(*menuItem_file);
	 Gtk::Menu *fileMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_file->set_submenu(*fileMenu);
	 
	 //New school add to file menu
	 Gtk::MenuItem *menuItem_new_school = Gtk::manage(new Gtk::MenuItem("_New School", true));
	 menuItem_new_school->signal_activate().connect([this] {this->on_new_school_click();});
	 fileMenu->append(*menuItem_new_school);
	 
	 //Quit add to file menuItem_file
	 Gtk::MenuItem *menuItem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	 menuItem_quit->signal_activate().connect([this] {this->on_quit_click();});
	 fileMenu->append(*menuItem_quit);
	 
	 //INSERT
	 //Insert
	 Gtk::MenuItem *menuItem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	 menu->append(*menuItem_insert);
	 Gtk::Menu *insertMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_insert->set_submenu(*insertMenu);
	 
	 //New Student
	 Gtk::MenuItem *menuItem_new_student = Gtk::manage(new Gtk::MenuItem("_New Student", true));
	 menuItem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
	 insertMenu->append(*menuItem_new_student);
	 
	 //New Parent
	 Gtk::MenuItem *menuItem_new_parent = Gtk::manage(new Gtk::MenuItem("_New Parent", true));
	 menuItem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
	 insertMenu->append(*menuItem_new_parent);
	 
	 //RELATE
	 //Relate
	 Gtk::MenuItem *menuItem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
	 menu->append(*menuItem_relate);
	 Gtk::Menu *relateMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_relate->set_submenu(*relateMenu);
	 
	 //Student to Parents
	 Gtk::MenuItem *menuItem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
	 menuItem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
	 relateMenu->append(*menuItem_student_parent);
	 
	 //DISPLAY
	 display = Gtk::manage(new Gtk::Label());
	 display->set_hexpand(true);
	 display->set_vexpand(true);
	 vbox->add(*display);
	 
	 //Showing everything
	 vbox->show_all();
	 
	 show_data();
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_school_click() {
	
	students.clear();
	parents.clear();
	
	show_data();
}

void Mainwin::on_new_student_click() {
	
	EntryDialog entry_name{*this, "<big><b>Student name?</b></big>", true}; entry_name.set_text("Enter name!"); entry_name.run();
	EntryDialog entry_email{*this, "<big><b>Student email?</b></big>", true}; entry_email.set_text("Enter email!"); entry_email.run();
	EntryDialog entry_grade{*this, "<big><b>Student grade?</b></big>", true}; entry_grade.set_text("Enter grade number!"); entry_grade.run();
	
	std::stringstream grade;
	int g;
	grade << entry_grade.get_text().raw();
	grade >> g;
	
	students.push_back(new Student{entry_name.get_text(), entry_email.get_text(), g});
	
	show_data();
}

void Mainwin::on_new_parent_click() {
	
	EntryDialog entry_name{*this, "<big><b>Parent name?</b></big>", true}; entry_name.set_text("Enter name!"); entry_name.run();
	EntryDialog entry_email{*this, "<big><b>Parent email?</b></big>", true}; entry_email.set_text("Enter email!"); entry_email.run();
	
	parents.push_back(new Parent{entry_name.get_text(), entry_email.get_text()});
	
	show_data();
}

void Mainwin::on_student_parent_click() {
	EntryDialog student{*this, "<big><b>Select Student</b></big>", true};
	
	std::string s_string = "";
	for(int i = 0; i < students.size(); i++) {
		s_string += std::to_string(i) + ")" + students[i]->Person::full_info() + "\n";
	}
	student.set_secondary_text(s_string, false);
	student.set_text("#");
	student.run();
	int s = std::stoi( student.get_text() );
	
	EntryDialog parent{*this, "<big><b>Select Parent</b></big>", true};
	
	std::string p_string = "";
	for(int i = 0; i < parents.size(); i++) {
		p_string += std::to_string(i) + ")" + parents[i]->Person::full_info() + "\n";
	}
	
	parent.set_secondary_text(p_string, false);
	parent.set_text("#");
	parent.run();
	int p = std::stoi( parent.get_text() );
	
	students[s]->add_parent(*parents[p]);
	parents[p]->add_student(*students[s]);
	
	show_data();
}

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::show_data() {
	Glib::ustring data = "";
	
	data += "\tStudents\n\n";
	if(students.size() >= 0) {
		for(auto & i : students) {
		    data += i->full_info();
			data += "\n";
		}
	}
	
	data += "\n\tParents\n\n";
	if(parents.size() >= 0) {
		for(auto & i : parents) {
			data += i->full_info();
			data += "\n";
		}
	}
	
	display->set_markup(data);
}
















