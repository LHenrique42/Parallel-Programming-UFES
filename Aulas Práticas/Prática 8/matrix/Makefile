FLAGS=-O2 -fopenmp

CC=g++

RM=rm -f

EXEC=matrix

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(EXEC).cpp -c -o $(EXEC).o
	$(CC) $(FLAGS) main.cpp -c -o main.o
	$(CC) $(FLAGS) main.o $(EXEC).o -o $(EXEC)

run:
	./$(EXEC)

clean:
	$(RM) main.o $(EXEC).o $(EXEC)
