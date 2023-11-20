#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
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
void BinarySearch(int n,int A[],int key,int low,int high)
{
	if(low<=high)
	{
		int mid=low+(high-low)/2;
		if(A[mid]==key)
		{
			printf("\nelement is Found!!");
		}
		else if(A[mid]>key)
		{
			BinarySearch(n,A,key,low,mid-1);
		}
		else
		{
			BinarySearch(n,A,key,mid+1,high);
		}
	}
	else
	{
		printf("\nElement Not Found!!");
	}
}
int main()
{
	int n;
	printf("\nEnter the No. of Elements:");
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the %d Element of Array:",i+1);
		scanf("%d",&A[i]);
	}
	int key;
	printf("\nEnter the Key to Search:");
	scanf("%d",&key);
	pid_t ID=fork();
	if(ID==0)
	{
		printf("\nChild Process is Being Executed");
		printf("\nChild Process ID is:%d",getpid());
		printf("\nChild Process is Sorting Array in Ascending Order");
		Ascending(n,A);
	}
	else
	{
		wait(NULL);
		printf("\nParent Process is Being Executed");
		printf("\nParent Process ID is:%d",getppid());
		printf("\nParent Process is Searching an Element in Array:");
		BinarySearch(n,A,key,0,n-1);
	}
}
/*
Output:
ayuri@mayuri-VirtualBox:~$ gcc Wait.c
mayuri@mayuri-VirtualBox:~$ ./a.out

Enter the No. of Elements:5
Enter the 1 Element of Array:2
Enter the 2 Element of Array:1
Enter the 3 Element of Array:5
Enter the 4 Element of Array:7
Enter the 5 Element of Array:8

Enter the Key to Search:2

Child Process is Being Executed
Child Process ID is:5283
Child Process is Sorting Array in Ascending Order
Ascending Order
1	2	5	7	8	

Parent Process is Being Executed
Parent Process ID is:3677
Parent Process is Searching an Element in Array:
element is Found!!
*/


