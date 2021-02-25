#include "Card.h"
#include <ctype.h>


Card::Card(std::string question, std::string answer) : _question{question}, _answer{answer} {}

std::string Card::attempt(std::string response) {
    
    if( response == _answer ) {
        return "Correct!";
    } else {
        return ("X - Correct answer was " + _answer);
    }
}

std::ostream& operator<<(std::ostream& ost, Card& m) {
    
    return ost << m._question;
}

