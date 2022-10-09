//RITTIK PANDA
//MT2022090
#include <sys/time.h>  
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    int start, end, pid;

    start = __rdtsc();
    pid = getpid();
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d \n", (end - start));
}
