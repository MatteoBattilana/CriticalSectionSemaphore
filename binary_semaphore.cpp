#include <atomic>
#include <thread>
#include "binary_semaphore.h"

BinarySemaphore::BinarySemaphore(bool value){
	s = value;
}

void BinarySemaphore::P(){
	while(!s.exchange(false)){
		#ifdef LOWCPUUSAGE
			std::this_thread::sleep_for(std::chrono::milliseconds(LOWCPUUSAGE));
		#endif
	}
}

void BinarySemaphore::V(){
	s = true;
	#ifdef LOWCPUUSAGE
		std::this_thread::sleep_for(std::chrono::milliseconds(LOWCPUUSAGE*5));
	#endif
}
