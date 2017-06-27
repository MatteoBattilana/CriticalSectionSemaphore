#include <iostream>
#include <thread>
#include "binary_semaphore.h"

using namespace std;

//init integer semaphore, A start first
static BinarySemaphore binarySemaphoreA (true);
static BinarySemaphore binarySemaphoreB (false);

void A();
void B();

int main(){
	srand(time(NULL));

	thread a = thread(A);
	thread b = thread(B);
	a.join();
	b.join();
}

void A(){
	while(true){
		binarySemaphoreA.P();
		cout<<"A ";
		cout.flush();
		binarySemaphoreB.V();
	}
}

void B(){
	while (true) {
		binarySemaphoreB.P();
		cout<<"B ";
		cout.flush();
		binarySemaphoreA.V();
	}
}
