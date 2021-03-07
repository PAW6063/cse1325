CXXFLAGS = --std=c++17

all : smart

smart : main.o person.o student.o parent.o
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o -o smart

main.o : main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

person.o : person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o : student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o : parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

test : example.o person.o student.o parent.o
	$(CXX) $(CXXFLAGS) example.o person.o student.o parent.o -o test

example.o : example.cpp *.h
	$(CXX) $(CXXFLAGS) -c example.cpp -o example.o

clean :
	rm -f *~ *.gch *.o a.out smart test
