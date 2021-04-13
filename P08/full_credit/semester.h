#ifndef _SEMESTER_H
#define _SEMESTER_H

#include <iostream>
#include <map>

enum class Semester {FALL, SPRING, SUMMER};

std::string to_string(Semester s);

std::ostream& operator<<(std::ostream& ost, const Semester& semester);

Semester load_semester(istream& ist);

#endif
