#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"


int queue[30];
int allWtimes[30];
int allRtimes[30];
void parentWork();
void childWork(int);
int main(int argc, char *argv[])
{
int index=0;
  if(strcmp(SCHFLAG,"3Q")!=0)
    {
      printf(1,"Scheduling type is not on 3 Queues scheduling!!!!!Sorry :( \n");
      exit();
    }
  for(int i=0;i<30;i++)  {
    int newP=fork();
    if(newP<0)
    {
      printf(1,"Problem in Forking Exit :(\n");
      exit();
    }
    else if(newP==0){
      childWork(i);
    }
    else if(newP>0){
      queue[index]=newP;
      index++;
      continue;
    }
  }
parentWork();
exit();

}
void parentWork(){
  int sumWtimes=0;
  int sumRtimes=0;
  int oneQueueWtime=0;
  int oneQueueRtime=0;
  for(int i=0;i<30;i++){
    int wtime;
    int rtime;
    int childPID=getPerformanceData(&wtime,&rtime);
    int j=0;
    for(;j<30;j++)
    {
      if(queue[j]==childPID)
        break;
    }
    allWtimes[j]=wtime;
    allRtimes[j]=rtime;
  }
  for(int i=0;i<30;i++){
    printf(1,"Process %d is in %d queue and has wait Time : %d & turn around time : %d \n",queue[i],((i+1)%3)+1,allWtimes[i],allWtimes[i]+allRtimes[i]);
    sumRtimes+=allRtimes[i];
    sumWtimes+=allWtimes[i];
  }
  for(int i=2;i<5;i++){
    oneQueueRtime=0;
    oneQueueWtime=0;
    for(int j=0;j<30;j++){
      if(j%3!=i%3)
        continue;
      oneQueueWtime+=allWtimes[j];
      oneQueueRtime+=allRtimes[j];
    }
    int trResult =(oneQueueWtime+oneQueueRtime)/10;
    int wResult = oneQueueWtime/10;
    // wResult=wResult;
    printf(1,"%d queue average : wait time = %d \t turn around time = %d \n",i-1,wResult,trResult);
  }
  int trResult =(sumWtimes+sumRtimes)/30;
  int wResult = sumWtimes/30;
  printf(1,"All queues average : wait time = %d \t turn around time = %d \n ",wResult,trResult);
}
void childWork(int cid){
  for(int i=0;i<(cid+1)%3;i++)
  {
    nice();
  }
  for(int i=0;i<500;i++){
    printf(1,"Process %d prints it cid : %d\n",getpid(),cid);
  }
  exit();
}
