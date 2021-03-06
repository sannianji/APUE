#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void daemonize(const char *cmd)
{
	int i,fd0,fd1,fd2;
	pid_t pid;
	struct rlimit r1;
	struct sigaction sa;

	//clear file creation musk

	umask(0);
	
	//get maximum number of file descriptors

	if(getrlimit(RLIMIT_NOFILE,&r1)<0)
		err_quit("%s:can't get file limit",cmd);
	
	//Become a session leader to lose controlling TTY

	if((pid=fork())<0)
		err_quit("%s can't fork",cmd);
	if(pid!=0)//parent
		exit(0);
	setsid();

	//Ensure future opens won't allocate controling TTY

	sa.sa_handler=SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	if(sigaction(SIGHUP,&sa,NULL)<0)
		err_quit("%s: can't ignore SIGHUP",cmd);
	if((pid=fork())<0)
		err_quit("%s: can't fork",cmd);
	if(pid!=0)//parent 
		exit(0);

	//Change the current working directory to the root so
	//we won't prevent file system from being ummounted

	if(chdir("/")<0)
		err_quit("%s: can't change directory to /",cmd);

	//Close all open file descriptors

	if(r1.rlim_max==RLIM_INFINITY)
		r1.rlim_max=1024;
	for(i=0;i<r1.rlim_max;i++)
		close(i);

	//Attach file descriptors 0,1 and 2 to /dev/null

	fd0=open("/dev/null",O_RDWR);
	fd1=dup(0);
	fd2=dup(0);

	//Initialize the log file

	openlog(cmd,LOG_CONS,LOG_DAEMON);
	if(fd0!=0||fd1!=0||fd2!=0)
	{
		syslog(LOG_ERR,"unexpect file descriptors %d %d %d",fd0,fd1,fd2);
		exit(1);
	}

}

int main(void)
{
	printf("start the daemonize\n");
	daemonize("sannianji");
	printf("finish the daemonize\n");
}
