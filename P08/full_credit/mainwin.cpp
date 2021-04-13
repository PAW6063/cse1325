#include "mainwin.h"

#define STUDENT_SIZE 500
#define PARENT_SIZE 300



Mainwin::Mainwin() {
	 
	 //Default file name
	 filename = "untitled.smart";
	 
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
	 menuIem_course->signal_activate().connect([this] {this->on_new_course_click();});
	 insertMenu->append(*menuIem_course);
	 
	 //New Section
	 Gtk::MenuItem *menuItem_section = Gtk::manage(new Gtk::MenuItem("_New Section", true));
	 menuIem_section->signal_activate().connect([this] {this->on_new_section_click();});
	 insertMenu->append(*menuIem_section);
	 
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
	
	
	//**************************
	//ADDS NEW STUDENT TO HEAP
	//**************************
	students.push_back(new Student{entry_name.get_text(), entry_email.get_text(), g});
	
	show_data();
}

void Mainwin::on_new_parent_click() {
	
	EntryDialog entry_name{*this, "<big><b>Parent name?</b></big>", true}; entry_name.set_text("Enter name!"); entry_name.run();
	EntryDialog entry_email{*this, "<big><b>Parent email?</b></big>", true}; entry_email.set_text("Enter email!"); entry_email.run();
	
	//**************************
	//ADDS NEW PARENT TO HEAP
	//**************************
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
	
	//*************************************
	// THIS IS WHERE I THINK THE PRBLEM IS
	//*************************************
	students[s]->add_parent(*parents[p]);
	parents[p]->add_student(*students[s]);
	
	show_data();
	
	
}

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::show_data() {
	Glib::ustring data = "";
	
	data += "\tStudents:\n";
	if(students.size() > 0) {
		for(auto & i : students) {
		    data += i->full_info() + "\n";
		}
	}
	
	data += "\n\tParents:\n";
	if(parents.size() > 0) {
		for(auto & i : parents) {
			data += i->full_info() + "\n";
		}
	}
	
	display->set_markup(data);
}

void Mainwin::on_save_click() {
	std::ofstream ofs{filename};
	if(!ofs) {throw std::runtime_error{"Cannot open file"};}
	
	try{
		ofs << std::to_string(students.size()) << std::endl;
		
		for(int i = 0; i < students.size(); i++){
			students[i]->Student::save(ofs);
		}
		
		ofs << std::to_string(parents.size()) << std::endl;
		
		for(int i = 0; i < students.size(); i++){
			parents[i]->Parent::save(ofs);
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
			std::string s;
			ifs >> s;
			int size = stoi(s);
			
			for(int i = 0; i < size; i++){
				students.push_back(new Student{ifs});
			}
			size = 0;
			
			ifs >> s;
			size = stoi(s);
			for(int i = 0; i < size; i++){
				parents.push_back(new Parent{ifs});
			}
			
		} catch(std::exception e) {
			Gtk::MessageDialog{*this, "Could not open SMART"}.run();
		}
	}
	
	show_data();
}

void Mainwin::on_about_click() {
	
	//Create About Dialog
	Gtk::AboutDialog about;
	about.set_transient_for(*this);
	
	//Program name for dialog
	about.set_program_name("SMART");
	
	//Picking then setting logo picture
	auto logo = Gdk::Pixbuf::create_from_file("logo.jpeg");
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
	 {"https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.pngkey.com%2Fmaxpic%2Fu2e6y3t4u2i1w7w7%2F&psig=AOvVaw3C1bizgHGpQ5AK9SVncT1g&ust=1617188860212000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCMDCyJHw1-8CFQAAAAAdAAAAABAW", 
	 "https://www.google.com/url?sa=i&url=https%3A%2F%2Ficon-icons.com%2Ficon%2Flink-programing-symbol-of-interface%2F105005&psig=AOvVaw1Hc2FRG6zKw3ZI87KFBw7b&ust=1617190464945000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCOizx-r21-8CFQAAAAAdAAAAABAD",
	 "Phillip A. Welch"};
	about.set_artists(artists);
	
	//Running the About dialog
	about.run();
}














