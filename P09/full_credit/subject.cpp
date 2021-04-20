#include "subject.h"


std::string to_string_subject(Subject s) {
	std::map<Subject, std::string> m = { {Subject::READING, "reading"}, {Subject::WRITING, "writing"}, 		{Subject::MATH, "math"}, {Subject::SCIENCE, "science"},
	{Subject::HISTORY, "history"}, {Subject::TRADING, "trading"}, {Subject::EXTRA, "extra"}, {Subject::NOTLISTED, "not listed"} };
	 
	 return m[s];
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
	ost << to_string_subject(subject);
	
	return ost;
}

Subject load_subject(std::istream& ist) {
	
	std::string s;
	
	std::getline(ist, s);
	
	if(s.compare("reading") == 0) return Subject::READING;
	if(s.compare("writing") == 0) return Subject::WRITING;
	if(s.compare("math") == 0) return Subject::MATH;
	if(s.compare("science") == 0) return Subject::SCIENCE;
	if(s.compare("history") == 0) return Subject::HISTORY;
	if(s.compare("trading") == 0) return Subject::TRADING;
	if(s.compare("extra") == 0) return Subject::EXTRA;
	
	return Subject::NOTLISTED;
}

Subject subject_list(int num) {
	std::map<int, Subject> list = { {0, Subject::READING}, {1, Subject::WRITING}, {2, Subject::MATH}, {3, Subject::SCIENCE}, {4, Subject::HISTORY}, {5, Subject::TRADING}, {6, Subject::EXTRA}, {7, Subject::NOTLISTED} };
	
	if((num > -1) && (num < 7)) {
		return list[num];
	}
	
	return list[7];
}
