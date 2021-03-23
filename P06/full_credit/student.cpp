#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade) : Person{name, email}, _grade{grade} {	}

void Student::add_parent(Parent& parent) { _parents.push_back(&parent); }

int Student::parents() { return _parents.size(); }

Parent& Student::parent(int index) { return *(_parents[index]); }

std::string Student::full_info() {
	std::string all_parents;
	for(int i = 0; i < parents(); i++) { all_parents = all_parents + parent(i).to_string() + ", "; }
	all_parents[all_parents.size() - 2] = '\0';
	
	return Person::full_info() + " grade " + std::to_string(_grade) + " parents: " + all_parents;
}
