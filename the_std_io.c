#include "apue.h"
int main(void)
{
	int c;
	while ((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("putc");
	if(ferror(stdin))
		err_sys("getc");
	exit(0);
}
