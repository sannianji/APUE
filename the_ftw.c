#include "apue.h"
#include <dirent.h>
#include <limits.h>
typedef int Myfunc(const char *,const struct stat *,int);

static Myfunc myfunc;
static int myftw(char *,Myfunc *);
static int dopath(Myfunc *);
static long nreg,ndir,nblk,nchr,nfifo,nslink,nsock,ntot;

int main(int argc,char *argv[])
{
	int ret;
	if(argc!=2)
		err_quit("usage: ftw <starting_pathname>");
	ret=myftw(argv[1],myfunc);
	ntot=nreg+ndir+nblk+nfifo+nslink+nsock;
	if(ntot==0)
		ntot=1;
	printf("regular files =\t %7ld,%5.2f %%\n",nreg,nreg*100.0/ntot);
	printf("directories =\t %7ld,%5.2f %%\n",ndir,ndir*100.0/ntot);
	printf("block special =\t %7ld,%5.2f %%\n",nblk,nblk*100.0/ntot);
	printf("char special=\t %7ld,%5.2f %%\n",nchr,nchr*100.0/ntot);
	printf("FIFOs =\t %7ld,%5.2f %%\n",nfifo,nfifo*100.0/ntot);
	printf("symbolic links=\t %7ld,%5.2f %%\n",nslink,nslink*100.0/ntot);
	printf("sockets =\t %7ld,%5.2f %%\n",nsock,nsock*100.0/ntot);
	exit(ret);	
}

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4

static char *fullpath;
static size_t pathlen;

static int myftw(char *pathname,Myfunc *func)
{
	fullpath=path_alloc(&pathlen);
}
