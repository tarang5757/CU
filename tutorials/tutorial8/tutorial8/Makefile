objects = test.o Criteria.o Photo.o Date.o

all: test

test: $(objects)
	g++ -o test $(objects)

test.o: test.cc Criteria.h Photo.h
	g++ -c test.cc 

Criteria.o: Criteria.h Criteria.cc
	g++ -c Criteria.cc
	
Photo.o: Photo.cc Photo.h
	g++ -c Photo.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc
	

clean:
	rm -f test *.o	

