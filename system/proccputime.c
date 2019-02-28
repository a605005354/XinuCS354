#include <xinu.h>

syscall	proccputime(
	pid32 pid
){
	uint32	cputime;
	intmask	mask; /*saved mask*/

	mask = disable();
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR; 
	}
	
    if(pid == currpid){
	    cputime = proctab[pid].prcputime;
    }
    else {
        cputime = proctab[pid].prcputime+(QUANTUM - preempt);
    }

    restore(mask);

	return cputime;
}