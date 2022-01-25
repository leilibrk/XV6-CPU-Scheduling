#include "types.h"
#include "stat.h"
#include "user.h"

#define N  10

void
forktest(void)
{
  int n, pid;

  printf(1, "Round Robin Test\n");

  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0)
      exit(); 
    if( pid > 0){
      for(int i=0 ; i<1000 ; i++){
              printf(1, "/%d/ : /%d/ \n", pid, i+1);
      }
      printf(1, "pid: %d\n", pid);
      printf(1, "turnaround time = %d \n", getttime(pid)-getctime(pid) );
      printf(1, "cpu burst time = %d \n", getrutime(pid));
      printf(1, "waiting time = %d \n",(getttime(pid)-getctime(pid))-getrutime(pid) );
      wait();
   }
  }



}

int
main(void)
{
  forktest();
  exit();
}
