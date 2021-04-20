#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>

#include "comboboxcontainer.h"
#include "entrydialog.h"
#include "parent.h"
#include "student.h"
#include "teacher.h"
#include "section.h"

class Mainwin : public Gtk::Window {
public :
	Mainwin();
	~Mainwin();
	
	typedef std::vector<Student*> Students;
	typedef Students::iterator iterator_s;
	typedef Students::const_iterator const_iterator_s;
	
	typedef std::vector<Parent*> Parents;
	typedef Parents::iterator iterator_p;
	typedef Parents::const_iterator const_iterator_p;
	
	typedef std::vector<Teacher*> Teachers;
	typedef Teachers::iterator iterator_t;
	typedef Teachers::const_iterator const_iterator_t;
	
	typedef std::vector<Course*> Courses;
	typedef Courses::iterator iterator_c;
	typedef Courses::const_iterator const_iterator_c;
	
	typedef std::vector<Section*> Sections;
	typedef Sections::iterator iterator_ss;
	typedef Sections::const_iterator const_iterator_ss;
	
	//typedef std::vector<Transcript*> Transcripts;
	
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
	//Added methods sprint 4
	void on_new_course_click();
	void on_new_section_click();
	void on_view_students_click();
	void on_view_parents_click();
	void on_view_courses_click();
	void on_view_sections_click();
	
	void on_new_teacher_click();
	void on_view_teacher_click();
	
private :
	Gtk::Label *display;
	std::vector <Student*> students;
	std::vector <Parent*> parents;
	//Added Attribute for sprint 3
	std::string filename;
	//Added Attributes for sprint 4
	std::vector<Course*> _courses;
	std::vector<Section*> _sections;
	std::vector<Teacher*> _teachers;
	
	void show_data(std::string data);
	void show_data();
};

#endif
