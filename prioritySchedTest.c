#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  int pid;
  changePolicy(1);
  printf(1, "priority Test \n");

  for(int n=0; n<30; n++){
      pid = fork();
      if(pid < 0)
        break;
      if(pid == 0){
        if(n < 5){
            setPriority(6);
        }
        if(n >= 5 && n < 10){
            setPriority(5);
        }
        if(n >= 10 && n < 15){
            setPriority(4);
        }
        if(n >= 15 && n < 20){
            setPriority(3);
        }
        if(n >= 20 && n < 25){
            setPriority(2);
        }
        if(n >= 25){
            setPriority(1);
        }
        for(int i=0 ; i<250 ; i++){
            printf(1, "/%d/ : /%d/ \n", pid, i+1);
        }
        sleep(3000);
        exit();
      }
      
    
  }
  int sumTurnaround = 0;
    int sumWaiting = 0;
    int sumBurst = 0;

    for (int i = 0; i <30 ; i++) {
        int pid = wait();
        int turnAround = getProcStatus(2, pid) - getProcStatus(1, pid);
        int waitingTime = getProcStatus(4, pid);
        int sleeping = getProcStatus(5, pid);
        int cpuBurst = getProcStatus(3, pid);
        sumTurnaround += turnAround;
        sumWaiting += waitingTime;
        sumBurst += cpuBurst;
        printf(1, "pid: %d, ", getpid());
        printf(1, "creation time = %d", getProcStatus(1, pid));
        printf(1, "termination time = %d", getProcStatus(2, pid));
        printf(1, "turnaround time = %d, ", turnAround);
        printf(1, "waiting time = %d, ", waitingTime);
        printf(1, "sleeping time = %d, ", sleeping);
        printf(1, "cpu burst = %d, ", cpuBurst);
        printf(1,"\n");


    }

    int avgTurnaround = sumTurnaround / 10;
    int avgWaiting = sumWaiting / 10;
    int avgCBT = sumBurst / 10;
    printf(1, "average turnaround time: %d",avgTurnaround);
    printf(1, "average waiting time: %d",avgWaiting);
    printf(1, "average cpu burst time: %d",avgCBT);

  exit();
}