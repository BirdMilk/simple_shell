#include "shell.h"

/*
 *@ssize_t getline() : Function that holds arguments and pointer variables to get the shell lines.
 *@typedef pid_t pid_t : It is the process id of the initial fork.
 *pid_t = fork() : It is the process id of the child.
 *stream = fopen(argv[1], "r") : logic used to open stream file using argv
 *Return : 0.
 */

ssize_t getline (char **restrict line, size_t *restrict x, FILE * restrict stream, int argc, char *argv[]){

 ssize_t read_line;
 size_t len = 0;

 typedef pid_t pid_t;

 pid_t = fork();

 while (1)
 {
    if (fork() == -1)
    {
        perror("Oops Error focking!!!");
        exit(EXIT_FAILURE);
    }else 
    if (fork() == 0)
    {
        printf("Focked successfully", "/nPPID: %d\n", getpid());   
        exit(EXIT_SUCCESS);
    }
    
    do
    {
        
        if (argc != 2)
        {
            printf(stderr, "Usage: %s /bin/ls\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        stream = fopen(argv[1], "r");
        if (stream == NULL)
        {
            perror("There's an error opening a file");
            exit(EXIT_FAILURE);
        }
        
      

       while ((read = getline(&line, &len, stream)) != -1)
       {
        printf("Line of length was retrieved successfully %zd:\n", read);
        fwrite(line, read, 1, stdout);
       }

       free(line);
       fclose(stream);
       exit(EXIT_SUCCESS);
       

    } while (1);
     
    
    
 }
 

}
/*
*main() : main function used to call the getline() function
*return: 0
*/
int main(){

    getline (char **restrict line, size_t *restrict x, FILE * restrict stream, int argc, char *argv[]);
    return 0;

}
