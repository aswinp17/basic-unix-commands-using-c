#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <fcntl.h>
#include <unistd.h>


#define SIZE 1024
int main()
{ 
 int fp, n;
 char *buff[SIZE];
  
  fp = open("temp.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
   
    if(fp == -1)
	{
		printf("\nError opening file %s errno = %d\n","temp.txt",errno);
		exit(EXIT_FAILURE);
	}
 
	
 while((n = read(STDIN_FILENO, buff, SIZE)) > 0)
   {
		if(write(fp,buff,n) != n)
			printf("\nError in writing data to \n");
	}
 if(close(fp) == -1)
		printf("\nError in closing file\n");
 
   fp = open("temp.txt", O_RDONLY);
   
    if(fp == -1)
	{
		printf("\nError opening file %s errno = %d\n","temp.txt",errno);
		exit(EXIT_FAILURE);
	}
   while((n = read(fp, buff, SIZE)) > 0)
    {
		if(write(STDOUT_FILENO,buff,n) != n)
			printf("\nError in writing data to \n");
	}
  if(close(fp) == -1)
		printf("\nError in closing file\n");
 }
