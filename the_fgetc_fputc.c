#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	
	while(fgets(buf,MAXLINE,stdin)!=NULL)
		if(fputs(buf,stdout)==EOF)
			err_sys("output");
	if(ferror(stdin))
		err_sys("input");
	exit(0);
}
