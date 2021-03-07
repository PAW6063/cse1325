#include "person.h"

Person::Person(std::string name, std::string email) : _name{name} _email{email} { }

std::string to_string() {
	return _name;
}

virtual std::string full_info() {
	return _name + " (" + _email + ")";
}
	
friend ostream& operator<<(ostream& ost, const Person& person) {
	ost << person._name;
	
	return ost;
}
