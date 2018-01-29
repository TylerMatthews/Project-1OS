//**********************************************************************
// Authors: Tyler Matthews, Matt Monik 
// Date: 01/26/2018
// Program to calculate the time for a System call
//
//
//**********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>

//Return system time
double calctime()
{
	double timeinsec = 0.0;
	struct value ctime;
	gettimeofday(&ctime, (struct timezone *)0);
	timeinsec = (double)(ctime.tv_sec + ctime.tv_usec * 1.0e-3);

	return(timeinsec);
}

int main(int argc, const char * argv[])
{
    
    double beginning ;
    double end;

    //Set thread to one processor
    cpu_set_t  affin;
    CPU_ZERO(&affin);
    unsigned int length = sizeof(affin);
    CPU_SET(0, &affin);
	
    double sysStart, sysStop, sysCallDur, dur, funcCallDur;
    int i,p;
    long k;
    int n;
    printf("Start Running \n");
    long itr_a = 1000000;
    
    //calculate system call cost
    sysStart = calctime();
	for (k = 0; k < itr_a; k++)
    {
		i = getpid();
	}
    //record the time in which the system call operations ends
    sysStop = calctime();

    //system call time
    dur = sysStop - sysStart;

    //estimated system call time
	sysCallDur = (sysStop - sysStart) / itr_a;
	printf("Average system call time is %f\n", sysCallDur);
    
    return(0); 
}

