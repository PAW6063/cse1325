#include "comboboxcontainer.h"


typedef T::iterator iterator;
	typedef T::const_iterator const_iterator;
	iterator begin() { return container.begin(); }
	iterator end() { return container.end(); }
	ComboBoxContainer::ComboBoxContainer(T container) {
	
	for(auto& t: container) {
		std::ostringstream oss;
		oss << *t;
		append(oss);
	}
}
