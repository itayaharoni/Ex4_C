CC=gcc
FLAGS= -Wall -g 
OBJECTS_FREQUENCY= frequency.o 
OBJECTS_MAIN_FREQUENCY= frequency.c

.PHONY= all clean 
all: frequency

frequency: $(OBJECTS_FREQUENCY)
	$(CC) $(FLAGS) -o frequency $(OBJECTS_FREQUENCY)
frequency.o: $(OBJECTS_MAIN_FREQUENCY)
	$(CC) $(FLAGS) -c $(OBJECTS_MAIN_FREQUENCY)

clean:
	rm -f *.o frequency
