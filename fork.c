#include"shell.h"


/*
*@main () : The main fuction that carries the forking process.
*@typedef pid_t pid_t : It is the process id of the initial fork.
*pid_t = fork() : It is the process id of the child.
*Return : 0.
*/

int main(){


  typedef pid_t pid_t;

  pid_t = fork();


  do
  {
    

     while (1)
     {
        if (pid_t == -1)
        {
             perror("Error forking");
             exit(EXIT_FAILURE);

        }
        else 
        if (pid_t == 0){
            printf("Forked successfully");
            exit(EXIT_SUCCESS);
        }
     }
     


  } while (1);
  

    return 0;
}
