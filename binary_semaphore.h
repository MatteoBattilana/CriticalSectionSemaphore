#ifndef BINARYSEMAPHORE_H
#define BINARYSEMAPHORE_H
#include <atomic>
class BinarySemaphore
{
	private:
		std::atomic<bool> s;
	public:
		void Init(bool value);
		void P();
		void V();
};

#endif
