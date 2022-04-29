//202135553 Yunsehyeon
#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include <string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>

#define MAX_BUF 1024
int main()
{
	pid_t pid,son,dau;
	pid = fork();

	if(pid < 0)
	{
	printf("Fork Failed");
	return 1;
	}
	else if(pid == 0)
	{
		son=getpid();
	}
	else
	{
		pid = fork();
		if(pid == 0)
		{
			dau = getpid();
		}
	}
	if(pid != 0)
	{
		wait(NULL);
	}
	if(getpid()==son)
	{
		
		char buf[1000];
		char * fifo_son = "/homework/hw4_fifo_son";
		int file_desc_son=open(fifo_son, O_RDONLY);
		printf("process son create\n");
		for(int i= 10; i<0; i--)
		{
			if(read(file_desc_son,buf,MAX_BUF)>0)
			{
				if(buf[i]=='0')
					break;
				printf("son : %s\n",buf);
			}
		}
		close(file_desc_son);
	}
	
	if(getpid()==dau)
	{
		
	char buf[1000];
	char * fifo_dau = "/homework/hw4_fifo_dau";
	int file_desc_dau=open(fifo_dau, O_RDONLY);
	printf("process daughter create\n");
	for (int j = 10; j >0; j--)
		{
			if(read(file_desc_dau,buf,MAX_BUF)>0)
			{
				if(buf[j]=='0')
					break;
				printf("daughter : %s\n",buf);
			}
		}
	close(file_desc_dau);
	}
	return 0;
}
