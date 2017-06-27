# Critical Section Semaphore
Copyright 2017 Matteo Battilana - Released under GPL v3 License

## Description
This is a C++11 implementation of the critical section with busywait and thread. This is not the version with the PCB list.

You can compile all the examples with:
```bash
make
```
and then clean the `*.o` file and executable with:
```bash
make clean
```

### Examples

There are two small examples:

#### alternate.cpp
This is the the base syncronization problem. There are two thread, `A` and `B` that runs alternately.

You can compile only this example with:

```bash
make alternate
```

#### mutex_lock.cpp
In this example there are multiple thread trying to enter in a limited number of critical sections.

In this example you can set:

Macro | Information
------------ | -------------
SEMNUMBER | Number of integer semaphores
NUMTHREAD | Number of running thread
SLEEPTIMEMAX | Max random sleep range
SLEEPTIMEMIN | Min random sleep range

You can compile only this example with:

```bash
make mutex_lock
```


## Information
In the `binary_semaphore.h` you can set the `LOWCPUUSAGE` macro. This has been added in order to avoid 100% of the CPU usage during the threads wait. I've also added a sleep in the `V` method because a thread can exit from its critical section and go ahead the others, that are doing the `LOWCPUUSAGE` sleep time.
