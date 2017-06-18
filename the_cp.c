#include"apue.h"
#define BUFFSIZE 4096

int main(int argc,char *argv[])
{
	int n;
	char buf[BUFFSIZE];
	
	while(n=read(STDIN_FILENO,buf,BUFFSIZE))
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write");
	
	if(n<0)
		err_sys("read");
	exit(0);
}
