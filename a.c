#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void binary(int a[],int key,int low,int high)
{
	if(low<=high)
	{
		int mid=low + (high-low)/2;
		if(a[mid]==key)
		{
			printf("element found!!\n");
		}
		else if(a[mid]>key)
		{
			binary(a,key,low,mid-1);
		}
		else
		{
			binary(a,key,mid+1,high);
		}
	}
	else
	{
		printf("element not found!!\n");
	}
}	
int main(int argc,char *argv[])
{
	int a[argc-1],key,low,high;
	for(int i=1;i<argc;i++)
	{
		a[i-1] = atoi(argv[i]);
	}

	low=0;
	high=argc - 1;
	
	printf("enter key you want to search=");
	scanf("%d",&key);
	
	binary(a,key,low,high);
}































/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void binary(int a[],int key,int low,int high)
{
	if(low<=high)
	{
		int mid=low + (high-low)/2;
		if(a[mid]==key)
		{
			printf("element found!!\n");
		}
		else if(a[mid]>key)
		{
			binary(a,key,low,mid-1);
		}
		else
		{
			binary(a,key,mid+1,low);
		}
	}
	else
	{
		printf("element not found!!\n");
	}
}
int main(int arg,char *argv[])
{
	int a[argc-1],key,low,high;
	for(int i=1;i<argc;i++)
	{
		a[i-1] = atoi(argv[i]);
	}

	low=0;
	high=argc - 1;

	printf("enter element you want to search=");
	scanf("%d",&key);
	
	binary(a,key,low,high);
	return 0;
}
	
*/







