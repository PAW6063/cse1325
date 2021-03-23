#ifndef __ENTRYDIALOG_H_H
#define __ENTRYDIALOG_H

#include <gtkmm.h>

class EntryDialog : public Gtk::MessageDialog {
public :
	void set_text(Glib::ustring text);
	Glib::ustring get_text();
}

#endif
