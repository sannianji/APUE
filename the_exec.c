#include "apue.h"
#include <sys/wait.h>

char *env_init[]={"USER=unknown","PATH=/tmp",NULL};

int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork");
	else if(pid ==0)
	{
		if(execle("/home/sannian/apue/the_echoall","myargl","MY  ARG2",(char *)0,env_init)<0)
		err_sys("execle");
	}
	if(waitpid(pid,NULL,0)<0)
		err_sys("waitpid");

	if((pid=fork())<0)
		err_sys("fork");
	else if(pid==0)//child
		if(execlp("the_echoall","echoall","only 1 arg",(char *)0)<0)
			err_sys("execlp");
	
	exit(0);
}
