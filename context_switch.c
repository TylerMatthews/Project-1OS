//**********************************************************************
// Authors: Tyler Matthews, Matt Monnik 
// Date: 01/26/2018
// Program to calculate the time for a context switch
//
//**********************************************************************

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>

//Return system time
double calctime()
{
	double timeinsec = 0.0;
	struct timeval ctime;
	gettimeofday(&ctime, (struct timezone *)0);
	timeinsec = (double)(ctime.tv_sec + ctime.tv_usec * 1.0e-3);

	return(timeinsec);
}

int main(int argc, const char * argv[])
{
    
    double beginning ;
    double end;

    //Set thread to one processor
    cpu_set_t affin;
    CPU_ZERO(&affin);
    unsigned int length = sizeof(affin);
    CPU_SET(0, &affin);
    

    int     pipes[2];
    int     byte_l;
    char    pipeString[] = "Pipe message!\n";
    pid_t   childId;
    char    read_buffer[600];
    
    printf("Begin piping: \n");
    
    pipe(pipes);
    if((childId = fork()) == -1)
    {       
        perror("fork");
        exit(1);
    }
    
    beginning = calctime();
   
    if ((sched_setaffinity(0, length, &affin) ) < 1)
    {
        if(childId == 0)       
        {       
            //pipe input closed
            close(pipes[0]);
            //output to pipe
            write(pipes[1], pipeString, (strlen(pipeString)+1));
            exit(0);
        }
        else
        {
    		//Parent reads pipe input
            byte_l = read(pipes[0], read_buffer, sizeof(read_buffer));
            end = calctime();
            printf("Pipe message: %s", read_buffer);
    		printf("Context switch time: %10f \n", end - beginning);
            close(pipes[1]);
            
        }
    }
    return(0);
    
}

