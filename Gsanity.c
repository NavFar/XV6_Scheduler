#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(int argc, char *argv[])
{
  if(strcmp(SCHFLAG,"GRT")!=0)
    {
      printf(1,"Scheduling type is not on Guaranteed scheduling!!!!!Sorry :( \n");
      exit();
    }
  printf(1,"Father pid is %d\n",getpid());
  sleep(1000);
  if(fork()<0){
    printf(1,"Error in forking :(\n");
    exit();
  }
  for(int i=0;i<50;i++){
    printf(1,"Process %d is printing for the %d time(s)\n",getpid(),i);
  }
  exit();
}
