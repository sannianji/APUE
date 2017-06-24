#include "apue.h"
#include "pathalloc.c"
int main(void)
{
	char *ptr;
	size_t size;
	if(chdir("/home/sannian")>0)
		err_sys("chdir");
	ptr=path_alloc(&size);
	if(getcwd(ptr,size)==NULL)
		err_sys("getcwd failed");
	printf("cwd=%s\n",ptr);
	exit(0);

}
