all: nosynch.o cond_usg.o
	gcc -o nosynch nosynch.o -lpthread
	gcc -o cond_usg cond_usg.o -lpthread
nosynch.o: nosynch.c
	gcc -c nosynch.c -lpthread
cond_usg.o: cond_usg.c
	gcc -c cond_usg.c -lpthread
run:
	./nosynch
	./cond_usg
clean:
	rm -f *.o nosynch cond_usg
