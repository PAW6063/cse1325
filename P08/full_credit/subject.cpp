#include "subject.h"


std::string to_string(Subject s) {
	std::map<Subject, std::string> m = { {Subject::READING, "reading"}, {Subject::WRITING, "writing"}, 		{Subject::MATH, "math"}, {Subject::SCIENCE, "science"},
	{Subject::HISTORY, "history"}, {Subject::EXTRA, "extra"} };
	 
	 return m[s];
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
	ost << to_string(subject);
	
	return ost;
}

Subject load_subject(std::istream& ist) {
	std::string s;
	ist >> s;
	
	switch(s){
		case "reading" : return Subject::READING;
		case "writing" : return Subject::WRITING;
		case "math" : return Subject::MATH;
		case "science" : return Subject::SCIENCE;
		case "history" : return Subject::HISTORY;
		case "extra" : return Subject::EXTRA;
	}
}
