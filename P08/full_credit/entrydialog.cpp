#include "entrydialog.h"

EntryDialog::EntryDialog(Gtk::Window& parent,
                         const Glib::ustring& message, 
                         bool use_markup, 
                         Gtk::MessageType type, 
                         Gtk::ButtonsType buttons, 
                         bool modal)
  : MessageDialog(parent, message, use_markup, type, buttons, modal), entry{new Gtk::Entry{}}
{
    get_content_area()->pack_start(*entry);
    entry->show();
}

void EntryDialog::set_text (const Glib::ustring& text) { entry->set_text(text); }

Glib::ustring EntryDialog::get_text () const { return entry->get_text(); }

CourseDialog::CourseDialog(const Glib::ustring& title, Gtk::Window& parent, bool modal, bool use_header_bar)
	: l_subject{"Subject"}, l_grade{"Grade"}
{
	for(int i = 0; i < 7; i++) {
		c_subject.append(to_string(subject_list(i)));
	}
	
	c_subject.set_active(6);
	
	plot.attach(l_subject, 0, 0, 1, 1);
	plot.attach(c_subject, 1, 0, 2, 1);
	
	s_b_grade.set_range(1, 12);
	s_b_grade.set_increments(1, 3);
	s_b_grade.set_value(1);
	
	plot.attach(l_grade, 0, 1, 1, 1);
	plot.attach(s_b_grade, 1, 1, 2, 1);
	
	get_content_area()->pack_start(plot);
	
	add_button("Select", Gtk::RESPONSE_OK);
    add_button("Cancel", Gtk::RESPONSE_CANCEL);
    
    show_all();
}

Subject CourseDialog::get_subject() { return subject_list(c_subject.get_active_row_number()); }

int CourseDialog::get_grade() { return s_b_grade.get_value_as_int(); }
