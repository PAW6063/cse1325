#ifndef __PERSON_H
#define __PERSON_H

class Person {
public:
	Person(std::string name, std::string email);
	std::string to_string();
	virtual std::string full_info();
	
	friend ostream& operator<<(ostream& ost, const Person& person);
	
protected:
	std::string _name;
	std::string _email;
};

#endif 
