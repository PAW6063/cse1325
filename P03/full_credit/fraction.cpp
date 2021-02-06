#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) : _numerator{numerator}, _denominator{denominator} {

}

void Fraction::reduce() {

}

std::ostream& operator<<(std::ostream& ost, Fraction& m) {
    ost << m._numerator << '/' << m._denominator;
    
    return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& m) {
    std::string = ist;
    
    
    return ist;
}

bool operator!=(const Fraction& lhs, const Fraction&) {
    
    
    return true;
}
