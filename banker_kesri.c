#include<stdio.h>

int main()
{
    int alloc[10][10];
    int max[10][10];
    int need[10][10];
    int avl[10];

    int n,m;

    printf("\nEnter number of processe\n");
    scanf("%d",&n);

    printf("\nEnter number of resorces\n");
    scanf("%d",&m);

    printf("\nEnter allocation matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter max matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter avl matrix\n");
    for(int j=0;j<m;j++)
    {
            scanf("%d",&avl[j]);
    }
    printf("...................\n DISPLAYING MATRIX\n...................");

    printf("\nAllocation matrix is \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",alloc[i][j]);
        }
        printf("\n");
    }
     printf("\nmax matrix is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter avl matrix\n");
    for(int j=0;j<m;j++)
    {
        printf("%d\t",avl[j]);
    }
    
    //Calculating need matrix 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("\nNeed matrix is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }

    int finish[n],ans[n],ind=0;

    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>avl[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[ind++]=i;
                    finish[i]=1;
                    for(int k=0;k<m;k++)
                    {
                        avl[k]+=alloc[i][k];

                    }
                    
                }
            }
        }
    }

    int flag=1;

    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            flag=0;
            printf("\n The following system is not in safe seq\n");
            break;
        }
    }

    if(flag==1)
    {
        printf("\n The following is the safe seq\n");
        for(int i=0;i<n;i++)
        {
            printf("%d->",ans[i]);
        }
    }
}

/*
OUTPUT:
mrinmayi@mrinmayi-VirtualBox:~/os$ gcc banker.c
mrinmayi@mrinmayi-VirtualBox:~/os$ ./a.out
enter no. of process=5
enter no. of resources=3

ALLOCATION
0 1 0

2 0 0

3 0 2

2 1 1

0 0 2


MAX
7 5 3

3 2 2 

9 0 2

4 2 2

5 3 3


AVAILABLE
10 5 7

-----------------displaying matrix------------------

AVAILABLE MATRIX
0	1	0	
2	0	0	
3	0	2	
2	1	1	
0	0	2	

MAX MATRIX
7	5	3	
3	2	2	
9	0	2	
4	2	2	
5	3	3	

AVAILABLE MATRIX
1057
NEED MATRIX
7	4	3	
1	2	2	
6	0	0	
2	1	1	
5	3	1	

foll sys is in safe state!!
safe seq:
0	1	2	3	4

*/
