#ifndef __DECK_H
#define __DECK_H

#include <iostream>
#include <string>
#include <vector>

#include "Card"

class Deck {
    public :
    void add_card(std::string question, std::string answer);
    void add_false_answer(std::string false_answer);
    std::vector<std::string> options();
    Card::Card deal();
    
    private :
    std::vector<Card> _cards;
    std::vector<std::string> _options;
    int _next_card; 
}

#endif
