using namespace std;

#include "bin_semaphore.h"
#include <iostream>
#include <atomic>
#include <thread>


void P_bin(atomic<bool> &s){
	while(!s.exchange(false)){
		#ifdef LOWCPUUSAGE
			std::this_thread::sleep_for(std::chrono::milliseconds(LOWCPUUSAGE));
		#endif
	}
}

void V_bin(atomic<bool> &s){
	s = true;
	#ifdef LOWCPUUSAGE
		std::this_thread::sleep_for(std::chrono::milliseconds(LOWCPUUSAGE*5));
	#endif
}