#include "section.h"


Section::Section(Course course, Semester semester, int year) : _course{course}, _semester{semester}, _year{year} {}

Section::Section(std::istream& ist) : _course{ist} {
	_semester = load_semester(ist);
	ist >> _year; ist.ignore(32767, '\n');
}

void Section::save(std::ostream& ost) {
	
	_course.Course::save(ost);
	ost << _semester << '\n' << _year << '\n';
}

std::ostream& operator<<(std::ostream& ost, const Section section) {
	
	ost << section._course << " for " << section._semester << " " << section._year;
	
	return ost;
}

std::string Section::section_print() {
	std::string output = "";
	
	output += _course.course_print() + " for " + to_string(_semester) + " " + std::to_string(_year);
	
	return output;
}
