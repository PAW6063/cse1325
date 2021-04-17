#ifndef _SECTION_H
#define _SECTION_H

#include <iostream>
#include <ostream>

#include "semester.h"
#include "course.h"

class Section {
public:
	Section(Course course, Semester semester, int year);
	Section(std::istream& ist);
	void save(std::ostream& ost);
	std::string section_print();
	
	friend std::ostream& operator<<(std::ostream& ost, const Section section);
private:
	Course _course;
	Semester _semester;
	int _year;
};

#endif
