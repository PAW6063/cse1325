#ifndef __PARENT_H
#define __PARENT_H

#include <vector>
#include <string>
#include <ostream>
#include <fstream>

#include "person.h"

class Student;

class Parent : public Person {
protected:
	typedef std::vector<Student*> Students;
	Students _students;

public:
	Parent(std::string name, std::string email);
	Parent(std::istream& ist);
	void add_student(Student& student);
	std::string full_info() override;
	virtual void save(std::ostream& ost);
	
	typedef Students::iterator iterator;
	typedef Students::const_iterator const_iterator;
	iterator begin() { return _students.begin(); }
	iterator end() { return _students.end(); }
};

#endif  
