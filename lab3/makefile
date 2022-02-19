all: nosynch.o
	gcc -o nosynch nosynch.o -lpthread
nosynch.o: nosynch.c
	gcc -c nosynch.c -lpthread
run:
	./nosynch
clean:
	rm -f *.o nosynch
