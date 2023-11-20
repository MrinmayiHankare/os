#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *str=(char *)shmat(shmid,(void *)0,0);
	printf("\nEnter Data:");
	fgets(str,1024,stdin);
	printf("\nWritten data is:%s\n",str);
	shmdt(str);
	return 0;
}
/*
Terminal 1:
mayuri@mayuri-VirtualBox:~$ gcc SHM1.c
mayuri@mayuri-VirtualBox:~$ ./a.out

Enter Data:mayuri

Written data is:mayuri
*/

