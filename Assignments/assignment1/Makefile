all:a1

a1: Date.o Hotel.o Reservation.o Room.o main.o
	g++ -o a1 Date.o Hotel.o Reservation.o Room.o main.o

Date.o: Date.h Date.cc
	g++ -c Date.cc

Hotel.o: Hotel.cc Hotel.h
	g++ -c Hotel.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Room.o: Room.h Room.cc
	g++ -c Room.cc

main.o: main.cc
	g++ -c main.cc

clean:
	rm -f a1 *.o
