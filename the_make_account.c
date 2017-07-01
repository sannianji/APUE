#include "apue.h"
int main(void)
{
	pid_t pid;
	if((pid=fork())<0)
		err_sys("fork");
	
	else if(pid!=0)
	{
		sleep(2);
		exit(0);
	}
	
	if((pid=fork())<0)
		err_sys("fork");
	else if(pid!=0)
	{
		sleep(4);
		abourt();
	}
	if((pid=fork())<0)
		err_sys("fork");
	else if(pid!=0)
	{
		execl("/bin/dd","dd","if=/etc/passwd","of=/dev/null",NULL);
		exit(7);
	}
	
	if((pid=fork())<0)
		err_sys("fork");
	else if(pid!=0)
	{
		sleep(8);
		exit((0);
	}
	
	sleep(6);
	kill(getpid(),SIGKILL);
	exit(6);
}
