#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void childWork();
void parentWork();
int main(int argc, char *argv[])
{
  if(strcmp(SCHFLAG,"RR")!=0)
    {
      printf(1,"Scheduling type is not on Round Robin!!!!!Sorry :( \n");
      exit();
    }
    for(int i=0;i<10;i++){
      int newP=fork();

      if(newP<0){
        printf(1,"Problem in forking Exit \n");
      }
      else if(newP==0){
        childWork();
      }
      else if(newP>0){
        continue;
      }
    }
    parentWork();
    exit();

}
void childWork(){
  for(int i =0;i<1000;i++){
    printf(1,"Child %d prints for %d time(s)\n",getpid(),i);
  }
  exit();
}
void parentWork(){
  int allWtimes[10];
  int allRtimes[10];
  int allPids[10];
  for(int i =0;i<10;i++){
    int wtime;
    int rtime;
    int pid=getPerformanceData(&wtime,&rtime);
    allWtimes[i]=wtime;
    allRtimes[i]=rtime;
    allPids[i]=pid;
  }

  for(int i=0;i<10;i++){
    printf(1,"Parent prints child %d status--> running time :%d \t wait time : %d \t turn around time :%d \n",allPids[i],allRtimes[i],allWtimes[i],allRtimes[i]+allWtimes[i]);
    sleep(5);
  }
}
