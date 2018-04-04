CXXFLAGS += --std=c++14
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags--libs`

main: main.o item.o container.o
    $(CXX) $(CXXFLAGS) -o main main.o item.o container.o $(GTKFLAGS)
main.o: main.cpp *.h
    $(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
item.o: item.cpp *.h
    $(CXX) $(CXXFLAGS) -c item.cpp $(GTKFLAGS)
container.o: container.cpp *.h
    $(CXX) $(CXXFLAGS) -c container.cpp $(GTKFLAGS)
