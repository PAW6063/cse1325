#ifndef __STDUENT_H
#define __STUDENT_H


class Parent;

class Student : public Person {
public:
	Student(std::string name, std::string email, int grade);
	void add_parent(Parent& parent);
	int parents();
	Parent& parent(int index);
	std::string full_info() override;
	
protected:
	int _grade;
	std::vector<Parent*> _parents;
};

#endif
