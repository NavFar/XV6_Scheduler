#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void childWork();
void parentWork();

int main(int argc, char *argv[])
{
  if(strcmp(SCHFLAG,"FRR")!=0)
    {
      printf(1,"Scheduling type is not on FIFO Round Robin!!!!!Sorry :( \n");
      exit();
    }
  startPrinting();
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
  endPrinting();
  exit();

}
void childWork(){
  for(int i=0;i<1000;i++)
    sleep(1);
  exit();
}
void parentWork(){
  for(int i=0;i<10;i++){
    wait();
  }

}
