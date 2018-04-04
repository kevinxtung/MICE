CXXFLAGS += --std=c++14
SRCFLAGS += -I ./

FFLAGS += $(CXX) $(CXXFLAGS) $(SRCFLAGS)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o item.o container.o
	$(CXX) $(CXXFLAGS) -o main main.o item.o container.o $(GTKFLAGS)
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
test_container: test_container.o container.o item.o
	$(CXX) $(CXXFLAGS) -o test_container test_container.o container.o item.o $(GTKFLAGS)
test_container.o: test_container.cpp
	$(CXX) $(CXXFLAGS) $(SRCFLAGS) -c -w test_container.cpp $(GTKFLAGS)
container.o: container.cpp *.h
	$(CXX) $(CXXFLAGS) $(SRCFLAGS) -c container.cpp $(GTKFLAGS)
item.o: item.cpp *.h
	$(FFLAGS) -c item.cpp $(GTKFLAGS)


