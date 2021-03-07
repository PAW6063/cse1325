#include "parent.h"
#include "student.h"

Parent::Parent(std::string name, std::string email) : Person{name, email} { }

void Parent::add_student(Student& student) { _students.push_back(&student); }

int Parent::students() { return _students.size(); }

Student& Parent::student(int index) { return *_students[index]; }

std::string Parent::full_info() {
	std::string all_students;
	for(int i = 0; i < students(); i++) { all_students = all_students + student(i).to_string() + ", "; }
	all_students[all_students.size() - 2] = '\0';
	
	return Person::full_info() + " students: " + all_students;
}
