#ifndef __STDUENT_H
#define __STUDENT_H

#include <vector>
#include <string>
#include <ostream>
#include <fstream>

#include "person.h"

class Parent;

class Student : public Person {
public:
	Student(std::string name, std::string email, int grade);
	Student(std::istream& ist);
	void add_parent(Parent& parent);
	int parents();
	Parent& parent(int index);
	std::string full_info() override;
	virtual void save(std::ostream& ost);
	
protected:
	int _grade;
	std::vector<Parent*> _parents;
};

#endif
