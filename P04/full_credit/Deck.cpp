#include "Deck.h"



void Deck::add_card(std::string question, std::string answer) {
    
    Card *flashcard = new Card(question, answer);
    _cards.push_back(*flashcard);
    
    _options.push_back(answer);
    
    _next_card = _cards.size();
}

void Deck::add_false_answer(std::string false_answer){
	
	_options.push_back(false_answer);
	
}

std::vector<std::string> Deck::options(){
	
	std::random_shuffle(_options.begin(), _options.end());
	
	return _options;
}

Card Deck::deal(){
	
	if(_cards.size() == 0){
		throw std::runtime_error{"No cards added!"};
	}else{
		if(_next_card > _cards.size()){
			std::random_shuffle(_cards.begin(), _cards.end());
			_next_card = 0;
		}
		
		_next_card++;
		
		return _cards[(_next_card - 1)];
	}
}

