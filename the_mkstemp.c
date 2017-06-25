#include "apue.h"
#include <stdlib.h>
#include <error.h>

void make_temp(char *);
int main(int argc,char *argv[])
{
	char good_template[]="/tmp/dirXXXXXX";//rigt way
	char *bad_template="/tmp/dirXXXXX";//wrong way
	
	printf("trying to create first temp file ..\n");
	make_temp(good_template);
	printf("trying to create second temp file ..\n");
	make_temp(bad_template);
	exit(0);
}

void make_temp(char *template)
{
	int fd;
	struct stat sbuf;
	if ((fd=mkstemp(template))<0)
		err_sys("mkstemp");
	close(fd);

	if(stat(template,&sbuf)<0)
		if(errno==ENOENT)
			printf("file doesn't exit\n");
		else
			err_sys("stat fail");
	else
	{
		printf("file exit\n");
		unlink(template);
	}
}
