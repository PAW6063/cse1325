#include "teacher.h"


Teacher::Teacher(std::string name, std::string email) : Person{name, email} { }

Teacher::Teacher(std::istream& ist) : Person{ist} { }

void Teacher::save(std::ostream& ost) {
	ost << _name << '\n' << _email << std::endl;
}

std::string Teacher::full_info() {
	return Person::full_info();
}
