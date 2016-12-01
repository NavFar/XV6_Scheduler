#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  printf(0,"I\'m the parent and about to create a new Child :)\n");
  int result = fork();
  if(result<0)
  {
    printf(0,"it is me parent but i cant have a child :(\n");
  }
  else if(result==0)
  {
    printf(0,"i\'m the child and my parent process ID is :\t %d  \n while my process ID is :\t %d \n",getppid(),getpid());
  }
  else if(result>0) {
    printf(0,"i\'m parent and i have a child :) \n my process ID is :\t %d \n",getpid());
    wait();
  }

  exit();
}
