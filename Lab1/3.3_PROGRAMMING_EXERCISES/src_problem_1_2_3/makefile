all: main.o factorial.o readline.o
	gcc factorial.o main.o readline.o -o myfactorial
factorial.o: factorial.c factorial.h
	gcc -c factorial.c
main.o: main.c factorial.h readline.h
	gcc -c main.c
readline.o: readline.c readline.h
	gcc -c readline.c
clean:
	rm -f *.o myfactorial