#include "fraction.h"
#include <string>

Fraction::Fraction(int numerator, int denominator) : _numerator{numerator}, _denominator{denominator} {
	reduce();
}

void Fraction::reduce() {
	if(Fraction::_denominator < 1) {
		Fraction::_denominator = Fraction::_denominator * -1;
		Fraction::_numerator = Fraction::_numerator * -1;
	}
	int ii;
	if(_denominator > _numerator) {
		ii = _denominator;
	}else{ii = _numerator;}

	for(int i = ii; i > 1 ; i--){
		if( ( (_denominator % i) == 0) && ( (_numerator % i) == 0)) {
			_denominator /= i;
			_numerator /= i;
		}
	}
}

std::ostream& operator<<(std::ostream& ost, Fraction& m) {
    ost << m._numerator << '/' << m._denominator;
    
    return ost;
}

std::istream& operator>>(std::istream& ist, Fraction& m) {
    char slash;

	ist >> m._numerator >> slash >> m._denominator;

	m.reduce();
	
	return ist;
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
	
	if(lhs._numerator != rhs._numerator) {return true; }

	if(lhs._denominator != rhs._denominator) {return true; }
    
    return false;
}

Fraction Fraction::operator-() {
	return Fraction{-_numerator, _denominator};
}

Fraction Fraction::operator+(Fraction& rhs) {
	return Fraction{((_numerator * rhs._denominator) + (rhs._numerator * _denominator)), 				(_denominator * rhs._denominator)};
}
Fraction Fraction::operator-(Fraction& rhs) {
	return Fraction{((_numerator * rhs._denominator) - (rhs._numerator * _denominator)), 				(_denominator * rhs._denominator)};
}
Fraction Fraction::operator*(Fraction& rhs) {
	return Fraction{_numerator * rhs._numerator, _denominator * rhs._denominator};
}
Fraction Fraction::operator/(Fraction& rhs) {
	return Fraction{_numerator * rhs._denominator, _denominator * rhs._numerator};
}
