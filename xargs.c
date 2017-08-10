#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <fcntl.h>
#include <unistd.h>


#define SIZE 1024

int main()
{
  char *buff[SIZE];
  int fp,n;
  
  
    while((n = read(STDIN_FILENO, buff, SIZE)) > 0)
    {
		if(write(STDOUT_FILENO,buff,n) != n)
			printf("\nError in writing data to \n");
	}
  
}
