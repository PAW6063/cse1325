(CXXFLAGS) = --std=c++17

test : test.o fraction.o *h
	$(CXX) $(CXXFLAGS) test.o fraction.o -o fraction

fraction : main.o fraction.o *h
	$(CXX) $(CXXFLAGS) main.o fraction.o -o fraction

main.o : main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

test.o : test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

fraction.o : fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

clean :
	rm -f *.o *.gch fraction a.out *~
