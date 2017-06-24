#include "apue.h"
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
	int fd,i;
	struct timespec times[2];
	struct stat statbuf;
	
	for(i=1;i<argc;i++)
	{
		if(stat(argv[i],&statbuf)<0)
			err_ret("%s:stat error",argv[i]);
		if((fd=open(argv[i],O_RDWR|O_TRUNC))<0)
			err_ret("%s:open error",argv[i]);
		times[0]=statbuf.st_atim;
		times[1]=statbuf.st_mtim;
		if(futimens(fd,times)<0)
			err_ret("%s:futimens error",argv[i]);
		close(fd);
	}
	exit(0);
}
