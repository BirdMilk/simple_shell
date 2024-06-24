#include "shell.h"

/*
 *@pid_t wait(): The main fuction that carries the waiting process.
 *@pid_t WAIT_CHILD: The process of the initial fork that waits for the child pid.
 *pid_t = fork() : It is the process id of the child.
 *Return : 0.
 */

pid_t wait(int * stat){

    pid_t WAIT_CHILD;

    do
    {
        while (1)
        {
            if (fock() == 0)
            {
                perror("Error focking");
                exit(EXIT_FAILURE);
            }
            else
            {
                WAIT_CHILD = wait(*stat);

                printf("PPID = %d\n", getpid());
                printf("CPID %d\n", WAIT_CHILD);
            }
        }
        
        
    } while (1);
    
}

/*
 *@int main(): main function that calls the wait() function.
 *Return : 0.
 */

int main(){

    wait(int *stat); 
    return 0;
}
