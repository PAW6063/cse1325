#include "semester.h"


std::string to_string(Semester s) {
	std::map<Semester, std::string> m = { {Semester::FALL, "fall"}, {Semester::SPRING, "spring"},
	{Semester::SUMMER, "summer"}, {Semester::NONE, "none"} };
	 
	 return m[s];
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester) {
	ost << to_string(semester);
	
	return ost;
}

Semester load_semester(std::istream& ist) {
	
	std::string s;
	
	std::getline(ist, s);
	
	if(s.compare("fall") == 0) return Semester::FALL;
	if(s.compare("spring") == 0) return Semester::SPRING;
	if(s.compare("summer") == 0) return Semester::SUMMER;
	
	
	return Semester::NONE;
}

Semester semester_list(int num) {
	std::map<int, Semester> list = { {0, Semester::FALL}, {1, Semester::SPRING}, {2, Semester::SUMMER}, {3, Semester::NONE} };
	
	if( (num > -1) && (num < 3) ) {
		return list[num];
	}
	
	return list[3];
}
