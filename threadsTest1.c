#include "types.h"
#include "stat.h"
#include "user.h"
int stack[4096];
int x = 0;

int main(int argc, char *argv[]){
    //int tid = fork();
    int tid = thread_create(stack, 0);
    if(tid < 0){
        printf(2, "error\n");
    }else if(tid == 0){
        //child
        for(;;){
            x++;
            sleep(100);
        }
    } else{
        //parent
        for(;;){
            printf(1, "x = %d\n", x);
            sleep(100);
        }
    }
    exit();
}