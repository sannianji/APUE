#include "apue.h"
static void sig_quit(int);

int main(void)
{
	sigset_t newmask,oldmask,pendmask;
	
	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
		err_sys("can't catch SIGQUIT");
	
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		err_sys("SIG_BLOCK error");
	
	sleep(5);
	
	if(sigpending(&pendmask)<0)
		err_sys("sigpending error");
	if(sigismember(&pendmask,SIGQUIT))
		printf("\nSIGQUIT pending\n");
	
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		err_sys("sigprocmask");
	printf("SIGQUIT unblocked\n");
	sleep(5);
	exit(0);
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT,sig_quit)<0)
		err_sys("can't reset signal SIGQUIT");
}
