#include "shell.h"


/**
 * main - Entry point for the simple shell program.
 *
 * Description:
 * This function initializes a simple shell that continuously prompts
 * the user for commands. It then forks a child process to execute the
 * given command using execvp. The parent process waits for the child
 * to complete. The shell continues to run until manually terminated
 * by the user.
 *
 * Return:
 * The function returns 0 upon successful completion.
 */

int main(void)
{
	char command[150];

	while (true)
	{
		pid_t child_pid;

		_prompt();
		get_command(command, sizeof(command));
		if (strcmp(command, "exit\n") == 0)
		{
			exit_hsh();
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			print_stdout("Error in forking process.\n");
			exit(EXIT_FAILURE);
		} else if (child_pid == 0)
		{
			char *argument_string[128];
			int cnt = 0;

			char *token = strtok((char *)command, " ");

			while (token != NULL)
			{
				argument_string[cnt++] = token;
				token = strtok(NULL, " ");
			}
			argument_string[cnt] = NULL;
			execvp(argument_string[0], argument_string);
			print_stdout("Error in executing command.\n");
			exit(EXIT_FAILURE);
		} else
		{
			wait(NULL);
		}
	}
	return (0);
}
