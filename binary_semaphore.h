#ifndef BINARYSEMAPHORE_H
#define BINARYSEMAPHORE_H
#define LOWCPUUSAGE 10
#include <atomic>
class BinarySemaphore
{
	private:
		std::atomic<bool> s;
	public:
		BinarySemaphore(bool value);
		void P();
		void V();
};

#endif
