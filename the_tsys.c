#include "apue.h"
int main(int argc,char *argv[])
{
	int status;
	if(argc<2)
		err_quit("cmdline argument required");
	if((status=system(argv[1]))<0)
		err_sys("system()");
	pr_exit(status);
	exit(0);
}
		
