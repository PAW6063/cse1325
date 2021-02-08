#include "fraction.h"
#include <string>

Fraction::Fraction(int numerator, int denominator) : _numerator{numerator}, _denominator{denominator} {

}

void Fraction::reduce() {

}

std::ostream& operator<<(std::ostream& ost, Fraction& m) {
    ost << m._numerator << '/' << m._denominator;
    
    return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& m) {
    std::string f;
    std::string sn = f.substr(0, f.find("/"));
    std::string sd = f.substr(f.find("/"));
    
    int n = stoi(sn);
    int d = stoi(sd);
    
    m._numerator = n;
    m._denominator = d;
    
    return ist;
}

bool operator!=(const Fraction& lhs, const Fraction&) {
    
    
    return true;
}
