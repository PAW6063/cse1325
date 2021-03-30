#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person{name, email}, _grade{grade} {	}

Student::Student(std::istream& ist) : Person{ist} {
	std::string grade;
	ist >> grade;
	_grade = stoi(grade);
}

void Student::add_parent(Parent& parent) { _parents.push_back(&parent); }

int Student::parents() { return _parents.size(); }

Parent& Student::parent(int index) { return *(_parents[index]); }

std::string Student::full_info() {
	std::string all_parents;
	std::string comma;
	for(int i = 0; i < parents(); i++) { all_parents += comma + parent(i).to_string(); comma = ", ";}
	
	
	return Person::full_info() + " grade " + std::to_string(_grade) + " parents: " + all_parents;
}

void Student::save(std::ostream& ost) {
	ost << _name << '\n' << _email << '\n' << std::to_string(_grade) << std::endl;
}
