CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all : smart

smart : main.o person.o student.o parent.o mainwin.o entrydialog.o
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o mainwin.o entrydialog.o $(GTKFLAGS) -o smart

main.o : main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

person.o : person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o : student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o : parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

mainwin.o : mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o : entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

debug : clean 
	$(CXX) $(CXXFLAGS) 

clean :
	rm -f *~ *.gch *.o a.out smart test *.smart
