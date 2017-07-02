#include<signal.h>
#include<errno.h>

#define SIGBAD(signo) ((signo)<=0||(signo)>NSIG)

int sigaddset(sigset_t *set,int signo)
{
	
}
