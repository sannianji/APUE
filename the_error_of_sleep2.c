#include "apue.h"

unsigned int sleep2(unsigned int);
static void sig_int(int);

int main(void)
{
	unsigned int unslept;
	if(signal(SIGINT,sig_int)==SIG_ERR)
		err_sys("signal (SIGINT) error");
	unslept=sleep2(5);
	printf("sleep2 returned\n %u\n",unslept);
	exit(0);
}

static void sig_int(int signo)
{
	int i,j;
	volatile int k;
	printf("\nsig_int starting \n");
	for(i=0;i<3000000;i++)
		for(j=0;j<4000;j++)
			k+=j*i;
	printf("sig_int finished\n");
}
