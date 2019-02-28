
#include <xinu.h>

syscall	procage(
	pid32 pid
){
	uint32	clocktime;
	intmask	mask; /*saved mask*/
		
	mask = disable();
	if (isbadpid(pid)) {
		restore(mask);
		return SYSERR; 
	}
	
	clocktime = proctab[pid].prbdate;
	restore(mask);

	return clocktime;
}