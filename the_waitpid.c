#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork");
	else if (pid==0)
	{
		if((pid=fork())<0)
			err_sys("fork error");
		else if(pid>0)
			exit(0);
		else if(pid==0){
		sleep(10);
		printf("second child ,parent pid=%ld\n",(long)getppid());
		exit(0);
		}
	}
	if(waitpid(pid,NULL,0)!=pid)
		err_sys("waitpid");
	exit(0);
}
