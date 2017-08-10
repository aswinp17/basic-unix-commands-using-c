#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
  if(argc != 2){
   printf("\n usage is touch FILENAME");
   return EXIT_FAILURE;
   }
   int fp;
   fp = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
   
    if(fp == -1)
	{
		printf("\nError opening file %s errno = %d\n",argv[2],errno);
		exit(EXIT_FAILURE);
	}
    if(close(fp) == -1)
         printf("\n eorror in closing file");
}
