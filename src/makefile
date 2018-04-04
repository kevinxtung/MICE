CXXFLAGS += --std=c++14
SRCFLAGS += -I ./
FFLAGS += $(CXX) $(CXXFLAGS) $(SRCFLAGS)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o item.o container.o
	$(FFLAGS) -o main main.o item.o container.o $(GTKFLAGS)
main.o: main.cpp *.h
	$(FFLAGS) -c main.cpp $(GTKFLAGS)
test_container: test_container.o container.o item.o
	$(FFLAGS) -o test_container test_container.o container.o item.o $(GTKFLAGS)
test_container.o: test_container.cpp
	$(FFLAGS) -c -w test_container.cpp $(GTKFLAGS)
container.o: ./classes/container/container.cpp ./classes/container/container.h
	$(FFLAGS) -c ./classes/container/container.cpp $(GTKFLAGS)
item.o: ./classes/item/item.cpp ./classes/item/item.h
	$(FFLAGS) -c ./classes/item/item.cpp $(GTKFLAGS)


clean:
	-rm -f *.o test_container
