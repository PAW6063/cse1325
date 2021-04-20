#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person{name, email}, _grade{grade} {	}

Student::Student(std::istream& ist) : Person{ist} {
	
	ist >> _grade; ist.ignore(32767, '\n');
}

void Student::add_parent(Parent& parent) { _parents.push_back(&parent); }

std::string Student::full_info() {
	std::string all_parents;
	std::string comma;
	for(Parent* p : _parents) { all_parents += comma + p->to_string(); comma = ", "; }
	
	return Person::full_info() + " grade " + std::to_string(_grade) + " parents: " + all_parents;
}

void Student::save(std::ostream& ost) {
	ost << _name << '\n' << _email << '\n' << std::to_string(_grade) << std::endl;
}
