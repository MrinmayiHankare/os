#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int fd1,fd2;
	//file descriment
	
	char * fifo1="fifo1";
	char * fifo2="fifo2";
	//declaring fifo
	
	mkfifo(fifo1, 0666);
	//make fifo1
	
	char arr[40];
	//declaring one char arr
	
	int i;
	for( i = 0; i < sizeof(arr); i +=2 )
	{
		 scanf("%c%c",&arr[i],&arr[i+1]);
		 if( arr[i] == '\n' && arr[i+1] == '\n' )
		 break;
	}
	arr[i]='$';
	//for loop to take char input
	
	//int buffer1[100], buffer2[100];
	int buffer1[3];
	// buffer to store no of words lines char
	
	
	//Pipe from file 1 to file 2
	fd1 = open(fifo1, O_WRONLY);
	write(fd1, arr, strlen(arr)+1);
	close(fd1);
	sleep(2);
	
	//Pipe from file 2 to file 1
	fd2 = open(fifo2, O_RDONLY);
	read(fd2, buffer1,sizeof(buffer1));
	printf("User1: \n\nWords :%d\nLines:%d\nCharacters:%d\n",
	buffer1[0],buffer1[1],buffer1[2]);
	close(fd2);
}
return 0;
}
