#include "mainwin.h"

#define STUDENT_SIZE 500
#define PARENT_SIZE 300



Mainwin::Mainwin() {
	 
	 //Default file name
	 filename = "untitled.smart";
	 
	 //Set window
	 set_default_size(600, 400);
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
	 
	 //FILE Added with sprint 3
	 
	 //Open
	 Gtk::MenuItem *menuItem_Open = Gtk::manage(new Gtk::MenuItem("_Open", true));
	 menuItem_Open->signal_activate().connect([this] {this->on_open_click();});
	 fileMenu->append(*menuItem_Open);
	 
	 //Save
	 Gtk::MenuItem *menuItem_Save = Gtk::manage(new Gtk::MenuItem("_Save", true));
	 menuItem_Save->signal_activate().connect([this] {this->on_save_click();});
	 fileMenu->append(*menuItem_Save);
	 
	 //Save As
	 Gtk::MenuItem *menuItem_Save_As = Gtk::manage(new Gtk::MenuItem("_Save As", true));
	 menuItem_Save_As->signal_activate().connect([this] {this->on_save_as_click();});
	 fileMenu->append(*menuItem_Save_As);
	 	 
	 //Ended sprint 3 additions
	 
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
	 
	 //New Course
	 Gtk::MenuItem *menuItem_course = Gtk::manage(new Gtk::MenuItem("_New Course", true));
	 menuItem_course->signal_activate().connect([this] {this->on_new_course_click();});
	 insertMenu->append(*menuItem_course);
	 
	 //New Section
	 Gtk::MenuItem *menuItem_section = Gtk::manage(new Gtk::MenuItem("_New Section", true));
	 menuItem_section->signal_activate().connect([this] {this->on_new_section_click();});
	 insertMenu->append(*menuItem_section);
	 
	 //VIEW
	 //View
	 Gtk::MenuItem *menuItem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	 menu->append(*menuItem_view);
	 Gtk::Menu *viewMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_view->set_submenu(*viewMenu);
	 
	 //View Students
	 Gtk::MenuItem *menuItem_view_students = Gtk::manage(new Gtk::MenuItem("_View Students", true));
	 menuItem_view_students->signal_activate().connect([this] {this->on_view_students_click();});
	 viewMenu->append(*menuItem_view_students);
	 
	 //View Parents
	 Gtk::MenuItem *menuItem_view_parents = Gtk::manage(new Gtk::MenuItem("_View Parents", true));
	 menuItem_view_parents->signal_activate().connect([this] {this->on_view_parents_click();});
	 viewMenu->append(*menuItem_view_parents);
	 
	 //View Course
	 Gtk::MenuItem *menuItem_view_courses = Gtk::manage(new Gtk::MenuItem("_View Courses", true));
	 menuItem_view_courses->signal_activate().connect([this] {this->on_view_courses_click();});
	 viewMenu->append(*menuItem_view_courses);
	 
	 //View Sections
	 Gtk::MenuItem *menuItem_view_sections = Gtk::manage(new Gtk::MenuItem("_View Sections", true));
	 menuItem_view_sections->signal_activate().connect([this] {this->on_view_sections_click();});
	 viewMenu->append(*menuItem_view_sections);
	 
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

	 //HELP
	 //Help
	 Gtk::MenuItem *menuItem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	 menu->append(*menuItem_help);
	 Gtk::Menu *aboutMenu = Gtk::manage(new Gtk::Menu());
	 menuItem_help->set_submenu(*aboutMenu);
	 
	 //About
	 Gtk::MenuItem *menuItem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	 menuItem_about->signal_activate().connect([this] {this->on_about_click();});
	 aboutMenu->append(*menuItem_about);
	 
	 //TOOLBAR HERE
	 //Toolbar build
	 Gtk::Toolbar *tools = Gtk::manage(new Gtk::Toolbar);
	 vbox->pack_start(*tools, Gtk::PACK_SHRINK, 0);
	 
	 //New School button
	 Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
	 new_school_button->set_tooltip_markup("Deletes current school and starts another.");
	 new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
	 tools->append(*new_school_button);
	 
	 //Open button
	 Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
	 open_button->set_tooltip_markup("FilerFinder to open existing file.");
	 open_button->signal_clicked().connect([this] {this->on_open_click();});
	 tools->append(*open_button);
	 
 	 //Save Button
 	 Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
	 save_button->set_tooltip_markup("Quick Save.");
	 save_button->signal_clicked().connect([this] {this->on_save_click();});
	 tools->append(*save_button);
	 
	 //Save As Button
	 Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
	 save_as_button->set_tooltip_markup("Save and name file.");
	 save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
	 tools->append(*save_as_button);
	 
	 //Separator
	 Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
	 tools->append(*sep);
	 
	 //Insert Student
	 Gtk::Image *add_s_image = Gtk::manage(new Gtk::Image{"plus_s.png"});
	 Gtk::ToolButton *insert_student_button = Gtk::manage(new Gtk::ToolButton(*add_s_image));
	 insert_student_button->set_tooltip_markup("Add new student.");
	 insert_student_button->signal_clicked().connect([this] {this->on_new_student_click();});
	 tools->append(*insert_student_button);
	 
	 //Insert Parents
	 Gtk::Image *add_p_image = Gtk::manage(new Gtk::Image{"plus_p.png"});
	 Gtk::ToolButton *insert_parent_button = Gtk::manage(new Gtk::ToolButton(*add_p_image));
	 insert_parent_button->set_tooltip_markup("Add new parent.");
	 insert_parent_button->signal_clicked().connect([this] {this->on_new_parent_click();});
	 tools->append(*insert_parent_button);
	 
	 //Relate Button
 	 Gtk::Image *relate_image = Gtk::manage(new Gtk::Image{"relate.png"});
	 Gtk::ToolButton *relate_button = Gtk::manage(new Gtk::ToolButton(*relate_image));
	 relate_button->set_tooltip_markup("Link student and parent.");
	 relate_button->signal_clicked().connect([this] {this->on_student_parent_click();});
	 tools->append(*relate_button);
	 
	 //Separator
	 Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
	 tools->append(*sep2);
	 
	 //New COurse
	 Gtk::Image *new_course_image = Gtk::manage(new Gtk::Image{"add_c.png"});
	 Gtk::ToolButton *new_course_button = Gtk::manage(new Gtk::ToolButton(*new_course_image));
	 new_course_button->set_tooltip_markup("Add new course.");
	 new_course_button->signal_clicked().connect([this] {this->on_new_course_click();});
	 tools->append(*new_course_button);
	 
	 //New Section
	 Gtk::Image *new_section_image = Gtk::manage(new Gtk::Image{"add_s.png"});
	 Gtk::ToolButton *new_section_button = Gtk::manage(new Gtk::ToolButton(*new_section_image));
	 new_section_button->set_tooltip_markup("Add new section.");
	 new_section_button->signal_clicked().connect([this] {this->on_new_section_click();});
	 tools->append(*new_section_button);
	  
	 //DISPLAY
	 display = Gtk::manage(new Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START});
	 display->set_hexpand(true);
	 display->set_vexpand(true);
	 vbox->add(*display);
	 
	 //Showing everything
	 vbox->show_all();
	 
	 on_view_students_click();
}

Mainwin::~Mainwin() {}

void Mainwin::on_new_school_click() {
	
	students.clear();
	parents.clear();
	_courses.clear();
	_sections.clear();
	
	on_view_students_click();
}

void Mainwin::on_new_student_click() {
	

	Gtk::Dialog dialog{"Student Info", *this};
	Gtk::Grid plot;
	
	Gtk::Label l_name{"Enter Name"};
	Gtk::Entry e_name;
	
	plot.attach(l_name, 0, 0, 1, 1);
	plot.attach(e_name, 1, 0, 2, 1);
	
	Gtk::Label l_email{"Enter Email"};
	Gtk::Entry e_email;
	
	plot.attach(l_email, 0, 1, 1, 1);
	plot.attach(e_email, 1, 1, 2, 1);
	
	Gtk::Label l_grade;
	Gtk::SpinButton s_b_grade;
	
	s_b_grade.set_range(1, 12);
	s_b_grade.set_increments(1, 1);
	s_b_grade.set_value(1);
	
	plot.attach(l_grade, 0, 2, 1, 1);
	plot.attach(s_b_grade, 1, 2, 2, 1);
	
	dialog.get_content_area()->pack_start(plot);
	
	dialog.add_button("Select", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	
	dialog.show_all();
	int response;
	if((response = dialog.run()) == Gtk::RESPONSE_OK) {
		students.push_back( new Student{ e_name.get_text(), e_email.get_text(), s_b_grade.get_value_as_int() } );
	}
	
	on_view_students_click();
}

void Mainwin::on_new_parent_click() {
	
	Gtk::Dialog dialog{"Parent Info", *this};
	Gtk::Grid plot;
	
	Gtk::Label l_name{"Enter Name"};
	Gtk::Entry e_name;
	
	plot.attach(l_name, 0, 0, 1, 1);
	plot.attach(e_name, 1, 0, 2, 1);
	
	Gtk::Label l_email{"Enter Email"};
	Gtk::Entry e_email;
	
	plot.attach(l_email, 0, 1, 1, 1);
	plot.attach(e_email, 1, 1, 2, 1);
	
	dialog.get_content_area()->pack_start(plot);
	
	dialog.add_button("Select", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	
	dialog.show_all();
	int response;
	if((response = dialog.run()) == Gtk::RESPONSE_OK) {
		parents.push_back( new Parent{ e_name.get_text(), e_email.get_text() } );
	}
	
	on_view_parents_click();
}

void Mainwin::on_new_course_click() {
	
	CourseDialog dialog{"Create Course", *this};
	
	int response;
	if((response = dialog.run()) == Gtk::RESPONSE_OK) {
		_courses.push_back( new Course{ dialog.get_subject(), dialog.get_grade() } );
	}
	
	on_view_courses_click();
}

void Mainwin::on_new_section_click() { 
	
	if(_courses.size() >= 1) {
		Gtk::Dialog dialog{"Create Section", *this};
		Gtk::Grid plot;
		
		Gtk::Label l_course{"Select Course"};
		Gtk::ComboBoxText c_course;
		
		for(int i = 0; i < _courses.size(); i++) {
			c_course.append(_courses[i]->course_print());
		}
		
		c_course.set_active(0);
		
		plot.attach(l_course, 0, 0, 1, 1);
		plot.attach(c_course, 1, 0, 2, 1);
		
		Gtk::Label l_semester{"Select Semester"};
		Gtk::ComboBoxText c_semester;
		
		for(int i = 0; i < 4; i++) {
			c_semester.append(to_string(semester_list(i)));
		}
		
		c_semester.set_active(3);
		
		plot.attach(l_semester, 0, 1, 1, 1);
		plot.attach(c_semester, 1, 1, 2, 1);
		
		Gtk::Label l_year;
		Gtk::SpinButton s_b_year;
		
		s_b_year.set_range(2000, 2100);
		s_b_year.set_increments(1, 5);
		s_b_year.set_value(2021);
		
		plot.attach(l_year, 0, 2, 1, 1);
		plot.attach(s_b_year, 1, 2, 2, 1);
		
		dialog.get_content_area()->pack_start(plot);
		
		dialog.add_button("Select", Gtk::RESPONSE_OK);
		dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
		
		dialog.show_all();
		int response;
		if((response = dialog.run()) == Gtk::RESPONSE_OK) {
			_sections.push_back( new Section{ *_courses[c_course.get_active_row_number()], semester_list(c_semester.get_active_row_number()), s_b_year.get_value_as_int() } );
		}
	} else { 
		Gtk::MessageDialog error{ *this, "No Courses Available"};
		error.run();
	}
	on_view_sections_click();
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
	
	//*************************************
	// THIS IS WHERE I THINK THE PRBLEM IS
	//*************************************
	students[s]->add_parent(*parents[p]);
	parents[p]->add_student(*students[s]);
	
	on_view_students_click();
	
	
}

void Mainwin::on_view_students_click() {
	std::string data = "";
	
	data += "<big><b>Students:</b></big>\n";
	if(students.size() > 0) {
		for(auto & i : students) {
		    data += i->full_info() + "\n";
		}
	}
	show_data(data);
}

void Mainwin::on_view_parents_click() {
	std::string data = "";
	
	data += "<big><b>Parents:</b></big>\n";
	if(parents.size() > 0) {
		for(auto & i : parents) {
			data += i->full_info() + "\n";
		}
	}
	show_data(data);
}
 
void Mainwin::on_view_courses_click() {
	std::string data = "";
	
	data += "<big><b>Courses:</b></big>\n";
	if(_courses.size() > 0) {
		for(auto & i : _courses) {
		    data += i->course_print() + '\n';
		}
	}
	show_data(data);
}
 
void Mainwin::on_view_sections_click() {
	std::string data = "";
	
	data += "<big><b>Sections:</b></big>\n";
	if(_sections.size() > 0) {
		for(auto & i : _sections) {
		    data += i->section_print() + '\n';
		}
	}
	show_data(data);}

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::show_data(std::string data) { display->set_markup(data); }

void Mainwin::on_save_click() {
	std::ofstream ofs{filename};
	if(!ofs) {throw std::runtime_error{"Cannot open file"};}
	
	try{
		ofs << std::to_string(students.size()) << std::endl;
		
		for(int i = 0; i < students.size(); i++){
			students[i]->Student::save(ofs);
		}
		
		ofs << std::to_string(parents.size()) << std::endl;
		
		for(int i = 0; i < parents.size(); i++){
			parents[i]->Parent::save(ofs);
		}
		
		ofs << std::to_string(_courses.size()) << std::endl;
		
		for(int i = 0; i < _courses.size(); i++) {
			_courses[i]->Course::save(ofs);
		}
		
		ofs << std::to_string(_sections.size()) << std::endl;
		
		for(int i = 0; i < _sections.size(); i++) {
			_sections[i]->Section::save(ofs);
		}
		
	} catch(std::exception e) {}
	
}

void Mainwin::on_save_as_click() {
	Gtk::FileChooserDialog saveFile("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	saveFile.set_transient_for(*this);
	
	auto filter_smart = Gtk::FileFilter::create();
	filter_smart->set_name("SMART Files");
	filter_smart->add_pattern("*.smart");
	saveFile.add_filter(filter_smart);
	
	auto filter_none = Gtk::FileFilter::create();
	filter_none->set_name("All Files");
	filter_none->add_pattern("*");
	saveFile.add_filter(filter_none);
	
	saveFile.set_filename(filename);
	
	saveFile.add_button("_Cancel", 0);
	saveFile.add_button("_Save", 1);
	
	int button_press = saveFile.run();
	
	if(button_press == 1){
		try{
			filename = saveFile.get_filename();
			on_save_click();
			
		} catch(std::exception e) {
			Gtk::MessageDialog{*this, "Could not save SMART"}.run();
		}
	}
}

void Mainwin::on_open_click() {
	on_new_school_click();
	
	Gtk::FileChooserDialog openFile("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	openFile.set_transient_for(*this);
	
	auto filter_smart = Gtk::FileFilter::create();
	filter_smart->set_name("SMART Files");
	filter_smart->add_pattern("*.smart");
	openFile.add_filter(filter_smart);
	
	auto filter_none = Gtk::FileFilter::create();
	filter_none->set_name("All Files");
	filter_none->add_pattern("*");
	openFile.add_filter(filter_none);
	
	openFile.set_filename(filename);
	
	openFile.add_button("_Cancel", 0);
	openFile.add_button("_Open", 1);
	
	int button_press = openFile.run();
	
	if(button_press == 1){
		try{
			filename = openFile.get_filename();
			std::ifstream ifs{filename};
			
			int size;
			ifs >> size;  ifs.ignore(32767, '\n');
			
			for(int i = 0; i < size; i++){
				students.push_back(new Student{ifs});
			}
			
			ifs >> size;  ifs.ignore(32767, '\n');
			for(int i = 0; i < size; i++){
				parents.push_back(new Parent{ifs});
			}
			
			ifs >> size;  ifs.ignore(32767, '\n');
			for(int i = 0; i < size; i++) {
				_courses.push_back(new Course{ifs});
			}
			
			ifs >> size;  ifs.ignore(32767, '\n');
			for(int i = 0; i < size; i++) {
				_sections.push_back(new Section{ifs});
			}
			
		} catch(std::exception e) {
			Gtk::MessageDialog{*this, "Could not open SMART"}.run();
		}
	}
	
		on_view_students_click();
}

void Mainwin::on_about_click() {
	
	//Create About Dialog
	Gtk::AboutDialog about;
	about.set_transient_for(*this);
	
	//Program name for dialog
	about.set_program_name("SMART");
	
	//Picking then setting logo picture
	auto logo = Gdk::Pixbuf::create_from_file("logo.png");
	about.set_logo(logo);
	
	//Version Copyright and License setters
	about.set_version("Version 0.0.3");
	about.set_copyright("Copyright 2021");
	about.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	
	//Labeling the authors
	std::vector<Glib::ustring> authors = {"Phillip A. Welch"};
	about.set_authors(authors);
	
	//Labeling the artists
	std::vector<Glib::ustring> artists =
	 {"Phillip A. Welch"};
	about.set_artists(artists);
	
	//Running the About dialog
	about.run();
}








