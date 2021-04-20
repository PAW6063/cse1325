#ifndef __ENTRYDIALOG_H
#define __ENTRYDIALOG_H

#include <gtkmm.h>
#include "subject.h"
#include "course.h"

class EntryDialog : public Gtk::MessageDialog {
  public:
    
    EntryDialog(Gtk::Window& parent,
                const Glib::ustring& message, 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false);

    void set_text (const Glib::ustring& text);
    Glib::ustring get_text () const;
  private:
    Gtk::Entry* entry;
};


class CourseDialog : public Gtk::Dialog {
public:
	CourseDialog(const Glib::ustring& title, Gtk::Window& parent,
				 bool modal=false, bool use_header_bar=false);
	
	Subject get_subject();
	int get_grade();	
		
private:
	Gtk::Grid plot;
	
	Gtk::Label l_subject;
	Gtk::ComboBoxText c_subject;
	
	Gtk::Label l_grade;
	Gtk::SpinButton s_b_grade;
};

#endif
