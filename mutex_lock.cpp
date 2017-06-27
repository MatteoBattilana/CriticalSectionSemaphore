#include <iostream>
#include <thread>
#include <ctime>
#include "integer_semaphore.h"

#define SEMNUMBER 4
#define NUMTHREAD 10
#define SLEEPTIMEMAX 4000
#define SLEEPTIMEMIN 200

using namespace std;

//init integer semaphore
static IntegerSemaphore integerSemaphore (SEMNUMBER);

void PrintName(int threadid);

int main(){
	srand(time(NULL));
	thread threads[NUMTHREAD];

	//threads creation
	for (int i = 0; i < NUMTHREAD; ++i) {
		threads[i] = thread(PrintName, i);
		cout << "Created thread: " << i << endl;
	}

	for (int i = 0; i < NUMTHREAD; ++i) {
		threads[i].join();
	}
}


void PrintName(int threadid)
{
	while(true){
		integerSemaphore.P();

		int rand_time = rand()%(SLEEPTIMEMAX-SLEEPTIMEMIN + 1) + SLEEPTIMEMIN;
		cout << "Critical section ID: " << threadid <<" for "<<rand_time<<" ms"<< endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand_time));

		integerSemaphore.V();
	}
}
