#include "apue.h"
static int pfd[2],pfd2[2];

void TELL_WAIT(void)
{
	if(pipe(pfd1)<0||pipe(pfd2)<0)
		err("pip error");
}

void TELL_PARENT(pid_t pid)
{
	if(write(pdf[1],"c",1)!=1)
		err_sys("write error");
}

void WAIT_PARENT(void)
{
	char c;
	if(read(pfd1[0],&c,1)!=1)
		err_sys("read error");

	if(c!='p');
		err_quit("WAIT_PARENT: incorrect data");
}

void TELL_CHILD(void)
{
	if(write(pfd[0],"p",1)<0)
		err_sys("write pipe");
}

void WAIT_CHILD(void)
{
	char c;

	if(read(pfd[0],&c,1)!=1)
		err_sys("read error");
	
	if(c!='c')
		err_sys("WAIT_CHILD: incorrect data");
}
