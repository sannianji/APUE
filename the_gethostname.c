#include <stdio.h>
#include <unistd.h>
#include <limits.h>
int main(void)
{
	char name[_POSIX_HOST_NAME_MAX];
	gethostname(name,sizeof(name));
	printf("%s\n",name);
	return 0;
}
