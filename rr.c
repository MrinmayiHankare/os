#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void rr(int a[],int AT[],int BT[],int remainingtime[],int n,int QT)
{
	int currtime=0;
	int completed=0;
	printf("id\tAT\tBT\tTAT\twaitingtime\n");
	while(completed<n)
	{
		for(int i=0;i<n;i++)
		{
			if(AT[i]<=currtime && remainingtime[i]>0)
			{
				if(remainingtime[i] <= QT)
				{
					currtime += remainingtime[i];
					remainingtime[i]=0;
					completed++;
				
					int turnaroundtime = currtime - AT[i];
					int waitingtime =  turnaroundtime - BT[i];
				
					printf("%d\t%d\t%d\t%d\t%d\n",a[i],AT[i],BT[i],turnaroundtime,waitingtime);
				}
				else
				{
					currtime += QT;
					remainingtime[i] -= QT;
				}
			}
		}
	}
}
int main()
{
	int n;
	printf("enter no. of process=");
	scanf("%d",&n);
	
	int a[n],AT[n],BT[n],remainingtime[n];
	for(int i=0;i<n;i++)
	{
		printf("enter process id=");
		scanf("%d",&a[i]);
		printf("enter process AT=");
		scanf("%d",&AT[i]);
		printf("enter process BT=");
		scanf("%d",&BT[i]);
		
		remainingtime[i]=BT[i];
	}
	int QT;
	printf("enter time quantam=");
	scanf("%d",&QT);
	printf("displaying table:\n");
	printf("id\tAT\tBT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",a[i],AT[i],BT[i]);
	}
	rr(a,AT,BT,remainingtime,n,QT);
	return 0;
}































/*
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void sjf(int a[],int AT[],int BT[],int remainingtime[],int n)
{
	int currtime=0;
	int completed=0;
	printf("\nid\tAT\tBT\tTAT\twaitingtime\n");
	
	while(completed<n)
	{
		int shortesttime=-1;
		for(int i=0;i<n;i++)
		{
			if(AT[i]<= currtime && remainingtime[i]>0)
			{
				if(shortesttime==-1  || remainingtime[i] < remainingtime[shortesttime])
				{
					shortesttime=i;
				}
			}
		}
		if(shortesttime==-1)
		{
			currtime++;
		}
		else
		{
			remainingtime[shortesttime]--;
			currtime++;
			
			if(remainingtime[shortesttime]==0)
			{
				completed++;
				
				int turnaroundtime= currtime - AT[shortesttime];
				int waitingtime = turnaroundtime - BT[shortesttime];
				
				printf("%d\t%d\t%d\t%d\t%d\n",a[shortesttime],AT[shortesttime],BT[shortesttime],
				turnaroundtime,waitingtime);
			}
		}
	}
}
int main()
{
	int n;
	printf("enter no. of process=");
	scanf("%d",&n);
	
	int a[n],AT[n],BT[n],remainingtime[n];
	for(int i=0;i<n;i++)
	{
		printf("enter id of process=");
	        scanf("%d",&a[i]);
	        printf("enter AT of process=");
		scanf("%d",&AT[i]);
		printf("enter BT of process=");
		scanf("%d",&BT[i]);
		
		remainingtime[i]=BT[i];
	}
	
	printf("displaying:");
	printf("\nid\tAT\tBT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",a[i],AT[i],BT[i]);
	}
	
	sjf(a,AT,BT,remainingtime,n);
	return 0;
}
*/
	
	
	
	
	
	
	
	
	


























/*
//#include<iostream>
#include<stdio.h>

void rr(int a[],int AT[],int BT[],int remainingtime[],int n,int QT)
{
	int currtime=0;
	int completed=0;
	printf("\nid\tAT\tBT\tTAT\twaitingtime\n"); 
	while(completed<n)
	{
		for(int i=0;i<n;i++)
		{
			if(AT[i] <= currtime && remainingtime[i] > 0)
			{
				if(remainingtime[i] <= QT)
				{ 
					currtime += remainingtime[i];
					remainingtime[i] = 0;
					completed++;
					
					int turnaroundtime = currtime - AT[i];
					int waitingtime = turnaroundtime - BT[i];
					
					printf("%d\t%d\t%d\t%d\t%d\n",a[i],AT[i],BT[i],turnaroundtime,waitingtime);
				}
				else
				{
					currtime += QT;
					remainingtime[i] -= QT;
				}
			}
		}	
	}
}
int main()
{
	int n,QT;
	printf("enter no. pf process=");
	scanf("%d",&n);
	
	int a[n],AT[n],BT[n],remainingtime[n];
	for (int i=0;i<n;i++)
	{
		printf("enter process id=");
		scanf("%d",&a[i]);
		printf("enter arrival time=");
		scanf("%d",&AT[i]);
		printf("enter burst time=");
		scanf("%d",&BT[i]);
	}
	printf("enter quantam time=");
	scanf("%d",&QT);
	
	for(int i=0;i<n;i++)
	{
		remainingtime[i]=BT[i];
	}
	
	printf("the process are:");
	printf("\nid\tAT\tBT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",a[i],AT[i],BT[i]);
	}
	printf("round robin::\n");

	rr(a,AT,BT,remainingtime,n,QT);
		
	return 0;
}
*/
/*
mrinmayi@mrinmayi-VirtualBox:~$ cd os
mrinmayi@mrinmayi-VirtualBox:~/os$ gcc roundrobin.c
mrinmayi@mrinmayi-VirtualBox:~/os$ ./a.out
Enter the number of processes:4
Enter the Process ID:1
Enter the Process ID:2
Enter the Process ID:3
Enter the Process ID:4
Enter the arrival time:0
Enter the burst time:5
Enter the arrival time:1
Enter the burst time:4
Enter the arrival time:2
Enter the burst time:2
Enter the arrival time:4 
Enter the burst time:1
Enter the quantum time:2
The processes are::
Process	ArrivalTime	BurstTime
1	0		5
2	1		4
3	2		2
4	4		1
Round Robin (Preemptive) Scheduling:

processes	ArrivalTime	BurstTime	Turnaroundtime	WaitingTime
3		2		2		4		2
4		4		1		3		2
2		1		4		10		6
1		0		5		12		7
mrinmayi@mrinmayi-VirtualBox:~/os$ 

*/
