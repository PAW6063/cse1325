#include "fraction.h"


 int main() {
    Fraction one;
	Fraction two;

	std::cout << "Enter a fraction (#/#): ";
	std::cin >> one;
	std::cout << "Enter another (#/#): ";
	std::cin >> two;
	
	Fraction three = -one;
	Fraction three2 = -two;
	Fraction four = one - two;
	Fraction five = one + two;
	Fraction six = one * two;
	Fraction seven = one / two;
	std::cout << "Negate: " << three << " " << three2 << std::endl;
	std::cout << "Subtract: " << four << std::endl;
	std::cout << "Add: " << five << std::endl;
	std::cout << "Multiply: " << six << std::endl;
	std::cout << "Divide: " << seven << std::endl;

    return 0;
}
