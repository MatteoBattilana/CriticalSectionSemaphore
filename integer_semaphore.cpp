#include "integer_semaphore.h"
#include <iostream>

using namespace std;

IntegerSemaphore::IntegerSemaphore(int value) : mutex(true), delay(false) {
	s = value;
}

void IntegerSemaphore::P(){
	mutex.P();
	s--;
	if(s < 0){
		mutex.V();
		delay.P();
	}
	else
		mutex.V();
}

void IntegerSemaphore::V(){
	mutex.P();
	s++;
	if(s <= 0){
		delay.V();
	}
	mutex.V();
}
