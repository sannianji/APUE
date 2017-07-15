#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void abort(void)
{
	sigset_t mask;
	struct sigaction action;

	sigaction(SIGABRT,NULL,&action);
	if(action.sa_handler==SIG_IGN)
	{
		action.sa_handler=SIG_DFL;
		sigaction(SIGABRT,&action,NULL);
	}

	if(action.sa_handler==SIG_DFL)
		fflush(NULL);
	
	sigfillset(&mask);
	sigdelset(&mask,SIGABRT);
	sigpromask(SIG_SETMASK,&mask,NULL);
	kill(getpid(),SIGABRT);

	fflush(NULL);
	action.sa_handler=SIG_DFL;
	sigaction(SIGABRT,&action,NULL);
	sigpromask(SIG_SETMASK,&nask,NULL);
	kill(getpid(),SIGABRT);
	exit(1);
}
