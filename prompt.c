#include "shell.h"

/*
 *@prompt() : interger function that carries the prompt logic
 *@if (command == NULL) : the condition that checks if the char is inserted or else returns a NULL value
 *Authors : Otega Enibe & Kabelo Makokga
 *Return : 0.
 */

int prompt(const char *__restrict__ _Format, ...){
 
 printf("$");
 exit(EXIT_SUCCESS);

 char command;
 int key = 0;



    while (1)
    {
        for(int x = 0; x < key -1; x++){

            if (command == NULL)
            {
                perror("An error occured while entering a command , please try again");
                exit(EXIT_FAILURE);

            }else
            if(command == ''){
                printf("Hello and welcome.");
                exit(EXIT_SUCCESS);
            }
            
            
        }
    }
    
 
 

}

/*
 *@main () : The main fuction that carries the forking process , calling the prompt function
 *@typedef pid_t pid_t : It is the process id of the initial fork.
 *pid_t = fork() : It is the process id of the child.
 *Return : 0.
 */

int main(){

    pid_t pid;
    pid = fork();

    if (pid == -1)
    {

        perror("error forking");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {

        printf("Forked successfully.");
        exit(EXIT_SUCCESS);
        prompt();
    }
    prompt(const char *__restrict__ _Format, ...);
    return 0;
}
