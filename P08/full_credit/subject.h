#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <iostream>
#include <string>
#include <map>

enum class Subject {READING, WRITING, MATH, SCIENCE, HISTORY, EXTRA, NOTLISTED};

std::string to_string(Subject s);

std::ostream& operator<<(std::ostream& ost, const Subject& subject);

Subject load_subject(std::istream& ist);

Subject subject_list(int num);

#endif
