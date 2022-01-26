#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  int pid;
  int size[] = {30, 5, 5, 5, 5, 5, 5};
  changePolicy(1);
  printf(1, "priority Test \n");

  for(int n=0; n<30; n++){
      pid = fork();
      if(pid < 0)
        break;
      if(pid == 0){
        if(n < 5){
            setPriority(6, pid);
        }
        if(n >= 5 && n < 10){
            setPriority(5, pid);
        }
        if(n >= 10 && n < 15){
            setPriority(4, pid);
        }
        if(n >= 15 && n < 20){
            setPriority(3, pid);
        }
        if(n >= 20 && n < 25){
            setPriority(2, pid);
        }
        if(n >= 25){
            setPriority(1, pid);
        }
        for(int i=0 ; i<250 ; i++){
            printf(1, "/%d/ : /%d/ \n", pid, i+1);
        }
        sleep(3000);
        exit();
      }
      
    
  }
    int totalTurnaround[7];
    int totalWaiting[7];
    int totalBurst[7];


    for (int i = 0; i <30 ; ++i) {
        int pid = wait();
        int turnAround = getProcStatus(2, pid) - getProcStatus(1, pid);
        int waitingTime = getProcStatus(4, pid);
        int sleeping = getProcStatus(5, pid);
        int cpuBurst = getProcStatus(3, pid);
        totalTurnaround[0] += turnAround;
        totalWaiting[0] += waitingTime;
        totalBurst[0] += cpuBurst;
        // printf(1, "get priority: \n", getPriority(pid));
        totalTurnaround[getPriority(pid)] += turnAround;
        totalWaiting[getPriority(pid)] += waitingTime;
        totalBurst[getPriority(pid)] += cpuBurst;
        printf(1, "PID: %d | Turnaround Time: %d | Waiting Time: %d"
                  " | CPU Burst Time: %d | Sleeping Time: %d\n", pid, turnAround, waitingTime, cpuBurst, sleeping);
    }

    for (int i = 0; i <7 ; ++i) {
        totalTurnaround[i] = totalTurnaround[i] / size[i];
        totalWaiting[i] = totalWaiting[i] / size[i];
        totalBurst[i] = totalBurst[i] / size[i];
    }
    printf(1, "average turnaround: %d waiting: %d burst: %d \n", totalTurnaround[0], totalWaiting[0], totalBurst[0]);
    for (int i=1;i<7;i++){
        printf(1, "priority: %d average turnaround: %d  waiting: %d  burst: %d \n",
               i, totalTurnaround[i], totalWaiting[i], totalBurst[i]);
    }

    exit();
}