#ifndef __CARD_H
#define __CARD_H

#include <ostream>
#include <string>


class Card {
    public :
    Card(std::string _question = "", std::string _answer = "");
    
    std::string attempt(std::string response);
    
    friend std::ostream& operator<<(std::ostream& ost, Card& m);
    
    private :
    std::string _question;
    std::string _answer;
};

#endif

