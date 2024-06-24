#include "shell.h"

/*
 *@main () : The main fuction that carries the forking process.
 *if (pidd == -1): forking condition to check is parent process id is accurate
 *pid_t = fork() : It is the process id of the child.
 *Return : 0.
 */

int main(void)

{
    pid_t ppid;
    pidd = fork();

    

    while (1)
    {
        if (pidd == -1)
        {
            printf("Error forking");
            exit(EXIT_FAILURE);
        }
        else

            if (pid == 0)
        {

            printf("Forking went successful");
            exit(EXIT_SUCCESS);
        }
    }
}
