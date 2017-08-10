#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

 if(argc != 2 || argv[1] == "--help")
   printf("\n usage rm FILENAME");

 int status;

 status =  unlink(argv[1]);

 if(status == 0)
 printf("\n succesful");
  else
  printf("\n unsuccesfull ");
}
