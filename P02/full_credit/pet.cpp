//definitions
#include "pet.h"

std::string to_string(Type type) {
    std::vector<std::string> vtype = {"Cat", "Dog", "Horse", "Pig", "Fish", "Ferret"};
    
    return vtype[type];
}

Pet::Pet(std::string n, double a, Type t) : name{n}, age{a}, type{t} {}

std::string Pet::to_string() {
    return  name + " is a "
    +         ::to_string(type) + " age "
    +       std::to_string(age);
}
