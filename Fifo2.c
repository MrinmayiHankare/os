#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	int fd1,fd2;//file descripter
	char * fifo1="fifo1";
	char * fifo2="fifo2";
	
	char buffer2[100];
	//to store data read from fifo1
	
	sleep(1);
	//Pipe from file 1 to file 2
	
	int wc=0,lc=0,cc=0;
	
	fd1 = open(fifo1, O_RDONLY);
	
	read(fd1, buffer2,sizeof(buffer2));
	
	int i=0;
	while(buffer2[i]!='$')
	{
		if(buffer2[i]==' ' || buffer2[i]=='\n')
		{
			wc++;
		}
		if(buffer2[i]=='\n')
		{
			lc++;
		}
		else
		{
			cc++;
		}
		i++;
	}
	wc++;
	lc++;
	//writing into the file
	FILE* fptr1;
	fptr1 = fopen("f1.txt", "w");
	fprintf(fptr1,"Words :%d\nLines:%d\nCharacters:%d\n",wc,lc,cc);
	
	fclose(fptr1);
	
	printf("User2: %s\n\n", buffer2);
	printf("Words :%d\nLines:%d\nCharacters:%d\n",wc,lc,cc);
	
	
	//Pipe from file 2 to file 1
	mkfifo(fifo2, 0666);
	
	//reading from the file
	
	int arr1[3]={wc,lc,cc};
	FILE* fptr2;
	int ch,num;
	
	fptr2 = fopen("demo.txt", "a");
	fprintf(fptr2,"Words :%d\nLines:%d\nCharacters:%d\n",wc,lc,cc);
	fclose(fptr2);
	
	fd2 = open(fifo2, O_WRONLY);
	write(fd2, arr1,sizeof(arr1));
	close(fd2);
	}
return 0;
}
