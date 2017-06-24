#include "apue.h"
int main(void)
{
	if(chdir("/home/sannian")<0)
		err_sys("chdir failed");
	printf("chdir to /tmp successed \n");
	system("pwd");
	exit(0);
}
