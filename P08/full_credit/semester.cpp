#include "semester.h"


std::string to_string(Semester s) {
	std::map<Semester, std::string> m = { {Semester::FALL, "fall"}, {Semester::SPRING, "spring"},
	{Semester::SUMMER, "summer"} };
	 
	 return m[s];
}

std::ostream& operator<<(std::ostream& ost, const Semester& semester) {
	ost << to_string(semester);
	
	return ost;
}

Semester load_semester(istream& ist) {
	std::string s;
	ist >> s;
	
	switch(s){
		case "fall" : return Semester::FALL;
		case "spring" : return Semester::SPRING;
		case "summer" : return Semester::SUMMER;
	}
}
