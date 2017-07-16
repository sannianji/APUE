#include "apue.h"
#include <pthread.h>

int makethread(void *(*fn)(void *),void *arg)
{
	int err;
	pthread_t tid;
	pthread_attr_t attr;
	
	err=pthread_attr_init(&attr);
	if(err!=0)
		return (err);
	err=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(err==0)
		pthread_create(&tid,&attr,fn,arg);
	pthread_attr_destroy(&attr);
	return (err);
}

void* thrfn(void* a)
{
//	setbuf(stdout,NULL);
//	printf("create detach thread success\n");
//	fflush(stdout);
	char *s="create detach thread success write\n";
	if(write(STDIN_FILENO,s,strlen(s))!=strlen(s))
		err_sys("write");
}

int main()
{
	int a;
	a=makethread(&thrfn,NULL);
	printf("%d\n",a);
	sleep(2);
	return 0;
}
