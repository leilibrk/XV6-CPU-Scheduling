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
   }
  }


}

int
main(void)
{
  forktest();
  exit();
}
