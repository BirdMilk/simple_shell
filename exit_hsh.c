#include "shell.h"

/**
 * exit_hsh - Exit the shell gracefully.
 *
 * Description:
 * This function prints a message indicating the shell is exiting
 * and then terminates the program with EXIT_SUCCESS. It is used
 * as the handler for the "exit" built-in command.
 */

void exit_hsh(void)
{
	print_stdout("exiting the shell.\n");
	exit(EXIT_SUCCESS);
}
