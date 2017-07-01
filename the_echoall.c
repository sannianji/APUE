#include "apue.h"
int main(int argc,char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;
	
	printf("the cmdline arguments is \n");
	for(i=0;i<argc;i++)
		printf("argv[%d] : %s\n",i,argv[i]);
	
	printf("the environment arguments is :\n");
	for(ptr=environ;*ptr!=NULL;ptr++)
		printf("%s\n",*ptr);
	exit(0);
}
