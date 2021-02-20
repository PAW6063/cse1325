(CXXFLAGS) = --std=c++17


all : flashcards


flashcards : main.o Deck.o Card.o *.h
	$(CXX) $(CXXFLAGS) main.o Deck.o Card.o -o flashcards

main.o : main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Deck.o : Deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c Deck.cpp -o Deck.o

Card.o : Card.cpp *.h
	$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o

clean :
	rm -f *~ *.ghc *.o a.out test flashcards
