#include "apue.h"

#define BSZ 48

int main()
{
	FILE *fp;
	char buf[BSZ];
	
	memset(buf,'a',BSZ-2);
	buf[BSZ-2]='\0';
	buf[BSZ-1]='X';
	printf("at first time the buf is :%s\n",buf);
	if((fp=fmemopen(buf,BSZ,"w+"))==NULL)
		err_sys("fmemopen failed");
	printf("initial buffer contents: %s\n",buf);
	fprintf(fp,"helloworld");
	printf("before flush:%s\n",buf);
	fflush(fp);
	printf("after flush:%s\n",buf);
	printf("len of string in buf = %ld\n",(long)strlen(buf));

	memset(buf,'b',BSZ-2);
	buf[BSZ-2]='\0';
	buf[BSZ-1]='X';
	fprintf(fp,"helloworld");
	fseek(fp,0,SEEK_SET);
	printf("after fseek:%s\n",buf);
	printf("len of string in buf=%ld\n",(long) strlen(buf));
	
	memset(buf,'c',BSZ-2);
	buf[BSZ-2]='\0';
	buf[BSZ-1]='X';
	fprintf(fp,"helloworld");
	fclose(fp);
	printf("after close:%s\n",buf);
	printf("len of string in buf=%ld\n",(long) strlen(buf));
	
	return 0;
}
