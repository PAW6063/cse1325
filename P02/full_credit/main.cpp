#include "pet.h"

int main() {
    std::vector<Pet> pets {     {"Bear", 56.0, DOG}, {"Gizmo", 15.2, CAT}, {"Sunny", 5.0, HORSE},
     {"Bacon", 26.0, PIG}, {"Captian Jack", 52.0, FERRET}, {"Nemo", 7.0, FISH}     };
    
    for(int i = 0; i <6; i++) std::cout << pets[i].to_string() << std::endl;
    
    return 0;
}

