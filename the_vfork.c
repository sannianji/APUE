#include "apue.h"
#include <unistd.h>
#include <sys/types.h>
int globvar=6;


int main(void)
{
	int var;
	pid_t pid;
	
	var=88;
	printf("before vfork\n");
	if((pid=vfork())<0)
		err_sys("vfork");
	if(pid==0)//child
	{
		globvar++;
		var++;
		printf("%ld\n",(long)getpid());
		_exit(0);
	}
	
	printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
	exit(0);
}
