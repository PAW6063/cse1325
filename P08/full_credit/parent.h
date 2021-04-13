#ifndef __PARENT_H
#define __PARENT_H

#include <vector>
#include <string>
#include <ostream>
#include <fstream>

#include "person.h"

class Student;

class Parent : public Person {
public:
	Parent(std::string name, std::string email);
	Parent(std::istream& ist);
	void add_student(Student& student);
	int students();
	Student& student(int index);
	std::string full_info() override;
	virtual void save(std::ostream& ost);
	
protected:
	std::vector<Student*> _students;
};

#endif  
