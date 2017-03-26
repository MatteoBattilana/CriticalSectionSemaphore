# Critical Section Semaphore
Copyright 2017 Matteo Battilana - Released under GPL v3 License

## Description
This is a C++11 implementation of the critical section without busywait. This is not the struct version with a PCB list.

You can compile this project with:
```bash
make
```
and then clean the `*.o` file with:
```bash
make clean
```

## Description
In the `binary_semaphore.h` you can set the `LOWCPUUSAGE` macro. This has been added in order to avoid 100% of the CPU usage during the threads wait. I've also added a sleep in the `V` method because a thread can exit from its critical section and go ahead the others, that are doing the `LOWCPUUSAGE` sleep time.

In the `main_semaphore.cpp` you can set:

Macro | Information
------------ | -------------
SEMNUMBER | Number of integer semaphores
NUMTHREAD | Number of running thread
SLEEPTIMEMAX | Max random sleep range 
SLEEPTIMEMIN | Min random sleep range 
