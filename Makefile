.PHONY:	all clean mutex_lock alternate

all: 									mutex_lock alternate

mutex_lock:						mutex_lock.cpp integer_semaphore.o binary_semaphore.o
											g++ mutex_lock.cpp integer_semaphore.o binary_semaphore.o -std=c++11 -pthread -o mutex_lock

alternate:						alternate.cpp integer_semaphore.o binary_semaphore.o
											g++ alternate.cpp integer_semaphore.o binary_semaphore.o -std=c++11 -pthread -o alternate

binary_semaphore.o:		binary_semaphore.cpp
											g++ -std=c++11 binary_semaphore.cpp -c

integer_semaphore.o:	integer_semaphore.cpp
											g++ -std=c++11 integer_semaphore.cpp -c
clean:
											/bin/rm -f *.o
											/bin/rm -f mutex_lock
											/bin/rm -f alternate
											/bin/rm -f a.out
