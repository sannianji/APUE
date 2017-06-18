#include<dirent.h>
#include"apue.h"
int main(int argc,char *argv[])
{
	if(argc<2)
		err_quit("usage: ls directory_name");
	DIR *dp;
	struct dirent *dirp;
	if((dp=opendir(argv[1]))==NULL)
		err_sys("opendir");
	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
	
	closedir(dp);
	exit(0);
}
