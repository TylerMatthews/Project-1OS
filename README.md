# Project-1OS


Issues we ran into:
- using ctime was giving an issue, saying a size was not defined. Eventually we figured out depending on the compiler, you had to use either "#include <sys/time.h>" or "#include <time.h>". We also found you had to use "#define _GNU_SOURCE".
- 





Things we learned:
- I had never tried to set a process to a specific CPU, or limit the CPU it could run on. It was a neat thing to learn you could do.
- I have not thought of mesuring context switch time, as we usually think of it as irrelevant. However, if multiple processes require many context switches, I see how that could begin to slow down a program. Trying to find a way around it might be worth looking into.
- Trying to optemize the number of system calls, and how an when they are called could become important. This could be especially important in processor intensive programs that have a specific amount of time they are allowed.
