#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <grp.h>
#include <shadow.h>
#include <stddef.h>
int main()
{
	struct passwd *ptr;
	setpwent();
	while((ptr=getpwent())!=NULL)
		printf("%s\n",ptr->pw_name);
	endpwent();

	printf("\n\n");

	struct spwd *sptr;
	setspent();
	while((sptr=getspent())!=NULL)
		printf("%s\n",sptr->sp_namp);
	endspent();
	
	printf("\n\n");

	struct group *sgrp;
	setgrent();
	while((sgrp=getgrent())!=NULL)
		printf("%s\n",sgrp->gr_name);
	endgrent();
	
		
}
