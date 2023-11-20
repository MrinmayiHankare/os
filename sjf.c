#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void sjf(int a[],int AT[],int BT[],int remainingtime[],int n)
{
	int currtime=0;
	int completed=0;
	printf("id\tAT\tBT\tTAT\twaitingtime\n");
	while(completed<n)
	{
		int shortesttime=-1;
		for(int i=0;i<n;i++)
		{
			if(AT[i]<=currtime && remainingtime[i]>0)
			{
				if(shortesttime==-1 || remainingtime[i] < remainingtime[shortesttime])
				{
					shortesttime = i;
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
				
				int turnaroundtime = currtime - AT[shortesttime];
				int waitingtime =  turnaroundtime - BT[shortesttime];
				
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
		printf("enter process id=");
		scanf("%d",&a[i]);
		printf("enter process AT=");
		scanf("%d",&AT[i]);
		printf("enter process BT=");
		scanf("%d",&BT[i]);
		
		remainingtime[i]=BT[i];
	}
	printf("displaying table:\n");
	printf("id\tAT\tBT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",a[i],AT[i],BT[i]);
	}
	sjf(a,AT,BT,remainingtime,n);
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
	
	
	
	
	
	
	
	
	
