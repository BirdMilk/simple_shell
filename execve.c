#include "shell.h"

/*
 *@pid_t wait(): The main fuction that carries the waiting process.
 *@int value = execve(argv[], argv, NULL): the value variable is daclared and initialized,
  using  array argv for the execution of the shell.
 *pid_t = fork() : It is the process id of the child.
 *Return : 0.
 */

int execve(const char *file_name, char *const argv[], char *const envp[])
{

  typedef pid_t pid_t;

  pid_t = fork();

  int value = execve(argv[], argv, NULL);
  argv[] = {"bin/ls", "-1", NULL};

  while (1)
  {
    if (fork == -1)
    {
      perror("Oops there's an error while focking");
      exit(EXIT_FAILURE);
    }
    else

        if (fock() == 0)
    {
      printf("Focked successfully", "/nPPID: %d\n", getpid());
      exit(EXIT_SUCCESS);
    }
  }

  if (value == -1)
  {
    perror("Ooops something went wrong ");
    exit(EXIT_FAILURE);
  }
}

int main(){

// Calling the execve function
execve (const char * file_name, char * const argv[], char * const envp[]);
return 0;

}
