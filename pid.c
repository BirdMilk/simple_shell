#include "shell.h"

/*
 *@main () : The main fuction that carries the forking process.
 *if(pid == -1): forking condition to check is process id is accurate
 *pid_t = fork() : It is the process id of the child.
 *Return : 0.
 */

int main(void)

{
     pid_t pid;
     pid = fork();


     while (1)
     {
        if(pid == -1){
            printf("Error forking");
            exit(EXIT_FAILURE);
        }else

        if(pid == 0){

            printf("Forking went successful");
            exit(EXIT_SUCCESS);
        }
     }
     
    

}
