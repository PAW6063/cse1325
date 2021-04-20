#include "section.h"


Section::Section(Course course, Semester semester, int year/*, Teacher& teacher*/) : _course{course}, _semester{semester}, _year{year}{} //_teacher{teacher} {}

Section::Section(std::istream& ist) : _course{ist} {
	_semester = load_semester(ist);
	ist >> _year; ist.ignore(32767, '\n');
	//_teacher = load_teacher(ist);
}

void Section::save(std::ostream& ost) {
	
	_course.Course::save(ost);
	//ost << _semester << '\n' << _year << '\n' << _teacher << '\n';
}

std::ostream& operator<<(std::ostream& ost, const Section section) {
	
	ost << section._course << " for " << section._semester << " " << section._year;
	
	return ost;
}

std::string Section::section_print() {
	std::string output = "";
	
	//output += _course.course_print() + " for " + to_string(_semester) + " " + std::to_string(_year) + " (taught by " + _teacher.Person::full_info() + ")";
	
	return output;
}
