#ifndef _COMBOBOXCONTAINER_H
#define _COMBOBOXCONTAINER_H

#include <gtkmm.h>
#include <sstream>
#include <ostream>

template <class T> 

class ComboBoxContainer : public Gtk::ComboBoxText {
public:
	ComboBoxContainer(T container);
};

template <class T>

ComboBoxContainer<T>::ComboBoxContainer(T container) {
	
	for(auto& t: container) {
		Gtk::ComboBoxText::append(t->to_string());
	}
	
	Gtk::ComboBoxText::set_active(0);
};

#endif
