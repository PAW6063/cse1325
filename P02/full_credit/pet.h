//declarations
#ifndef __PET_H
#define __PET_H

#include <iostream>
#include <vector>

//namespace pet_types {
    enum Type{CAT, DOG, HORSE, PIG, FISH, FERRET};
    std::string to_string(Type type);
//}

class Pet {
    public:
    Pet(std::string name, double age, Type type);
    std::string to_string();
    private:
    std::string name;
    double age;
    Type type;
};

#endif
