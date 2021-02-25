#include "Card.h"
#include <ctype.h>


Card::Card(std::string question, std::string answer) : _question{question}, _answer{answer} {}

std::string Card::attempt(std::string response) {
    
    std::string response_2 = response;
    std::string answer_2 = _answer;
    
    for (int i : response_2) {
        response_2[i] = toupper(response[i]);
    }
    for (int i : answer_2) {
        answer_2[i] = toupper(_answer[i]);
    }
    
    if( response_2 == answer_2 ) {
        return "Correct!";
    } else {
        return ("X - Correct answer was" + _answer);
    }
}

std::ostream& operator<<(std::ostream& ost, Card& m) {
    
    return ost << m._question;
}

