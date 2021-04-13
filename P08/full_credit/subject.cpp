#include "subject.h"


std::string to_string(Subject s) {
	std::map<Subject, std::string> m = { {Subject::READING, "reading"}, {Subject::WRITING, "writing"}, 		{Subject::MATH, "math"}, {Subject::SCIENCE, "science"},
	{Subject::HISTORY, "history"}, {Subject::EXTRA, "extra"}, {Subject::NOTLISTED, "not listed"} };
	 
	 return m[s];
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
	ost << to_string(subject);
	
	return ost;
}

Subject load_subject(std::istream& ist) {
	
	std::string s;
	
	std::getline(ist, s); ist.ignore(32767, '\n');
	
	if(s.compare("reading") == 0) return Subject::READING;
	if(s.compare("writing") == 0) return Subject::WRITING;
	if(s.compare("math") == 0) return Subject::MATH;
	if(s.compare("science") == 0) return Subject::SCIENCE;
	if(s.compare("history") == 0) return Subject::HISTORY;
	if(s.compare("extra") == 0) return Subject::EXTRA;
	
	return Subject::NOTLISTED;
}
