#include "Deck.h"
#include "Card.h"


int main() {
    std::cout << "This is a flashcard study game enjoy!! Exit(-1)" << std::endl;
    
    Deck _deck;
    _deck.add_card("A style of programming focused on the use of classes and class hierarchies", "Object-Oriented Programming (OOP)");
    _deck.add_card("Reuse and extension of fields and method implementations from another class", "Inheritance");
    _deck.add_card("Bundling data and code into a restricted container", "Encapsulation");
    _deck.add_card("Specifying a general interface while hiding implementation details (sometimes listed as a4th fundamental concept of OOP, though I believe it's common to most paradigms)", "Abstraction");
    _deck.add_card("A data type that can typically be handled directly by the underlying hardware", "Primitive type");
    _deck.add_card("A data type consisting of a fixed set of constant values called enumerators (C++has both enum and enum class)", "Enumerated type");
    _deck.add_card("A template encapsulating data and code that manipulates it (C++ also has struct, which isidentical other than default visibility)", "Class");
    _deck.add_card("An encapsulated bundle of data and code (e.g., an instance of a program is a process; aninstance of a class is an object)", "Instance");
    _deck.add_card("An instance of a class containing a set of encapsulated data and associated methods", "Object");
    _deck.add_card("A block of memory associated with a symbolic name that contains an object instance or aprimitive data value", "Variable");
    
    _deck.add_false_answer("Friend");
    _deck.add_false_answer("Attribute");
    _deck.add_false_answer("Destructor");
    _deck.add_false_answer("Method");
    
    
   /* 
    std::string _default;
    while( ( toupper(_default[0]) != 'Y' ) || ( toupper(_default[0]) != 'N' ) ){
        std::cout << "\n\n\nA default deck has been made would you like to add cards??(Y/n) ";
        std::getline(std::cin, _default);
        
        if(_default == "-1"){
            return 0;
        }
        
        if(toupper(_default[0]) == 'Y'){
            
            int _d = 0;
            while(_d != 3) {
                std::cout << "\nAdd question & true answer (1), Add false answer (2), Go to study(3)";
                std::cin >> _d;
                
                if( _d == -1) {
                    return 0;
                }
                
                if(_d == 1) {
                    
                    std::string _q;
                    std::string _a;
                    
                    std::cout << "\nEnter a question: ";
                    std::getline(std::cin, _q);
                    if(_q == "-1") {
                        return 0;
                    }
                    std::cout << "\nEnter an answer: ";
                    std::getline(std::cin, _a);
                    if(_a == "-1") {
                        return 0;
                    }
                    _deck.add_card(_q, _a);
                }
                
                if(_d == 2) {
                    
                    std::string _fa;
                    
                    std::cout << "\nEnter a false answer: ";
                    std::getline(std::cin, _fa);
                    
                    if(_fa == "-1") {
                        return 0;
                    }
                    
                    _deck.add_false_answer(_fa);
                }
                
                if( ( _d != -1 ) || ( _d != 1 ) || ( _d != 2) || ( _d != 3 ) ) {
                    
                    std::cout << "\nNot a valid choice." << std::endl;
                }
            }
            
        } else if(toupper(_default[0]) == 'N') {
            break;
        } else {
            
            std::cout << "\nNot a valid choice." << std::endl;
        }
    }
    */
    
    
    int _c;
    while(_c != -1){
        
        Card _new = _deck.deal();
    
        std::cout << "\nSelect the number of the term for each definition (-1 to exit)\n" << std::endl;
        
        std::vector<std::string> _deck_options = _deck.options();
        
        for(int i = 0; i < _deck_options.size(); i++) {
		    std::cout << i << ".) " << _deck_options[i] << std::endl;
	    }
	    
	    std::cout << "\n" << _new << "?? ";
	    std::cin >> _c;
	    
	    if(_c != -1) {
	        if((_c > -1) && (_c < _deck_options.size())){
	            std::string _answer_choice = _new.attempt(_deck_options[_c]);
	            std::cout << _answer_choice << std::endl;
            }else{
                std::cout << "Not a valid choice." << std::endl;
            }
        }
    }
    
    
    
    return 0;    
}
