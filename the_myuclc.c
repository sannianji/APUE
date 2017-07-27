#include "apue.h"
#include <sys/wait.h>
int main(void)
{
	char line[MAXLINE];
	FILE *fpin;
	
	if((fpin=popen("./the_upper_to_lower","r"))==NULL)
		err_sys("open error");
	for(;;)
	{
		fputs("prompt> ",stdout);
		fflush(stdout);
		if(fgets(line,MAXLINE,fpin)==NULL)
			break;
		if(fputs(line,stdout)==EOF)
			err_sys("fputs error to pipe");
	}
	if(pclose(fpin)==-1)
		err_sys("pclose error");
	putchar('\n');
	exit(0);
}
