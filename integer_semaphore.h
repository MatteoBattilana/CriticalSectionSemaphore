#ifndef INTEGERSEMAPHORE_H
#define INTEGERSEMAPHORE_H
#include "binary_semaphore.h"
class IntegerSemaphore
{
	private:
		int s = 1;
		BinarySemaphore mutex;
		BinarySemaphore delay;
	public:
		IntegerSemaphore(int value);
		void P();
		void V();
};

#endif
