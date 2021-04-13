#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <iostream>
#include <map>

enum class Subject {READING, WRITING, MATH, SCIENCE, HISTORY, EXTRA};

std::string to_string(Subject s);

std::ostream& operator<<(std::ostream& ost, const Subject& subject);

Subject load_subject(std::istream& ist);

#endif
