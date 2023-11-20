#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>r
void Display(int n,int A[])
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}
void Ascending(int n,int A[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	printf("\nAscending Order");
	Display(n,A);
}
void Descending(int n,int A[])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]<A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	printf("\nDescending Order");
	Display(n,A);
}
int main()
{
	int n;
	printf("\nEnter the No. of Elements:");
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the %d Element:",i+1);
		scanf("%d",&A[i]);
	}
	pid_t ID=fork();
	if(ID==0)
	{
		sleep(10);
		printf("\nChild Process is Being Executed");
		printf("\nChild Process ID is:%d",getpid());
		printf("\nChild Process is Sorting Array in Ascending Order");
		Ascending(n,A);
	}
	else
	{
		printf("\nParent Process is Being Executed");
		printf("\nParent Process ID is:%d",getppid());
		printf("\nParent Process is Sorting Array in Descending Order");
		Descending(n,A);
	}
}
/*
Output:
mayuri@mayuri-VirtualBox:~$ gcc Fork.c
mayuri@mayuri-VirtualBox:~$ ./a.out

Enter the No. of Elements:5
Enter the 1 Element:1
Enter the 2 Element:0
Enter the 3 Element:8
Enter the 4 Element:6
Enter the 5 Element:4

Parent Process is Being Executed
Parent Process ID is:3677
Parent Process is Sorting Array in Descending Order
Descending Order
8 6 4 1 0
(After 10 seconds)
mayuri@mayuri-VirtualBox:~$
Child Process is Being Executed
Child Process ID is:5906
Child Process is Sorting Array in Ascending Order
Ascending Order
0 1 4 6 8
*/

