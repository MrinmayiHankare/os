#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	char *a[]= {"./b.out","1","2","3","4",NULL };

	pid_t pid=fork();
	if(pid==0)
	{
		execv(a[0],a);
	}
	else
	{
		wait();
	}
	return 0;
}









































/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	pid_t pid = fork();
	char *a[]= {"./b.out","1","2","3","4",NULL};
	if(pid==0)
	{
		execv(a[0],a);
	}
	else
	{
		wait();
	}

	return 0;
}*/
