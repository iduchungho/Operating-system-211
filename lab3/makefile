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
pi: pi_mutex.o pi_semaphore.o
	gcc -o pi_mutex pi_mutex.o -lpthread
	gcc -o pi_semaphore pi_semaphore.o -lpthread
pi_mutex.o: pi_mutex.c
	gcc -c pi_mutex.c -lpthread
pi_semaphore.o: pi_semaphore.c
	gcc -c pi_semaphore.c -lpthread
rpi:
	./pi_mutex 100000
	./pi_semaphore 100000
cls:
	rm -f *.o pi_mutex pi_semaphore
