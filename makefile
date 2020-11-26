all: main

main.o: main.c myBank.h
	gcc -Wall -c main.c

myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c

main: main.o myBank.o
	gcc -Wall main.o myBank.o -o main

clean:
	rm -f *.o main

.PHONY: clean all