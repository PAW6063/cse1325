#include "Deck.h"
#include "Card.h"


int main() {
    Deck _deck;
    _deck.add_card("A style of programming focused on the use of classes and class hierarchies", "Object-Oriented Programming (OOP)");
    _deck.add_false_answer("Inheritance");
    
    std::cout << "Select the number of the term for each definition (-1 to exit)\n" << std::endl;
    
    std::vector<std::string> _deck_options = _deck.options();
    
    for(int i = 0; i < _deck_options.size(); i++) {
		std::cout << i << ".) " << _deck_options[i] << std::endl;
	}
	
	Card _new = _deck.deal();
	int _choice;
	
	std::cout << "\n" << _new << "?? ";
	std::cin >> _choice;
	
	std::string _answer_choice = _new.attempt(_deck_options[_choice]);
    
    return 0;    
}
