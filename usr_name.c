#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
int main()
{
	struct passwd *ptr;
	setpwent();
	while((ptr=getpwent())!=NULL)
		printf("%s\n",ptr->pw_name);
	endpwent();
	
}
