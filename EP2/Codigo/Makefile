CXX=mpic++#g++
CXXFLAGS=-O3
LDFLAGS=-O3

OBJECTS=main.o sha1.o

sha1: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o sha1 $(OBJECTS)

all:	sha1

run:	all
	mpirun -np 8 ./sha1 #./sha1 # b2cdbf0601d8ae90d3cda1c978566ace86c4eac0


clean:
	rm -f *.optrpt *.o sha1 *~ 
