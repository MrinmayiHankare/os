#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	key_t key=ftok("shmfile",65);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *str=(char *)shmat(shmid,(void *)0,0);
	printf("\nData Read From Memory is:%s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
}
/*
Output:
mayuri@mayuri-VirtualBox:~$ gcc SHM2.c
mayuri@mayuri-VirtualBox:~$ ./a.out

Data Read From Memory is:mayuri
*/

