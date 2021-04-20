#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person{name, email} { }

Parent::Parent(std::istream& ist) : Person{ist} {}

void Parent::add_student(Student& student) { _students.push_back(&student); }

std::string Parent::full_info() {
	std::string all_students;
	std::string comma;
	for(Student* s : _students) { all_students += comma + s->to_string(); comma = ", ";}
	
	return Person::full_info() + " students: " + all_students;
}

void Parent::save(std::ostream& ost) {
	ost << _name << '\n' << _email << std::endl;
}
