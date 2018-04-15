CXXFLAGS += --std=c++14
SRCFLAGS += -I ./
FFLAGS += $(CXX) $(CXXFLAGS) $(SRCFLAGS)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o main_window.o dialogs.o controller.o view.o emporium.o item.o scoop.o container.o topping.o
	$(FFLAGS) -o mice main.o main_window.o dialogs.o controller.o view.o emporium.o item.o scoop.o container.o topping.o $(GTKFLAGS)
main.o: main.cpp
	$(FFLAGS) -c main.cpp $(GTKFLAGS)
main_window.o: ./classes/main_window/main_window.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window.cpp $(GTKFLAGS)
dialogs.o: ./classes/dialogs/dialogs.cpp ./classes/dialogs/dialogs.h
	$(FFLAGS) -c ./classes/dialogs/dialogs.cpp $(GTKFLAGS)
controller.o: ./classes/controller/controller.cpp ./classes/controller/controller.h
	$(FFLAGS) -c ./classes/controller/controller.cpp $(GTKFLAGS)
view.o: ./classes/view/view.cpp ./classes/view/view.h
	$(FFLAGS) -c ./classes/view/view.cpp $(GTKFLAGS)
emporium.o: ./classes/emporium/emporium.cpp ./classes/emporium/emporium.h
	$(FFLAGS) -c ./classes/emporium/emporium.cpp $(GTKFLAGS)
item.o: ./classes/item/item.cpp ./classes/item/item.h
	$(FFLAGS) -c ./classes/item/item.cpp $(GTKFLAGS)
scoop.o: ./classes/scoop/scoop.cpp ./classes/scoop/scoop.h
	$(FFLAGS) -c ./classes/scoop/scoop.cpp $(GTKFLAGS)


test: test.o container.o item.o
	$(FFLAGS) -o test test.o container.o item.o $(GTKFLAGS)
test.o: test.cpp
	$(FFLAGS) -c -w test.cpp $(GTKFLAGS)
container.o: ./classes/container/container.cpp ./classes/container/container.h
	$(FFLAGS) -c ./classes/container/container.cpp $(GTKFLAGS)

topping.o: ./classes/topping/topping.cpp ./classes/topping/topping.h
	$(FFLAGS) -c ./classes/topping/topping.cpp $(GTKFLAGS)


clean:
	-rm -f *.o enviro test
