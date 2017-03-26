#include <iostream>
#include <thread>
#include <pthread.h>
#include <ctime>
#include "integer_semaphore.h"

#define SEMNUMBER 1
#define NUMTHREAD 100
#define SLEEPTIMEMAX 4000
#define SLEEPTIMEMIN 200

using namespace std;

void *PrintHello(void *threadid);

static IntegerSemaphore integerSemaphore;	

int main(){
	pthread_t threads[NUMTHREAD];
	int rc;
	srand(time(NULL));

	integerSemaphore.Init(SEMNUMBER);

	for (int i = 0; i < NUMTHREAD; ++i) {
		 rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
		 if (rc){
			cout << "Error:unable to create thread: " << rc << endl;
		 }
		 else{
			cout << "Created thread: " << i << endl;
		 }
	}
	pthread_exit(NULL);
}


void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	
	while(true){
		
		int rand_time = rand()%(SLEEPTIMEMAX-SLEEPTIMEMIN + 1) + SLEEPTIMEMIN;
		integerSemaphore.P();
		cout << "Critical section ID: " << tid <<" for "<<rand_time<<" ms"<< endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand_time));
		integerSemaphore.V();
		
	}
	pthread_exit(NULL);
}
