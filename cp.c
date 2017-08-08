#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <fcntl.h>
#include <unistd.h>


#define SIZE 1024

int main(int argc, char* argv[])
{
    int source,destination,readbuffer,writebuffer;
    char *buff[SIZE];

    if(argc != 3 || argv[1] =="--help") {
      
        printf("\n usage : cpcmd source deestination\n");
        exit(EXIT_FAILURE);
      }

    source = open(argv[1], O_RDONLY);
    
    if(source == -1) {
       printf("\n error openning file %s errno = %d ",argv[1],errno);
       exit(EXIT_FAILURE);
     }
   
    destination = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
   
    if(destination == -1)
	{
		printf("\nError opening file %s errno = %d\n",argv[2],errno);
		exit(EXIT_FAILURE);
	}
 
	
	while((readbuffer = read(source,buff,SIZE)) > 0)
	{
		if(write(destination,buff,readbuffer) != readbuffer)
			printf("\nError in writing data to \n");
	}
	
	
	if(close(source) == -1)
		printf("\nError in closing file\n");
 
	if(close(destination) == -1)
		printf("\nError in closing file\n");
 
}
