#include "apue.h"
#include <sys/wait.h>

char *env_init[]={"USER=unknown","PATH=/tmp",NULL};
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork");
	else if(pid==0)
	{
		if(execle("/home/sannian/bin/echoall",))
	}
}
