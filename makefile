all: run

main.o: main.c myBank.h
	gcc -Wall -c main.c

myBank.o: myBank.c myBank.h
	gcc -Wall -c myBank.c

run: main.o myBank.o
	gcc -Wall main.o myBank.o -o run

clean:
	rm -f *.o run

.PHONY: clean all