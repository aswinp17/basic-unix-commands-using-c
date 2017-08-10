#include <stdio.h>
#include<unistd.h>

int main( int argc , char *argv[])
{   
    if(argc != 2 || argv[1] == "--help")
    {
      printf("\n usage: mkdir DIRNAME");
    }

  char *cmd = "mkdir";
  char *args[3];
  args[0] = "mkdir";
  args[1] = argv[1];
  args[2] = NULL;

  execvp(cmd,argv);
}
  
