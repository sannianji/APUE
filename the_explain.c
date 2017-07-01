#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork");
	
	else if(pid==0)
		if(execlp("p","testinterp","myarg1","MY ARG2",(char *)0)<0)
			err_sys("execl");
	if(waitpid(pid,NULL,0)<0)
		err_sys("waitpid");
	
	exit(0);
}
