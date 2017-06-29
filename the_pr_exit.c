#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\t%d\n",WEXITSTATUS(status),status);
	if(WIFSIGNALED(status))
		printf("abnormal termination, exit status = %d\t%d\n",WTERMSIG(status),status,
#ifdef WCOREDUMP
	WCOREDUMP(status)?"(core file generated)":"");	
#else
	"");
#endif
	else if(WIFSTOPPED(status))
		printf("child stopped,signal number=%d\t%d\n",WSTOPSIG(status),status);
}
