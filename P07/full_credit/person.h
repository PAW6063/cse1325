#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <istream>

class Person {
public:
	Person(std::string name, std::string email);
	Person(std::istream& ist);
	std::string to_string();
	virtual std::string full_info();
	virtual void save(std::ostream& ost);
	
	friend std::ostream& operator<<(std::ostream& ost, const Person& person);
	
protected:
	std::string _name;
	std::string _email;
};

#endif 
