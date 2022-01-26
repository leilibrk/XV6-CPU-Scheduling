#include "types.h"
#include "stat.h"
#include "user.h"

#define N  60

int main(void){
  int n, pid;
  int size[] = {60, 10, 10, 10, 10, 10, 10};
  changePolicy(2);
  printf(1, "MultiLayered Test\n");

  for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0)
            break;
        if(pid == 0){
            if(n < 10){
                setPriority(1, pid);
            }
            if(n >= 10 && n < 20){
                setPriority(2, pid);
            }
            if(n >= 20 && n < 30){
                setPriority(3, pid);
            }
            if(n >= 30 && n < 40){
                setPriority(4, pid);
            }
            if(n >= 40 && n < 50){
                setPriority(5, pid);
            }
            if(n >= 50){
                setPriority(6, pid);
            }
            for(int i=0 ; i<200 ; i++){
                printf(1, "/%d/ : /%d/ \n", pid, i+1);
            }
            sleep(300);
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