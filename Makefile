.PHONY:	all clean

all:			main_semaphore.cpp int_semaphore.o bin_semaphore.o
			g++ main_semaphore.cpp int_semaphore.o bin_semaphore.o -std=c++11 -pthread

bin_semaphore.o:	bin_semaphore.cpp
			g++ -std=c++11 bin_semaphore.cpp -c

int_semaphore.o: 	int_semaphore.cpp bin_semaphore.o
			g++ -std=c++11 int_semaphore.cpp bin_semaphore.o -c
clean:
			/bin/rm -f *.o
