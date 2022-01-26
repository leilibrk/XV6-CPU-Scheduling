#include "types.h"
#include "stat.h"
#include "user.h"

#define N  60

int main(void){
  int n, pid , pri;
  changePolicy(2);
  printf(1, "MultiLayered Test\n");

  for(n=0; n<N; n++){
      pid = fork();
      if(pid < 0)
        break;

      if(n < 10){
          setPriority(1);
          pri = 1;
      }
      if(n >= 10 && n < 20){
          setPriority(2);
          pri = 2;
      }
      if(n >= 20 && n < 30){
          setPriority(3);
          pri = 3;
      }
      if(n >= 30 && n < 40){
          setPriority(4);
          pri = 4;
      }
      if(n >= 40 && n < 50){
          setPriority(5);
          pri = 5;
      }
      if(n >= 50){
          setPriority(6);
          pri = 6;
      }
    for(int i=0 ; i<20 ; i++){
        printf(1, "/%d/ : /%d/ : /p %d/ \n", pid, i+1,pri);
        //printf(1, "turnaround time = %d \n", getttime(pid)-getctime(pid) );
        //printf(1, "cpu burst time = %d \n", getrutime(pid));
        //printf(1, "waiting time = %d \n",(getttime(pid)-getctime(pid))-getrutime(pid) );
        sleep(80);
    }
  }
  
  exit();
}