using namespace std;

#include "int_semaphore.h"
#include "bin_semaphore.h"
#include <iostream>

extern int s = 1;
extern atomic <bool> mutex (true);
extern atomic <bool> delay (false);

void init(int value){
	s = value;
}

void P(){
	P_bin(mutex);
	s--;
	if(s < 0){
		V_bin(mutex);
		P_bin(delay);
	}
	else
		V_bin(mutex);
}

void V(){
	P_bin(mutex);
	s++;
	if(s <= 0){
		V_bin(delay);
	}
	V_bin(mutex);
}
