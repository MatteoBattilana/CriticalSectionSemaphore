#define LOWCPUUSAGE 10
#ifndef BINSEMAPHORE_H
#define BINSEMAPHORE_H
#include <atomic>

void P_bin(atomic<bool> &s);
void V_bin(atomic<bool> &s);

#endif