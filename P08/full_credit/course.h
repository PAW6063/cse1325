#ifndef _COURSE_H
#define _COURSE_H

#include <iostream>
#include <ostream>

#include "subject.h"

class Course{

public :
	Course(Subject subject, int grade);
	Course(std::istream& ist);
	void save(std::ostream& ost);
	
	friend std::ostream& operator<<(std::ostream& ost, const Course course);

private :
	Subject _subject;
	int _grade;
};

#endif
