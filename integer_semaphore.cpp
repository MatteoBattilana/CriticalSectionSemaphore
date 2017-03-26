#include "integer_semaphore.h"
#include <iostream>

using namespace std;


void IntegerSemaphore::Init(int value){
	s = value;
	delay.Init(false);
	mutex.Init(true);
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
