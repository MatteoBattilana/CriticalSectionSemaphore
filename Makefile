.PHONY:	all clean

all:			main_semaphore.cpp integer_semaphore.o binary_semaphore.o
			g++ main_semaphore.cpp integer_semaphore.o binary_semaphore.o -std=c++11 -pthread

binary_semaphore.o:	binary_semaphore.cpp
			g++ -std=c++11 binary_semaphore.cpp -c

integer_semaphore.o: 	integer_semaphore.cpp
			g++ -std=c++11 integer_semaphore.cpp -c
clean:
			/bin/rm -f *.o
