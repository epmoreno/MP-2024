CC = g++
CFLAGS = -Wall
EXEC = main

DEPS = include/c_date.hpp include/c_guest.hpp include/c_hotel.hpp include/c_reservation.hpp include/c_room.hpp include/c_staff.hpp
OBJS = build/c_date.o build/c_guest.o build/c_hotel.o build/c_reservation.o build/c_room.o build/c_staff.o build/main.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

build/%.o: src/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

build/main.o: src/main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f build/*.o $(EXEC)