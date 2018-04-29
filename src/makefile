CXXFLAGS += --std=c++14
SRCFLAGS += -I ./
FFLAGS += $(CXX) $(CXXFLAGS) $(SRCFLAGS)

GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o main_window.o main_window_default.o main_window_employee.o main_window_order.o main_window_finalize.o main_window_show_orders.o main_window_keyboard.o order.o serving.o dialogs.o controller.o controller_save.o view.o emporium.o item.o scoop.o container.o topping.o person.o customer.o server.o manager.o owner.o
	$(FFLAGS) -o mice main.o main_window.o main_window_default.o main_window_employee.o main_window_order.o main_window_finalize.o main_window_show_orders.o main_window_keyboard.o order.o serving.o dialogs.o controller.o controller_save.o view.o emporium.o item.o scoop.o container.o topping.o person.o customer.o server.o manager.o owner.o $(GTKFLAGS)
main.o: main.cpp
	$(FFLAGS) -c main.cpp $(GTKFLAGS)
main_window.o: ./classes/main_window/main_window.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window.cpp $(GTKFLAGS)
main_window_default.o: ./classes/main_window/main_window_default.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_default.cpp $(GTKFLAGS)
main_window_employee.o: ./classes/main_window/main_window_employee.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_employee.cpp $(GTKFLAGS)
main_window_order.o: ./classes/main_window/main_window_order.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_order.cpp $(GTKFLAGS)
main_window_finalize.o: ./classes/main_window/main_window_finalize.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_finalize.cpp $(GTKFLAGS)
main_window_show_orders.o: ./classes/main_window/main_window_show_orders.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_show_orders.cpp $(GTKFLAGS)
main_window_keyboard.o: ./classes/main_window/main_window_keyboard.cpp ./classes/main_window/main_window.h
	$(FFLAGS) -c ./classes/main_window/main_window_keyboard.cpp $(GTKFLAGS)
order.o: ./classes/order/order.cpp ./classes/order/order.h
	$(FFLAGS) -c ./classes/order/order.cpp $(GTKFLAGS)
serving.o: ./classes/serving/serving.cpp ./classes/serving/serving.h
	$(FFLAGS) -c ./classes/serving/serving.cpp $(GTKFLAGS)
dialogs.o: ./classes/dialogs/dialogs.cpp ./classes/dialogs/dialogs.h
	$(FFLAGS) -c ./classes/dialogs/dialogs.cpp $(GTKFLAGS)
controller.o: ./classes/controller/controller.cpp ./classes/controller/controller.h
	$(FFLAGS) -c ./classes/controller/controller.cpp $(GTKFLAGS)
controller_save.o: ./classes/controller/controller_save.cpp ./classes/controller/controller.h
	$(FFLAGS) -c ./classes/controller/controller_save.cpp $(GTKFLAGS)
view.o: ./classes/view/view.cpp ./classes/view/view.h
	$(FFLAGS) -c ./classes/view/view.cpp $(GTKFLAGS)
emporium.o: ./classes/emporium/emporium.cpp ./classes/emporium/emporium.h
	$(FFLAGS) -c ./classes/emporium/emporium.cpp $(GTKFLAGS)
item.o: ./classes/item/item.cpp ./classes/item/item.h
	$(FFLAGS) -c ./classes/item/item.cpp $(GTKFLAGS)
scoop.o: ./classes/scoop/scoop.cpp ./classes/scoop/scoop.h
	$(FFLAGS) -c ./classes/scoop/scoop.cpp $(GTKFLAGS)
person.o: ./classes/person/person.cpp ./classes/person/person.h
	$(FFLAGS) -c ./classes/person/person.cpp $(GTKFLAGS)
customer.o: ./classes/customer/customer.cpp ./classes/customer/customer.h
	$(FFLAGS) -c ./classes/customer/customer.cpp $(GTKFLAGS)
server.o: ./classes/server/server.cpp ./classes/server/server.h
	$(FFLAGS) -c ./classes/server/server.cpp $(GTKFLAGS)
manager.o: ./classes/manager/manager.cpp ./classes/manager/manager.h
	$(FFLAGS) -c ./classes/manager/manager.cpp $(GTKFLAGS)
owner.o: ./classes/owner/owner.cpp ./classes/owner/owner.h
	$(FFLAGS) -c ./classes/owner/owner.cpp $(GTKFLAGS)

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
