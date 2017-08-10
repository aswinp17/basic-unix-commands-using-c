#include <stdio.h>
#include<unistd.h>

int main( int argc , char *argv[])
{   
    if(argc != 2 || argv[1] == "--help")
    {
      printf("\n usage: rmdir DIRNAME");
    }

  char *cmd = "rmdir";
  char *args[3];
  args[0] = "rmdir";
  args[1] = argv[1];
  args[2] = NULL;

  execvp(cmd,argv);
}
  
