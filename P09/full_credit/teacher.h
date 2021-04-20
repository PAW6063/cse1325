#ifndef _TEACHER_H
#define _TEACHER_H

#include "person.h"

class Teacher : public Person {
public:
	Teacher(std::string name, std::string email);
	Teacher(std::istream& ist);
	virtual void save(std::ostream& ist);
	std::string full_info() override;
};

#endif    
